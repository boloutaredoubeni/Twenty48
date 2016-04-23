#include <gtest/gtest.h>

#include "Twenty48/Move.hpp"
#include "player_impl.hpp"

#include <algorithm>

using namespace twenty48;

namespace {
static bool verify_tiles_moved_up(const std::vector<int> &prev,
                                  const std::vector<int> &next) {
  std::vector<int> top_row_prev(prev.begin(), prev.begin() + 3);
  std::vector<int> top_row_next(next.begin(), prev.begin() + 3);
  return top_row_prev != top_row_next;
}
} // namespace

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
  ASSERT_EQ(0, player->MovesMade());
}

TEST(Player, can_notify_view_of_game_board) {
  const auto player = Player::Create();
  const auto board = player->GameState();
  ASSERT_EQ(16, board.size());
}

TEST(Player, new_game_adds_a_tile) {
  const auto player = Player::Create();
  const auto count_values = [](const std::vector<int> &xs) {
    const auto begin = xs.begin();
    const auto end = xs.end();
    return std::count_if(begin, end,
                         [](int i) { return (i > 1) && (i % 2) == 0; });
  };

  ASSERT_EQ(0, count_values(player->GameState()));
  player->NewGame();
  ASSERT_EQ(2, count_values(player->GameState()));
}

// NOTE: these tests fail when its not the first move in the game
TEST(Player, can_move_up) {
  const auto player = Player::Create();
  ASSERT_GE(0, player->MovesMade());
  const auto prev = player->GameState();
  ASSERT_TRUE(player->Swipe(Move::Up));
  // ASSERT_EQ(1, player->MovesMade());
  // ASSERT_GE(0, player->Score());
  // ASSERT_TRUE(verify_tiles_moved_up(prev, player->GameState()));
}

TEST(Player, can_move_tiles) {
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
