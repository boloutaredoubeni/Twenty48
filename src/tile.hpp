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
#pragma mark Public Methods
#endif
  virtual void Init();

  virtual void Init(uint8_t);
  virtual void Increase();
  virtual int8_t Value() const;
  virtual void Unlock();
  virtual bool Locked() const;
};
} // namespace impl
} // namespace twenty48
