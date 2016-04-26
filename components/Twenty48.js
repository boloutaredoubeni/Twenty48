import React, {Component, StyleSheet, Text, View, Navigator} from 'react-native';
import HomeScreen from './HomeScreen';

// TODO(boloutaredoubeni): Button to navigate to game
// TODO(boloutaredoubeni): Button for game info and how to play
export default class App extends Component {
  constructor(props) {
    super(props);
    // this.subscription = NativeEventEmitter.addListener('ScoreChange', (score)
    // => console.log(score));
    this.state = {};
  }

  render() {
    return(
      // clang-format off
      <Navigator
        initialRoute = {{ component: HomeScreen, type: "right" }} 
        renderScene = { this._renderScene } />
  );
  // clang-format on
  }
  
  _renderScene(route, navigator) {
    const RouteComponent = route.component;
    // clang-format off
    return (
      <RouteComponent {...route.props}
        navigator={navigator}
        route={route} />
      
    );
    // clang-format on
  }
}
  
  


