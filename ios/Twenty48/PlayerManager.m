#include "PlayerManager.h"
#include "T48Player.h"

#import "RCTLog.h"

@implementation PlayerManager {
  T48Player *_player;
}

RCT_EXPORT_MODULE()

RCT_EXPORT_METHOD(startNewGame) {
  if (!_player) {
    _player = [T48Player create];
  }
  [_player newGame];
  RCTLogInfo(@"Starting a new game");
}
@end
