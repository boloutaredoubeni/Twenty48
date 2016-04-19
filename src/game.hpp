#pragma once

#include <cstdint>

namespace twentyfortyeight {
namespace impl {

class Game final {
  uint64_t score_;
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
