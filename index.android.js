/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 */

import React, {AppRegistry, Component, StyleSheet, Text, View, NativeModules} from 'react-native';

import AppStyleSheet from './app/styles';

class Twenty48 extends Component {
  render() {
    return (
      <View style={styles.container}>
        <Text style={styles.welcome}>
          Welcome to React Native!
        </Text>
        <Text style={styles.instructions}>
          To get started, edit index.android.js
        </Text>
        <Text style={styles.instructions}>
          Shake or press menu button for dev menu
        </Text>
      </View>
    );
  }
}

const player = NativeModules.PlayerManager;
console.dir(player);
player.startNewGame();

AppRegistry.registerComponent('Twenty48', () => Twenty48);
