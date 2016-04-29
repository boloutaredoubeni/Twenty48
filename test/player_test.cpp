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

auto convert_vec_to_array(const std::vector<int16_t> &v)
    -> std::array<uint16_t, dimension * dimension> {
  std::array<uint16_t, dimension * dimension> out{};
  if (v.size() != 16) {
    return out;
  }
  std::copy(v.begin(), v.end(), out.begin());
  return out;
}
} // namespace

TEST_F(PlayerTest, can_use_set_game) {
  const auto new_state = std::array<uint16_t, dimension * dimension>{};
  SetGameBoard(new_state);
  player_->NewGame();
  const auto new_game = convert_vec_to_array(player_->GameState());
  const auto end_state = convert_vec_to_array(player_->GameState());
  ASSERT_NE(end_state, new_state);
  ASSERT_NE(new_game, new_state);
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
  {
    SetGameBoard(std::array<uint16_t, dimension * dimension>{
        {4, 1, 1, 1, 4, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1}});
    ASSERT_TRUE(player_->Swipe(Move::Up));
    std::vector<int16_t> end_state{
        {4, 1, 1, 1, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    ASSERT_EQ(end_state, player_->GameState());

    ASSERT_EQ(8, player_->Score());
    ASSERT_GT(0, player_->MovesMade());
    ASSERT_FALSE(player_->GameOver());
    ASSERT_FALSE(player_->HasWon());
  }
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
