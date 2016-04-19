#include <gtest/gtest.h>

#include "player_impl.hpp"

#include <algorithm>

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
  ASSERT_EQ(1, count_values(player->GameState()));
}
