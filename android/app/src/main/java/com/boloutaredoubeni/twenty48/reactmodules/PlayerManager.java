package com.boloutaredoubeni.twenty48.reactmodules;

import android.util.Log;

import com.facebook.react.bridge.Arguments;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.boloutaredoubeni.twenty48.djinni.Player;
import com.boloutaredoubeni.twenty48.djinni.Move;
import com.facebook.react.bridge.WritableArray;
import com.facebook.react.bridge.WritableMap;
import com.facebook.react.modules.core.DeviceEventManagerModule;
import com.facebook.react.modules.core.RCTNativeAppEventEmitter;

import java.util.Map;
import java.util.HashMap;

import javax.annotation.Nullable;

/**
 * Copyright 2016 Boloutare Doubeni
 */
public class PlayerManager extends ReactContextBaseJavaModule {

  private final static String TAG = "PlayerManager";

  static {
    try {
      System.loadLibrary("2048_jni");
    } catch (UnsatisfiedLinkError e) {
      Log.e(TAG, "The library was not loaded");
      System.exit(1);
    }
  }

  Player player;

  public PlayerManager(ReactApplicationContext context) { super(context); }

  @Override
  public String getName() {
    return "PlayerManager";
  }

  @ReactMethod
  public void newGame() {
    if (player == null) {
      player = Player.create();
    }
    player.newGame();
    Log.i(TAG, "The game has been created!!");
  }

  @ReactMethod
  public void swipe(int direction) {
    if (player == null) {
      Log.e(TAG, "The player attempted to swipe on an uninitialized board");
      return;
    }
    final Move move = convertToMove(direction);
    if (move == null) {
      return;
    }
    player.swipe(move);
    notifyGameChanged(getReactApplicationContext(), "ScoreChanged",
                      getGameStateParams());
  }

  @Nullable
  @Override
  public Map<String, Object> getConstants() {
    final Map<String, Object> constants = new HashMap<>();
    constants.put("MoveUp", 0);
    constants.put("MoveDown", 1);
    constants.put("MoveLeft", 2);
    constants.put("MoveRight", 3);
    return constants;
  }

  private Move convertToMove(int direction) {
    if (direction < 0 || direction > 3) {
      Log.e(TAG, "Invalid direction");
      return null;
    }
    switch (direction) {
    case 0:
      return Move.UP;
    case 1:
      return Move.DOWN;
    case 2:
      return Move.LEFT;
    case 3:
      return Move.RIGHT;
    default:
      return null;
    }
  }

  private void notifyGameChanged(ReactContext reactContext, String eventName,
                                 @Nullable WritableMap params) {
    reactContext.getJSModule(RCTNativeAppEventEmitter.class)
        .emit(eventName, params);
  }

  private WritableMap getGameStateParams() {
    final WritableMap params = Arguments.createMap();
    final WritableArray gameBoard = Arguments.createArray();
    for (final int tile : player.gameState()) {
      gameBoard.pushInt(tile);
    }
    params.putDouble("score", (double)player.score());
    params.putBoolean("gameOver", player.gameOver());
    params.putBoolean("hasWon", player.hasWon());
    params.putDouble("movesMade", (double)player.movesMade());
    params.putArray("gameBoard", gameBoard);
    return params;
  }
}
