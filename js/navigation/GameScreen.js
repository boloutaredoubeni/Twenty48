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

export default class GameScreen extends Component {

  constructor(props) {
    super(props);
    // this.subscription = NativeEventEmitter.addListener('ScoreChange', (score)
    // => console.log(score));
    this.state = {
      player : NativeModules.PlayerManager,
      subscription : {},
    };
    this.x = 0;
    this.y = 0;
  }

  componentWillMount() {
    this.state.player.newGame();
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
