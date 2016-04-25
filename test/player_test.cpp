#include <gtest/gtest.h>

#include "Twenty48/Move.hpp"
#include "player_impl.hpp"

#include <algorithm>

using namespace twenty48;
using namespace twenty48::impl;
using namespace ::testing;

#if 0
#pragma mark -
#pragma mark Player Fixture
#endif

namespace {
class PlayerTest : public Test {
protected:
  std::shared_ptr<Player> player_;

  PlayerTest() { player_ = Player::Create(); }

  virtual void SetUp() override {
    player_->NewGame();
    ASSERT_EQ(0, player_->Score());
    ASSERT_FALSE(player_->GameOver());
    ASSERT_FALSE(player_->HasWon());
    ASSERT_EQ(0, player_->MovesMade());
    ASSERT_EQ(2, TileCount());
  }

  virtual int16_t TileCount() const {
    const auto game_state = player_->GameState();
    return std::count_if(game_state.begin(), game_state.end(),
                         [](int i) { return (i > 1) && ((i % 2) == 0); });
  }

  virtual void
  SetGameBoard(const std::array<uint16_t, dimension * dimension> &state) {
    std::static_pointer_cast<PlayerImpl>(player_)->SetGame(state);
  }
};
} // namespace

TEST_F(PlayerTest, can_use_set_game) {
  SetGameBoard(std::array<uint16_t, dimension * dimension>{});
}

TEST_F(PlayerTest, cant_set_game_to_invalid_state) {
  SetGameBoard(std::array<uint16_t, dimension * dimension>{});
  ASSERT_EQ(0, player_->MovesMade());
  ASSERT_EQ(2, TileCount());
}

TEST_F(PlayerTest, can_notify_view_of_game_board) {
  const auto board = player_->GameState();
  ASSERT_EQ(16, board.size());
}

TEST_F(PlayerTest, new_game_adds_tiles) { ASSERT_EQ(2, TileCount()); }

TEST_F(PlayerTest, can_move_up) {
  ASSERT_GE(0, player_->MovesMade());
  const auto prev = player_->GameState();
  ASSERT_FALSE(player_->Swipe(Move::Up));
  ASSERT_GE(0, player_->MovesMade());
  // FIXME: this result is intended to be random. Create a fixture to normalize
  // behaviour
  ASSERT_TRUE(player_->Swipe(Move::Up));
  ASSERT_EQ(1, player_->MovesMade());
  ASSERT_GE(0, player_->Score());
}

TEST_F(PlayerTest, can_move_tiles) {
  // TODO(boloutaredoubeni): assert that there are two tiles or that the
  // combined tiles is
  // TODO(boloutaredoubeni): assert that the score is changed
  // TODO(boloutaredoubeni): all tile are as far as they can possible be in the
  // direction they were swiped
  // TODO(boloutaredoubeni): if two consecutive tiles are matches they are
  // combined
  // TODO(boloutaredoubeni): after a move is finished and addTile() is called is
  // should notify is available moves are possible
}

#if 0
#pragma mark -
#pragma mark In Game Tests
Progress through the game for a couple of steps then verify behavoir
#endif

#if 0
#pragma mark -
#pragma mark End Game
Verify how the program behaves at the end of the game
#endif
