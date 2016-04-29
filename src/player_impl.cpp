#include "player_impl.hpp"
#include "Twenty48/move.hpp"

#include <algorithm>
#include <iterator>
#include <random>
#include <chrono>

#include <cassert>
#include <cstdio>

using namespace twenty48;
using namespace twenty48::impl;

#if 0
#pragma mark -
#pragma mark Helpers
#endif

namespace {
  auto is_valid(uint16_t val) -> decltype((val > 1) && !(val & (val -1))) {
    // NOTE: 1 is a power of two, but not tile == 1
    return (val > 1) && !(val & (val -1));
  }
}

#if 0
#pragma mark -
#pragma mark Constructors
#endif

// implement the static method of the base class
std::shared_ptr<Player> Player::Create() {
  return std::make_shared<PlayerImpl>();
}

PlayerImpl::PlayerImpl() { game_ = std::make_shared<Game>(); }

PlayerImpl::~PlayerImpl() {}

#if 0
#pragma mark -
#pragma mark Public Methods
#endif

void PlayerImpl::NewGame() {
  for (auto &tile : game_->board_) {
    tile.Init();
  }

  assert(std::all_of(game_->board_.begin(), game_->board_.end(),
                     [](const auto &i) { return !i.Value(); }));

  addTile();
  game_->score_ = 0;
  moves_made_ = 0;
}

int64_t PlayerImpl::Score() const {
  const auto score = game_->score_;
  assert(score >= 0);
  return score;
}

bool PlayerImpl::HasWon() const { return game_->has_won_; }

std::vector<int16_t> PlayerImpl::GameState() const {
  std::vector<int16_t> game_state(16);
  if (moves_made_ == -1) {
    return game_state;
  }
  std::transform(game_->board_.begin(), game_->board_.end(), game_state.begin(),
                 [](const auto &tile) { return tile.Value(); });
  assert(game_state.size() == 16);
  return game_state;
}

bool PlayerImpl::GameOver() const { return game_->is_over_; }

bool PlayerImpl::Swipe(Move move) {
  auto has_moved = false;
  if (moves_made_ == -1) {
    return has_moved;
  }
  switch (move) {
  case Move::Up:
    has_moved = moveUp();
    break;
  case Move::Down:
    has_moved = moveDown();
    break;
  case Move::Left:
    has_moved = moveLeft();
    break;
  case Move::Right:
    has_moved = moveRight();
    break;
  }

  if (has_moved) {
    ++moves_made_;
    addTile();
  }
  unlockTiles();
  assert(std::any_of(game_->board_.begin(), game_->board_.end(),
                     [](const auto &i) { return is_valid(i.Value()); }));
  return has_moved;
}

int64_t PlayerImpl::MovesMade() const { return moves_made_; }

void PlayerImpl::SetGame(
    const std::array<uint16_t, dimension * dimension> &game_board) {
  // check if all tiles are a power of 2
  if (std::any_of(game_board.begin(), game_board.end(),
                   [](int x) { return !((x > 1) && !(x & (x - 1))); })) {
    // #if defined (DEBUG) || (!NDEBUG)
    printf("Invalid\n");
    // #endif
    NewGame();
    return;
  }
  std::transform(game_board.begin(), game_board.end(), game_->board_.begin(),
                 [](const auto &val) { return Tile(val); });
  assert(std::equal(game_board.begin(), game_board.end(), game_->board_.begin(),
                    [](int i, const Tile &tile) { return i == tile.Value(); }));
}

#if 0
#pragma mark -
#pragma mark Private Methods
#endif

void PlayerImpl::addTile() const {
  bool is_new_game = std::all_of(game_->board_.begin(), game_->board_.end(),
                                 [](const auto i) { return !i.Value(); });

  // Loop thru all tiles
  for (auto &tile : game_->board_) {
    // if it is 1, find an random empty one
    if (!tile.Value()) {
      size_t idx;
      do {
        unsigned seed =
            std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine generator(seed);
        std::uniform_int_distribution<size_t> distribution(
            0, dimension * dimension - 1);
        idx = distribution(generator);
        assert(idx >= 0 && idx < dimension * dimension);
      } while (!game_->board_[idx].Value());

      // Assign the 'empty' tile a value
      unsigned seed =
          std::chrono::system_clock::now().time_since_epoch().count();
      std::default_random_engine generator(seed);
      std::uniform_real_distribution<double> distribution(0.0, 1.0);
      game_->board_[idx].Init((distribution(generator) >= 0.95) ? 4 : 2);
    }

    if (is_new_game) {
      is_new_game = false;
      // loop again add another tile
      continue;
    }

    assert(std::any_of(game_->board_.begin(), game_->board_.end(),
                       [](const auto& i) { return is_valid(i.Value()) ; }));
    if (hasMoves()) {
      return;
    }
  }

  game_->is_over_ = true;
}

bool PlayerImpl::hasMoves() const {
  const auto begin = game_->board_.begin();
  const auto end = game_->board_.end();
  return !std::all_of(begin, end, [](const auto &i) { return is_valid(i.Value()); });
}

bool PlayerImpl::moveUp() const {
  auto board_changed = false;
  // [*][*][*][4] __\\ [*][8][2][8]
  // [*][8][2][4] --// [*][*][*][*]
  // Check 12 - 15 with 8 - 11
  // merge if possible
  // then check 8 - 11 with 4 -7
  // merge
  // then check 0 - 3 with 4 - 7
  // remember that this is non-greedy thus [4][4][4][4] => [*][*][8][8]
  for (auto check_index = 8; check_index >= 0; check_index -= 4) {
    // get the a slice
    // merge into new row
    // if merged row equals top row and bottom is not empty board has not
    // changed
    for (auto start = game_->board_.begin() + check_index,
              end = game_->board_.begin() + check_index + 4;
         start != end; ++start) {
      auto next = end + 1;
      assert(next != nullptr);
      if ((*start).Value() != (*next).Value()) {
        printf("start: %d, next: %d\n", (*start).Value(), (*next).Value());
        continue;
      }
      if ((*start).Locked() || (*next).Locked()) {
        printf("start: %d, next: %d\n", (*start).Value(), (*next).Value());
        continue;
      }
      if ((*start).Value() == 1) {
        printf("start: %d, next: %d\n", (*start).Value(), (*next).Value());
        continue;
      }
      (*next).Init();
      (*start).Increase();
      game_->score_ += (*start).Value();
      board_changed = true;
    }
  }
  return board_changed;
}

bool PlayerImpl::moveDown() const { return false; }

bool PlayerImpl::moveLeft() const { return false; }

bool PlayerImpl::moveRight() const { return false; }

void PlayerImpl::unlockTiles() const {
  for (auto &tile : game_->board_) {
    tile.Unlock();
  }
}
