#include "player_impl.hpp"
#include "Twenty48/move.hpp"

#include <random>
#include <algorithm>

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

PlayerImpl::PlayerImpl() { game_ = std::make_shared<Game>(); }

PlayerImpl::~PlayerImpl() {}

#if 0
#pragma mark -
#pragma mark PublicMethods
#endif

void PlayerImpl::NewGame() {
  for (auto tile : game_->board_) {
    tile = 0;
  }

  assert(std::all_of(game_->board_.begin(), game_->board_.end(),
                     [](int i) { return i == 0; }));

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
  const auto game_board =
      std::vector<int32_t>(game_->board_.begin(), game_->board_.end());
  assert(game_board.size() == 16);
  return game_board;
}

bool PlayerImpl::GameOver() { return game_->is_over_; }

bool PlayerImpl::Swipe(Move move) {
  switch (move) {
    case Move::Up:
      return moveUp();
    case Move::Down:
      return moveDown();
    case Move::Left:
      return moveLeft();
    case Move::Right:
      return moveRight();
  }
  return true;
}

void PlayerImpl::addTile() const {
  bool is_new_game = std::all_of(game_->board_.begin(), game_->board_.end(),
                                 [](int i) { return i == 0; });
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<> rand_dist(dimension * dimension - 1);
  // Loop thru all tiles
  for (auto& tile : game_->board_) {
    // if it is 0 find an random empty one
    if (!tile) {
      if (rand_dist(generator) >= chance_of_four) {
        tile = 4;
      } else {
        tile = 2;
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
                       [](int i) { return i > 0; }));
  }
  game_->is_over_ = true;
}

bool PlayerImpl::hasMoves() const {
  const auto begin = game_->board_.begin();
  const auto end = game_->board_.end();
  return !std::all_of(begin, end, [](int i) { return i > 0; });
}

bool PlayerImpl::moveUp() const {
  addTile();
  return false;
}

bool PlayerImpl::moveDown() const {
  addTile();
  return false;
}

bool PlayerImpl::moveLeft() const {
  addTile();
  return false;
}

bool PlayerImpl::moveRight() const {
  addTile();
  return false;
}
