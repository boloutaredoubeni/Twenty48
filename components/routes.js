/* @flow */
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

export class InfoScreen extends Component {

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

export class GameScreen extends Component {

  constructor(props) {
    super(props);
    // this.subscription = NativeEventEmitter.addListener('ScoreChange', (score)
    // => console.log(score));
    this.state = {
      player : NativeModules.PlayerManager,
      subscription : {},
    };
  }

  render() {
    // clang-format off
      return (
          <View>
            <Text>Game is here</Text>
            <Text>Score </Text>
          </View>
      );
      // clang-format on
  }
}



export class HomeScreen extends Component {

  constructor(props) {
    super(props);
    // this.subscription = NativeEventEmitter.addListener('ScoreChange', (score)
    // => console.log(score));
    this.state = {};
  }

  render() {
    // clang-format off
    return (
      <View style = {styles.container}>
        <Text style = {styles.welcome}>
            2048
        </Text>
        <View>
          {this.renderStartButton()}
        </View >
        <View>
            {this.renderInfoButton()}
        </View>
      </View>
    );
    // clang-format on
  }

  renderStartButton() {
    // TODO(boloutaredoubeni): style this
    // clang-format off
    return (
      <TouchableOpacity onPress={() => this._startGame()}>
        <Text style = {styles.instructions}>
                Play!
        </Text>
      </TouchableOpacity>
      );
    //   clang-format on
  }

  renderInfoButton() {
      // clang-format off
    return (
     <TouchableOpacity onPress={() => this._showInfo()}>
        <Text style={styles.instructions}>
                About
        </Text>
      </TouchableOpacity>
      );
    // clang-format on
  }

  _startGame() {
    console.log("Clicked on start game");
    this.props.navigator.push({
      component : GameScreen,
    });
  }

  _showInfo() {
    console.log("Showing info");
    this.props.navigator.push({
      component : InfoScreen,
    });
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
