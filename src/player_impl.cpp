#include "player_impl.hpp"

using namespace twentyfortyeight::cpp;
using namespace twentyfortyeight::impl;

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

void PlayerImpl::addTile() const {
  for (const auto tile : game_->board_) {
    if (!tile) {
    }
  }
}
