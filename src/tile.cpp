#include "tile.hpp"

#include <cassert>

using namespace twenty48::impl;

Tile::Tile() {}
Tile::Tile(int32_t value) : value_(value) {}

void Tile::Increase() {
  if (locked_ || value_ < 2) {
    return;
  }
  if (value_ == 0) {
    value_ = 2;
    return;
  }
  value_ <<= 1;
  locked_ = true;
}

void Tile::Unlock() { locked_ = false; }

int8_t Tile::Value() const { return value_; }

void Tile::Init() { Init(0); }

void Tile::Init(uint8_t value) {
  if ((value == 3) || (value > 4) || (value == 1)) {
    return;
  }
  Unlock();
  value_ = value;
}

bool Tile::Locked() const { return locked_; }
