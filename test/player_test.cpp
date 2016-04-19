#include <gtest/gtest.h>

#include "player_impl.hpp"

#include <algorithm>

using namespace twentyfortyeight::cpp;

#if 0
#pragma mark -
#pragma mark New Game Tests
Verify how the program behaves when the player starts a new game
#endif
TEST(Player, ctor_dtor) { const auto player = Player::Create(); }

TEST(Player, new_game) {
  const auto player = Player::Create();
  player->NewGame();
  ASSERT_EQ(0, player->Score());
  ASSERT_FALSE(player->GameOver());
  ASSERT_FALSE(player->HasWon());
}

TEST(Player, can_notify_view_of_game_board) {
  const auto player = Player::Create();
  const auto board = player->GameState();
  ASSERT_EQ(16, board.size());
}

TEST(Player, new_game_adds_a_tile) {
  const auto player = Player::Create();
  const auto count_values = [](const std::vector<int>& xs) {
    const auto begin = xs.begin();
    const auto end = xs.end();
    return std::count_if(begin, end,
                         [](int i) { return (i > 0) && (i % 2) == 0; });
  };

  ASSERT_EQ(0, count_values(player->GameState()));
  player->NewGame();
  ASSERT_EQ(2, count_values(player->GameState()));
}

TEST(Player, can_move_tiles) {
  // TODO(boloutaredoubeni): assert that there are two tiles or that the
  // combined tiles is
  // TODO(boloutaredoubeni): assert that the score is changed
  //
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
