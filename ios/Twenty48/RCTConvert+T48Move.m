//
//  RCTConvert+T48Move.m
//  Twenty48
//
//  Created by Boloutare Doubeni on 4/27/16.
//  Copyright © 2016 Facebook. All rights reserved.
//

#include "RCTConvert+T48Move.h"
#include "T48Move+Constants.h"

@implementation RCTConvert (T48Move)

RCT_ENUM_CONVERTER(T48Move, (@{
                     MOVE_UP : @(T48MoveUp),
                     MOVE_DOWN : @(T48MoveDown),
                     MOVE_LEFT : @(T48MoveLeft),
                     MOVE_RIGHT : @(T48MoveRight)
                   }),
                   T48MoveUp, integerValue);

@end