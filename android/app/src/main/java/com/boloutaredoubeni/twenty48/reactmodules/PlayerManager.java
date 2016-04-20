package com.boloutaredoubeni.twenty48.reactmodules;

import android.util.Log;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;

/**
 * Copyright 2016 Boloutare Doubeni
 */
public class PlayerManager extends ReactContextBaseJavaModule {

  private final static String  TAG = "PlayerManager";

  static {
    try {
      System.load("2048_jni");
    } catch (UnsatifiedLinkError e) {
      Log.e(TAG, "The library was not loaded");
      System.exit(1);
    }
  }
  
  com.boloutaredoubeni.twentyfortyeight.djinni.Player player;
  
  public PlayerManager(ReactApplicationContext context) {
    super(context);
  }
  
  @Override
  public String getName() {
    return "Player";
  }
  
  @ReactMethod
  public void startNewGame() {
    if (player == null) {
      player = com.boloutaredoubeni.twentyfortyeight.djinni.Player.create();
    }
    player.startNewGame();
  }
}
