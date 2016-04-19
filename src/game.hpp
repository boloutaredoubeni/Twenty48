#pragma once

#include <array>

#include <cstdint>

namespace twentyfortyeight {
namespace impl {

const static uint8_t dimension = 4;

using GameBoard = std::array<uint32_t, dimension * dimension>;

class Game final {
  uint64_t score_{0};
  bool has_won_ = false;
  const GameBoard board_{};  // NOTE: all members are zero
  friend class PlayerImpl;

 public:
  Game();
  ~Game();
  Game(Game &&) = default;
  Game(const Game &) = default;
  Game &operator=(Game &&) = default;
  Game &operator=(const Game &) = default;
};
}  // namespace twentyfortyeight
}  // namespace impl
