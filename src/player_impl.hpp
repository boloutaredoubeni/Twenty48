#pragma once

#include "player.hpp"

namespace twentyfortyeight {
namespace impl {

class PlayerImpl : public cpp::Player {
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
};

}  // namespace impl
}  // namespace twentyfortyeight
