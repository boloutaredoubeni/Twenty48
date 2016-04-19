#include <gtest/gtest.h>

#include "player_impl.hpp"

using namespace twentyfortyeight::cpp;
// using namespace twentyfortyeight::impl;

TEST(Player, ctor_dtor) { auto player = Player::Create(); }
