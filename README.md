# Twenty48

An example project using [React Native](https://facebook.github.io/react-native/) for the UI and C++ for the business logic
via [Djinni](https://github.com/dropbox/djinni)

### Try it Out
It's not done yet but at this point the React Native code can call C++
For now you can:
 ```
 git clone --recursive git@github.com:boloutaredoubeni/Twenty48.git
 ```

Then run
```
make
```

#### iOS
```
make ios
```

#### Android
```
make android
```

### Test
```
make test
```

### Project Structure
```
.
|_ android/
    |_ app/src/main/java/com/boloutaredoubeni/twenty48/
      |_ djinni/ -> Java files generated by Djinni to link with C++
      |_ reactmodules/ -> Native Module code for android to link JS to android to C++
    |_ jni-src/ -> JNI C++ files
|_ js/ -> react native components
|_ djinni/ -> Interface definitions
|_ include/Twenty48 -> Generated C++ classes, structs, etc...
|_ ios/Twenty48/ -> Native Module code for ios
    |_ Djinni/ -> Generated Obj-C and Obj-C++
|_ src/ -> Implemented C++ files
|_ test/ -> Tests for business logic
|_ index.*.js -> entry point for React

```

### Screenshot
![](screenshots/iphone-homescreen.png)

### License
MIT
