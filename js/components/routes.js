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
import GameBoard from './GameBoard';
// clang-format on

const Direction: any = {
  None : 0,
  Up : 1,
  Down : 2,
  Left : 3,
  Right : 4,
};

// clang-format off
type Move =
  | Direction.None
  | Direction.Up
  | Direction.Down
  | Direction.Right
  | Direction.Left;
// clang-format on

/**
 * Controller for the GameView
 */
class GameScreen extends Component {

  state: {
    score : number,
    gameOver : boolean,
    movesMade : 0,
    gameBoard : Array<number>
  };
  player: NativeModules.PlayerManager;
  subscription: any;
  x: number;
  y: number;

  constructor(props: any) {
    super(props);
    this.state = {score : 0, gameOver : false, movesMade : 0, gameBoard : []};
    this.player = NativeModules.PlayerManager;
    this.subscription = {};
  }

  componentWillMount() {
    this.player.newGame();
    this.subscription = NativeAppEventEmitter.addListener(
        'ScoreChanged', (game: any) => { this.setState(game); });
  }

  render(): React.Element {
    // clang-format off
      return (
          <View style={styles.container}>
            <Text>Score: {this.state.score}</Text>
            <Text>Moves: {this.state.movesMade}</Text>
            <Text>GameOver: {this.state.gameOver}</Text>
            <TouchableOpacity
                style={styles.backButton}
                onPress={(): void => this._goHome()}>
              <Text style={styles.instructions}>
                    Back
              </Text>
            </TouchableOpacity>
            <GameBoard
              tiles={this.state.gameBoard}
              onTouchStart={(event: any): void => this._touchStart(event)}
              onTouchEnd={(event: any): void => this._touchEnd(event)}/>
            {/*<Text>Winner: {this.state.hasWon}</Text>*/}
          </View>
      );
      // clang-format on
  }

  componentWillUnmount() {
      try {
        this.subscription.remove();
      } catch (e) {
        console.error(e);
      }
  }

  _goHome() {
    this.props.navigator.pop();
  }

  _touchStart(event: any) {
    if (this.state.gameOver) return;
    this.x = event.nativeEvent.pageX;
    this.y = event.nativeEvent.pageY;
    console.log("Start touch event at (" + this.x + "," + this.y + ")");
  }

  _touchEnd(event: any) {
    if (this.state.gameOver) return;
    const dx: number = event.nativeEvent.pageX - this.x;
    const dy: number = event.nativeEvent.pageY - this.y;

    let direction: Move = Direction.None;
    if (Math.abs(dx) > 3 * Math.abs(dy) && Math.abs(dx) > 30) {
      direction = dx > 0 ? Direction.Right : Direction.Left;
    } else if (Math.abs(dy) > 3 * Math.abs(dx) && Math.abs(dy) > 30) {
      direction = dy > 0 ? Direction.Up : Direction.Down;
    }

    console.log("End touch event at (" + this.x + "," + this.y + ")");
    this.x = 0;
    this.y = 0;
          // TODO send the swipe event and redraw the view, update the score.
      console.log("Move in direction " + direction);
      // try {
      this._swipe(direction);
    // } catch(e) {
    //   console.error(e);
    // }

  }

  _swipe(direction: Move) {
    switch (direction) {
    case Direction.Up:
      this.player.swipe(this.player.MoveUp);
      break;
    case Direction.Down:
      this.player.swipe(this.player.MoveDown);
      break;
    case Direction.Left:
      this.player.swipe(this.player.MoveLeft);
      break;
    case Direction.Right:
      this.player.swipe(this.player.MoveRight);
      break;
    default:
      throw Error('Invalid direction');
    }
  }
}

/**
 * Controller for the About/Info Screen
 */
class InfoScreen extends Component {

  render(): React.Element {
    // clang-format off
    return (
      <View style={styles.container}>
        <TouchableOpacity
            style={styles.backButton}
            onPress={(): void => this._goHome()}>
          <Text style={styles.instructions}>
                Back
          </Text>
        </TouchableOpacity>
        <Text>About 2048</Text>
      </View>
    );
            // clang-format on
  }

  _goHome() { this.props.navigator.pop(); }
}

/**
 * The initial screen for the application
 */
export default class HomeScreen extends Component {

  render(): React.Element {
    // clang-format off
    return (
      <View style={styles.container}>
        <Text style={styles.welcome}>
            2048
        </Text>
        <View style={styles.playButton}>
          {this.renderStartButton()}
        </View>
        <View style={styles.infoButton}>
          {this.renderInfoButton()}
        </View>
      </View>
    );
    // clang-format on
  }

  renderStartButton(): React.Element {
    // TODO(boloutaredoubeni): style this
    // clang-format off
    return (
      <TouchableOpacity onPress={(): void => this._startGame()}>
        <Text style={styles.instructions}>
                Play!
        </Text>
      </TouchableOpacity>
      );
    //   clang-format on
  }

  renderInfoButton(): React.Element {
      // clang-format off
    return (
     <TouchableOpacity onPress={(): void => this._showInfo()}>
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

const colors = {
  buttercup : '#F39C12',
  jade : '#00B16A',
  wistful : '#AEA8D3',
  salem : '#1E824C',
  burntOrange : '#D35400',
  porcelain : '#ECF0F1',
}

const buttonAttrs = {
  border : {
    radius : 6,
    width : 2,
  },
  margin : 5,
  fontSize : 25,
}

const styles = StyleSheet.create({
  container : {
    flex : 1,
    justifyContent : 'center',
    alignItems : 'center',
    backgroundColor : colors.wistful,
  },
  welcome : {
    fontSize : 40,
    textAlign : 'center',
    margin : 10,
  },
  instructions : {
    textAlign : 'center',
    color : colors.porcelain,
    fontSize : 20,
    margin : 10,
  },
  playButton : {
    borderRadius : buttonAttrs.border.radius,
    borderWidth : buttonAttrs.border.width,
    borderColor : colors.salem,
    backgroundColor : colors.jade,
    margin : buttonAttrs.margin,
  },
  infoButton : {
    borderRadius : buttonAttrs.border.radius,
    borderWidth : buttonAttrs.border.width,
    borderColor : colors.burntOrange,
    backgroundColor : colors.buttercup,
    margin : buttonAttrs.margin,
  },
  backButton : {
    margin : buttonAttrs.margin,
  },
});
