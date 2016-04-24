#pragma once

#include <cstdint>

namespace twenty48 {
namespace impl {
struct Tile {
#if 0
#pragma mark -
#pragma mark Members
#endif
  bool locked_{false};
  int32_t value_{1};

#if 0
#pragma mark -
#pragma mark Constructors
#endif
  Tile();
  explicit Tile(int32_t);
  ~Tile() {}
  Tile(Tile &&) = default;
  Tile(const Tile &) = default;
  Tile &operator=(Tile &&) = default;
  Tile &operator=(const Tile &) = default;
};
} // namespace impl
} // namespace twenty48
