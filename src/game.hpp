#pragma once

#include "tile.hpp"

#include <algorithm>
#include <array>

#include <cstdint>

namespace twenty48 {
namespace impl {

const static uint8_t dimension = 4;
const static uint8_t chance_of_four = 15;

using GameBoard = std::array<std::shared_ptr<Tile>, dimension * dimension>;

class Game final {
  uint64_t score_{0};
  bool has_won_ = false;
  bool is_over_ = false;
  GameBoard board_{};
  friend class PlayerImpl;

 public:
#if 0
#pragma mark -
#pragma mark Constructors
#endif
  Game();
  ~Game();
  Game(Game &&) = default;
  Game(const Game &) = default;
  Game &operator=(Game &&) = default;
  Game &operator=(const Game &) = default;
};
}  // namespace twentyfortyeight
}  // namespace impl
