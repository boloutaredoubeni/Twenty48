#include "tile.hpp"

#include <random>
#include <chrono>

#include <cassert>


using namespace twenty48::impl;

Tile::Tile() {}
Tile::Tile(int32_t value) : value_(value) {}

void Tile::Reset() {
    locked_ = false;
    value_ = 0;
}

void Tile::Increase() {
  if (locked_) {
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

void Tile::Init() {
    unsigned seed =
    std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
  Unlock();
  value_ = (distribution(generator) >= 0.95) ? 4 : 2;
}

bool Tile::Locked() const { return locked_; }
