package com.boloutaredoubeni.twenty48.reactmodules;

import android.util.Log;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.boloutaredoubeni.twenty48.djinni.Player;

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
  public void startNewGame() {
    if (player == null) {
      player = Player.create();
    }
    player.newGame();
    Log.i(TAG, "The game has been created!!");
  }
}
