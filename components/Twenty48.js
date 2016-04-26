import React, {Component, StyleSheet, Text, View, NativeModules, NativeEventEmitter, TouchableOpacity} from 'react-native';


// TODO(boloutaredoubeni): Button to navigate to game
// TODO(boloutaredoubeni): Button for game info and how to play
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
          2048
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
    // subscription.remove();
  }
  
  renderButton() {
    return (
      <TouchableOpacity onPress={this._startGame()}>
        <Text style={styles.instructions}>
          Play!
        </Text>
      </TouchableOpacity>
    );
  }
}


const styles = StyleSheet.create({
  container : {
    flex : 1,
    justifyContent : 'center',
    alignItems : 'center',
    backgroundColor : '#F5FCFF',
  },
  welcome : {
    fontSize : 20,
    textAlign : 'center',
    margin : 10,
  },
  instructions : {
    textAlign : 'center',
    color : '#333333',
    marginBottom : 5,
  },
});


