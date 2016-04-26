import React, {Component,  Text, View, NativeModules, NativeEventEmitter} from 'react-native';
import AppStyleSheet from './styles';

class Twenty48 extends Component {
  
  constructor() {
    super();
    this.subscription = NativeEventEmitter.addListener('ScoreChange', (score) => console.log(score));
    this.player = NativeModules.PlayerManager;
  }
  
  render() {
    return (
      <View style={styles.container}>
        <Text style={styles.welcome}>
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
  
  componentWillUnmount() {
    subscription.remove();
  }
}

module.export = Twenty48;