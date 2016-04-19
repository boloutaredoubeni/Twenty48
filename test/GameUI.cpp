#include "GameUI.hpp"

using namespace twentyfortyeight::testing;

// Contructors, Destructors
GameUI::GameUI() {}

GameUI::~GameUI() {}

// private methods
GameUI& GameUI::Instance() {
  static GameUI instance;
  return instance;
}
