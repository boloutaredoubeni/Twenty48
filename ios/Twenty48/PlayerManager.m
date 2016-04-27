/**
 * (c) Boloutare Doubeni 2016
 */
#include "PlayerManager.h"
#include "T48Player.h"

#import "RCTEventDispatcher.h"
#import "RCTLog.h"

@implementation PlayerManager {
  T48Player *_player;
}

@synthesize bridge = _bridge;

RCT_EXPORT_MODULE()

#if 0
#pragma mark -
#pragma mark Export Methods
#endif

RCT_EXPORT_METHOD(newGame) {
  if (!_player) {
    _player = [T48Player create];
  }
  [_player newGame];
  RCTLogInfo(@"Starting a new game");
}

RCT_EXPORT_METHOD(swipe : (T48Move)direction) {
  if (!_player) {
    RCTLogError(@"Attempting to move tiles for a uninitialized game");
    return;
  }
  [_player swipe:direction];
}

#if 0
#pragma mark -
#pragma mark Event Listeners
#endif

@end
