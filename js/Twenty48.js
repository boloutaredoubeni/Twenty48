/** @flow */

'use strict';
// clang-format off
import React, {
  Component,
  StyleSheet,
  Text,
  View,
  Navigator
} from 'react-native';
import HomeScreen from './components/routes';
// clang-format on


/**
 * The root component for the application
 */
export default class App extends Component {
  render() {
    // clang-format off
    return (
      <Navigator
        initialRoute={{
          component: HomeScreen,
          type: "right"
        }}
        renderScene={ this._renderScene }/>
    );
    // clang-format on
  }

  _renderScene(route, navigator) {
    const RouteComponent = route.component;
    // clang-format off
    return (
      <RouteComponent {...route.props}
        navigator={navigator}
        route={route}
        onBack={() => {
          if (route.index > 0) {
            navigator.pop();
          }
        }} />
    );
    // clang-format on
  }
}
