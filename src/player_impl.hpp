#pragma once

#include "player.hpp"
#include "game.hpp"

#include <cassert>

namespace twentyfortyeight {
namespace impl {

class PlayerImpl : public cpp::Player {
  std::shared_ptr<Game> game_;

 public:
#if 0
#pragma mark -
#pragma mark Constructors
#endif

  PlayerImpl();
  ~PlayerImpl();
  PlayerImpl(PlayerImpl &&) = default;
  PlayerImpl(const PlayerImpl &) = default;
  PlayerImpl &operator=(PlayerImpl &&) = default;
  PlayerImpl &operator=(const PlayerImpl &) = default;

#if 0
#pragma mark -
#pragma mark PublicMethods
#endif

  void NewGame();
  int64_t Score();
  bool HasWon();
  std::vector<int32_t> GameState();
  bool GameOver();

 private:
  void addTile() const;
};

}  // namespace impl
}  // namespace twentyfortyeight
