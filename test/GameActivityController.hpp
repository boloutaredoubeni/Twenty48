#pragma once

#include "GameUI.hpp"
#include "Player.hpp"

#include <memory>

namespace twentyfortyeight {
namespace testing {

using namespace twentyfortyeight::cpp;

/// Subclasses will interact with the game ui
class GameActivityController {
  const std::unique_ptr<Player> player_;
  const std::unique_ptr<GameChangeListener> listener_;

 public:
  /// An analogue to UIViewController:viewDidLoad and Activty.onCreate()
  GameActivityController();

  /// An analogue to UIViewController.viewWillDisappear and Activity.onDestroy()
  ~GameActivityController(){};

 private:
  static void ClearGameBoard();

  // FIXME(boloutaredoubeni): add methods corresponding to gameui
};
}  // namespace testing
}  // namespace twentyfortyeight
