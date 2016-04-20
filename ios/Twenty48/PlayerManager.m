#include "PlayerManager.h"
#include "TFEPlayer.h"

#import "RCTLog.h"

@implementation PlayerManager {
  TFEPlayer *_player;
}

RCT_EXPORT_MODULE()

RCT_EXPORT_METHOD(startNewGame) {
  if (!_player) {
    _player = [TFEPlayer create];
  }
  [_player newGame];
  RCTLogInfo(@"Starting a new game");
}
@end
