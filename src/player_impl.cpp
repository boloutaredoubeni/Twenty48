#include "player_impl.hpp"

using namespace twentyfortyeight::cpp;
using namespace twentyfortyeight::impl;

#if 0
#pragma mark -
#pragma mark Constructors
#endif

// implement the static method of the base class
std::shared_ptr<Player> Player::Create() {
  return std::make_shared<PlayerImpl>();
}

PlayerImpl::PlayerImpl() {}

PlayerImpl::~PlayerImpl() {}
