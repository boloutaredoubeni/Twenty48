#pragma once
/**
 * This file includes a prototype representing the ui of the game
 */
#include <array>

namespace twentyfortyeight {
namespace testing {

class ActivityController;

using GameBoard = std::array<std::array<uint16_t, 4>, 4>;

class GameUI {
  uint16_t score_text = 0;
  GameBoard board;
  uint16_t hi_score_text = 0;
  uint16_t times_played = 0;

  friend class ActivityController;
};
}  // namespace testing
}  // namespace twentyfortyeight
