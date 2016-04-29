#pragma once

#include "Twenty48/player.hpp"
#include "game.hpp"

namespace twenty48 {
namespace impl {

class PlayerImpl final : public twenty48::Player {
  std::shared_ptr<Game> game_;
  int64_t moves_made_{-1};

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

  virtual void NewGame();
  virtual int64_t Score() const;
  virtual bool HasWon() const;
  virtual std::vector<int16_t> GameState() const;
  virtual bool GameOver() const;
  virtual bool Swipe(twenty48::Move);
  virtual int64_t MovesMade() const;
  virtual void SetGame(const std::array<uint16_t, dimension * dimension> &);

private:
#if 0
#pragma mark -
#pragma mark Private Methods
#endif
  virtual void addTile() const;
  virtual bool hasMoves() const;
  virtual bool moveUp() const;
  virtual bool moveDown() const;
  virtual bool moveLeft() const;
  virtual bool moveRight() const;
  virtual void unlockTiles() const;
};

} // namespace impl
} // namespace twentyfortyeight
