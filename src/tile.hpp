#pragma once

#include <cstdint>

namespace twenty48 {
namespace impl {
class Tile {
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
public:
  Tile();
  explicit Tile(int32_t);
  ~Tile() {}
  Tile(Tile &&) = default;
  Tile(const Tile &) = default;
  Tile &operator=(Tile &&) = default;
  Tile &operator=(const Tile &) = default;

#if 0
#pragma mark -
#pragma mark Public Method
#endif
  virtual void Init();
  virtual void Increase();
  virtual int8_t Value() const;
  virtual void Unlock();
  virtual void Combine(Tile &tile);
};
} // namespace impl
} // namespace twenty48
