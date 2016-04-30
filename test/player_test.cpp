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
                         [](int x) { return ((x > 1) && !(x & (x - 1))); });
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
  SetGameBoard(std::array<uint16_t, dimension * dimension>{
      {/* row 1 */ 0, 1, 2, 3, /* row 2 */ 4, 5, 6, 7, /* row 3*/ 8, 9, 1, 2,
       /* row 4 */ 3, 4, 5, 6}});
  ASSERT_EQ(2, TileCount());
}

TEST_F(PlayerTest, new_game_adds_tiles) { ASSERT_EQ(2, TileCount()); }

TEST_F(PlayerTest, can_move_up_veritically) {

  const auto set_state = std::array<uint16_t, dimension * dimension>{
      {/* row 1*/ 4, 0, 0, 0, /* row 2 */ 4, 0, 0, 0, /* row 2 */ 4, 0, 0, 0,
       /* row 4 */ 0, 0, 0, 0}};
  SetGameBoard(set_state);
  ASSERT_EQ(set_state, convert_vec_to_array(player_->GameState()));
  ASSERT_TRUE(player_->Swipe(Move::Up));
  const auto first = player_->GameState().at(0);
  const auto second = player_->GameState().at(4);
  ASSERT_EQ(first, 4);
  ASSERT_EQ(second, 8);
  ASSERT_EQ(8, player_->Score());
  ASSERT_GT(player_->MovesMade(), 0);
  //    ASSERT_EQ(3, TileCount());
  ASSERT_FALSE(player_->GameOver());
  ASSERT_FALSE(player_->HasWon());
}

TEST_F(PlayerTest, moving_up_doesnt_change_top) {
  const auto set_state = std::array<uint16_t, dimension * dimension>{
      {/* row 1*/ 4, 4, 4, 4, /* row 2 */ 0, 0, 0, 0, /* row 2 */ 0, 0, 0, 0,
       /* row 4 */ 0, 0, 0, 0}};
  SetGameBoard(set_state);
  ASSERT_EQ(set_state, convert_vec_to_array(player_->GameState()));
  ASSERT_FALSE(player_->Swipe(Move::Up));
  const auto top_is_four = std::count(player_->GameState().begin(),
                                      player_->GameState().begin() + 3, 4);
  ASSERT_TRUE(top_is_four);
  ASSERT_EQ(4, TileCount());
  ASSERT_EQ(0, player_->Score());
  ASSERT_EQ(player_->MovesMade(), 0);
  ASSERT_FALSE(player_->GameOver());
  ASSERT_FALSE(player_->HasWon());
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
