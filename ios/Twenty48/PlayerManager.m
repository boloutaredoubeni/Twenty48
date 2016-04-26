#include "PlayerManager.h"
#include "T48Player.h"

#import "RCTEventDispatcher.h"
#import "RCTLog.h"

@implementation PlayerManager {
  T48Player *_player;
}

@synthesize bridge = _bridge;

RCT_EXPORT_MODULE()

RCT_EXPORT_METHOD(newGame) {
  if (!_player) {
    _player = [T48Player create];
  }
  [_player newGame];
  RCTLogInfo(@"Starting a new game");
}

- (void)scoreChangedEvent:(NSNotification *)notification {
  NSString *eventName = notification.userInfo[@"name"];
  [self.bridge.eventDispatcher sendAppEventWithName:@"ScoreChange"
                                               body:@{
                                                 @"name" : eventName
                                               }];
}

@end
