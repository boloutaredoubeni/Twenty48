/**
  * (c) Boloutare Doubeni 2016
  * @flow
  */

'use strict';

// clang-format off
import React, {
  Component,
  StyleSheet,
  Text,
  View,
  TouchableOpacity,
  NativeModules
} from 'react-native';
// clang-format on

export default class InfoScreen extends Component {

  constructor(props) {
    super(props);
    // this.subscription = NativeEventEmitter.addListener('ScoreChange', (score)
    // => console.log(score));
    this.state = {};
  }

  render() {
    // clang-format off
    return (
      <View>
        <Text>About 2048</Text>
      </View>
    );
    // clang-format on
  }
}
