#include "game.hpp"

using namespace twenty48;
using namespace twenty48::impl;

Game::Game() {
  for (auto i = 0; i < 8; ++i) {
    board_[i] = Tile();
  }
};
Game::~Game(){};
