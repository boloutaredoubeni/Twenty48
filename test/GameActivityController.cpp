#include "GameActivityController.hpp"

using namespace twentyfortyeight::testing;

// Constructors, Destructors, Assign
GameActivityController::GameActivityController() {
  player_ = Player::create(listener_);
}

GameActivityController::~GameActivityController() {
  std::shared_ptr<GameUI> game_ui = GameUI::Instance();
  game_ui->score_text = 0;
  ++game_ui->times_played_;
  ClearGameBoard();
  delete listener_;
  delete player_;
}

// private static methods
GameActivityController::ClearGameBoard() {
  std::shared_ptr<GameUI> game_ui = GameUI::Instance();
  for (auto tile : game_ui->board_) {
    tile = 0;
  }
}
