#pragma once

#include "Twenty48/player.hpp"
#include "game.hpp"

namespace twenty48 {
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
#pragma mark Public Methods
#endif

  void NewGame();
  int64_t Score();
  bool HasWon();
  std::vector<int32_t> GameState();
  bool GameOver();
  bool Swipe(cpp::Move);

 private:
#if 0
#pragma mark -
#pragma mark Private Methods
#endif
  void addTile() const;
  bool hasMoves() const;
  bool moveUp() const;
  bool moveDown() const;
  bool moveLeft() const;
  bool moveRight() const;
};

}  // namespace impl
}  // namespace twentyfortyeight
