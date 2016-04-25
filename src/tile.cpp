#include "tile.hpp"

#include <cassert>

using namespace twenty48::impl;

Tile::Tile() {}
Tile::Tile(int32_t value) : value_(value) {}

void Tile::Increase() {
  if (locked_)
    return;
  value_ <<= 1;
  locked_ = true;
}

void Tile::Unlock() { locked_ = false; }

int8_t Tile::Value() const { return value_; }

void Tile::Init() { value_ = 1; }

bool Tile::Locked() const { return locked_; }
