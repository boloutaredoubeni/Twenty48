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
        <View>
          {this.renderStartButton()}
        </View>
        <View>
          {this.renderInfoButton()}
        </View>
      </View>
    );
  }
  
  componentWillUnmount() {
    // subscription.remove();
  }
  
  renderStartButton() {
    // TODO(boloutaredoubeni): style this
    return (
      <TouchableOpacity onPress={this._startGame()}>
        <Text style={styles.instructions}>
          Play!
        </Text>
      </TouchableOpacity>
    );
  }
  
  renderInfoButton() {
    return (
      <TouchableOpacity onPress={this._showInfo()}>
        <Text style={styles.instructions}>
          About
        </Text>
      </TouchableOpacity>
    );
  }
  
  _startGame() {
    console.log("Clicked on start game");
  }
  
  _showInfo() {
    console.log("Showinng info");
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


