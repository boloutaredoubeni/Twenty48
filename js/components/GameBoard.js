/**
 * @flow
 */
'use strict';

// clang-format off
import React, { View, Component, StyleSheet } from 'react-native';
// clang-format on

class Cell extends Component {
  render() {
    return (
      // clang-format off
      <View />
      // clang-format on
    );
  }
}

class Tile extends Component {
  render() {
    return (
      // clang-format off
      <Text/>
      // clang-format on
    );
  }
}

export default class GameBoard extends Component {
  render() {
    return (
      // clang-format off
      /* TODO init with tiles */
      <View>
        <View></View>
        <View></View>
        <View></View>
        <View></View>
      </View>
      // clang-format on
    );
  }
}
