#include <gtest/gtest.h>

#include "player_impl.hpp"

using namespace twentyfortyeight::cpp;
// using namespace twentyfortyeight::impl;

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
