#include "player_impl.hpp"
#include "Twenty48/move.hpp"

#include <algorithm>
#include <random>

#include <cassert>

using namespace twenty48;
using namespace twenty48::impl;

#if 0
#pragma mark -
#pragma mark Constructors
#endif

// implement the static method of the base class
std::shared_ptr<Player> Player::Create() {
  return std::make_shared<PlayerImpl>();
}

PlayerImpl::PlayerImpl() {
  game_ = std::make_shared<Game>();
  std::for_each(game_->board_.begin(), game_->board_.end(),
                [](auto &tile) {
                  tile = Tile();
                });
  assert(std::all_of(game_->board_.begin(), game_->board_.end(),
                     [](const auto &i) { return i.value_ == 1; }));
}

PlayerImpl::~PlayerImpl() {}

#if 0
#pragma mark -
#pragma mark PublicMethods
#endif

void PlayerImpl::NewGame() {
  for (auto &tile : game_->board_) {
    tile.value_ = 1;
  }

  assert(std::all_of(game_->board_.begin(), game_->board_.end(),
                     [](const auto &i) { return i.value_ == 1; }));

  addTile();
  game_->score_ = 0;
}

int64_t PlayerImpl::Score() {
  const auto score = game_->score_;
  assert(score >= 0);
  return score;
}

bool PlayerImpl::HasWon() { return game_->has_won_; }

std::vector<int32_t> PlayerImpl::GameState() {
  std::vector<int32_t> game_state(16);
  std::transform(game_->board_.begin(), game_->board_.end(), game_state.begin(),
                 [](const auto& tile) {
                   return tile.value_;
                 });
  assert(game_state.size() == 16);
  return game_state;
}

bool PlayerImpl::GameOver() { return game_->is_over_; }

bool PlayerImpl::Swipe(Move move) {
  auto has_moved = false;
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
    addTile();
  }
  unlockTiles();
  return has_moved;
}

int64_t PlayerImpl::MovesMade() { return moves_made_; }

#if 0
#pragma mark -
#pragma mark Private Methods
#endif

void PlayerImpl::addTile() const {
  bool is_new_game = std::all_of(game_->board_.begin(), game_->board_.end(),
                                 [](const auto i) { return i.value_ == 1; });
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<> rand_dist(dimension * dimension - 1);
  // Loop thru all tiles
  for (auto &tile : game_->board_) {
    // if it is 0 find an random empty one
    if (tile.value_ == 1) {
      if (rand_dist(generator) >= chance_of_four) {
        tile.value_ = 4;
      } else {
        tile.value_ = 2;
      }
      // FIXME(boloutaredoubeni): select a random tile instead of the first one
      // that is found
    }

    if (is_new_game) {
      is_new_game = false;
      // loop again add another tile
      continue;
    }

    if (hasMoves()) {
      return;
    }

    assert(std::any_of(game_->board_.begin(), game_->board_.end(),
                       [](const auto i) { return i.value_ > 0; }));
  }
  game_->is_over_ = true;
}

bool PlayerImpl::hasMoves() const {
  const auto begin = game_->board_.begin();
  const auto end = game_->board_.end();
  return !std::all_of(begin, end, [](const auto i) { return i.value_ > 1; });
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
  // remember that this is non-greedy
  auto check_index = 12;
  do {
    // get the a row
    // get the adjacent row
    // merge into new row
    // if merged row equals top row and bottom is not empty board has not
    // changed
    check_index -= 4;
  } while (check_index < 0);
  return board_changed;
}

bool PlayerImpl::moveDown() const { return false; }

bool PlayerImpl::moveLeft() const { return false; }

bool PlayerImpl::moveRight() const { return false; }

void PlayerImpl::unlockTiles() const {}
