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
  NativeModules,
  NativeAppEventEmitter,
} from 'react-native';
// clang-format on

class GameScreen extends Component {

  constructor(props) {
    super(props);
    // this.subscription = NativeEventEmitter.addListener('ScoreChange', (score)
    // => console.log(score));
    this.state = {
      player : NativeModules.PlayerManager,
      subscription : {},
      score : 0,
    };
    this.x = 0;
    this.y = 0;
  }

  componentWillMount() {
    this.state.player.newGame();
    this.state.subscription = NativeAppEventEmitter.addListener(
        'ScoreChanged', (score) => {this.state.score = score});
    this.state.player.swipe();
  }

  render() {
    // clang-format off
      return (
          <View
            onTouchStart={(event) => this._touchStart(event)}
            onTouchEnd={(event) => this._touchEnd(event)}>
            <Text>Game is here</Text>
            <Text>Score </Text>
          </View>
      );
      // clang-format on
  }

  componentWillUnmount() {
      try {
        this.state.subscription.remove();
      } catch (e) {
        console.error(e);
      }
  }

  _touchStart(event) {
    // FIXME check if the player can move i.e game over
    if (this._isGameOver()) return;
    this.x = event.nativeEvent.pageX;
    this.y = event.nativeEvent.pageY;
    console.log("Start touch event at (" + x + "," + y + ")");
  }

  _touchEnd(event) {
    if (this._isGameOver()) return;
    const dx = event.nativeEvent.pageX - this.x;
    const dy = event.nativeEvent.pageY - this.y;

    let direction = -1;
    if (Math.abs(dx) > 3 * Math.abs(dy) && Math.abs(dx) > 30) {
      direction = dx > 0 ? 2 : 0;
    } else if (Math.abs(dy) > 3 * Math.abs(dx) && Math.abs(dy) > 30) {
      direction = dy > 0 ? 3 : 1;
    }

    if (direction !== -1) {
      console.log("End touch event at (" + x + "," + y + ")");
      // TODO send the swipe event and redraw the view, update the score.
      console.log("Move in direction " + direction);
      return;
  }
    console.error("Undefined touch event");
  }

  _isGameOver() {
    const _player = this.state.player;
    if (_player == null) {
      console.error("The player value is null");
      return true;
    }
    /* FIXME get the game over message from internal object */
    return false;
  }

}

class InfoScreen extends Component {

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

export default class HomeScreen extends Component {
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
        </View>
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
