package com.boloutaredoubeni.twenty48.reactmodules;

import android.util.Log;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.boloutaredoubeni.twenty48.djinni.Player;
import com.boloutaredoubeni.twenty48.djinni.Move;

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
}
