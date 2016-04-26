/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 * @flow
 */

import React, {AppRegistry, Component, Text, View, NativeModules,} from 'react-native';

import AppStyleSheet from './app/styles';

class Twenty48 extends Component {
  render() {
    return (
      <View style={AppStyleSheet.container}>
        <Text style={AppStyleSheet.welcome}>
          Welcome to React Native!
        </Text>
        <Text style={AppStyleSheet.instructions}>
          To get started, edit index.ios.js
        </Text>
        <Text style={AppStyleSheet.instructions}>
          Press Cmd+R to reload,{
      '\n'}
          Cmd+D or shake for dev menu
        </Text>
      </View>
    );
  }
}


const PlayerManager = NativeModules.PlayerManager;
PlayerManager.startNewGame();

AppRegistry.registerComponent('Twenty48', () => Twenty48);
