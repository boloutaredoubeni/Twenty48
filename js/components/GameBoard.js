/**
 * @flow
 */
'use strict';

// clang-format off
import React, {
  View,
  Component,
  StyleSheet
} from 'react-native';
// clang-format on

class Cell extends Component {
  render(): React.Element {
    return (
        // clang-format off
      <View />
        // clang-format on
        );
  }
}

class Tile extends Component {
  render(): React.Element {
    return (
        // clang-format off
      <View>
      </View>
        // clang-format on
        );
  }
}

export default class GameBoard extends Component {

  x: number;
  y: number;

  constructor(props: any) {
    super(props);
    this.x = 0;
    this.y = 0;
  }

  render(): React.Element {
    let tiles = this.props.tiles;
    return (
        // clang-format off
      /* TODO init with tiles */
      <View
          onTouchStart={(event: any): void => this._touchStart(event)}
          onTouchEnd={(event: any): void => this._touchEnd(event)}>
        <View></View>
        <View></View>
        <View></View>
        <View></View>
      </View>
      // clang-format on
    );
  }

  _touchStart(event: any) {
    this.x = event.nativeEvent.pageX;
    this.y = event.nativeEvent.pageY;
    console.log("Start touch event at (" + this.x + "," + this.y + ")");
  }

  _touchEnd(event: any) {
    const dx: number = event.nativeEvent.pageX - this.x;
    const dy: number = event.nativeEvent.pageY - this.y;

    let direction = -1;
    if (Math.abs(dx) > 3 * Math.abs(dy) && Math.abs(dx) > 30) {
      direction = dx > 0 ? 2 : 0;
    } else if (Math.abs(dy) > 3 * Math.abs(dx) && Math.abs(dy) > 30) {
      direction = dy > 0 ? 3 : 1;
    }

    if (direction !== -1) {
      console.log("End touch event at (" + this.x + "," + this.y + ")");
      // TODO send the swipe event and redraw the view, update the score.
      console.log("Move in direction " + direction);
      return;
    }
    console.error("Undefined touch event");
  }
}
