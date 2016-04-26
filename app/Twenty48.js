import React, {Component,  Text, View, NativeModules, NativeEventEmitter} from 'react-native';
import style from './styles';

export default class App extends Component {
  
  constructor(props) {
    super(props);
    // this.subscription = NativeEventEmitter.addListener('ScoreChange', (score) => console.log(score));
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

