# Makefile
xb-prettifier := $(shell command -v xcpretty >/dev/null 2>&1 && echo "xcpretty -c" || echo "cat")
valgrind-exe := $(shell command -v valgrind >/dev/null 2>&1 && echo "valgrind" || echo "")
clang-format := $(shell command -v clang-format >/dev/null 2>&1 && echo "clang-format -i -style=file" || echo "touch")
GYP ?=  ./third_party/gyp
DJINNI ?= ./third_party/djinni/src/run

all: format test ios_app android_app

format: $(DJINNI)
	@echo "Cleaning up Gyp files"
	@$(GYP)/tools/pretty_gyp.py lib2048.gyp > lib_tmp && mv lib_tmp lib2048.gyp
	@$(GYP)/tools/pretty_gyp.py third_party/gtest.gyp > gtest_tmp && mv gtest_tmp third_party/gtest.gyp
	@echo "Cleaning up source files via clang-format"
	@${clang-format} src/*.cpp 
	@${clang-format} src/*.hpp 
	@${clang-format} *.js 
	@${clang-format} ios/Twenty48/**/*.h  
	@${clang-format} ios/Twenty48/*.m 
	@${clang-format} ios/Twenty48/**/*.mm
	@${clang-format} test/*.cpp
	@${clang-format} android/jni-src/*.cpp 
	@${clang-format} android/jni-src/*.hpp  
	@${clang-format} android/app/src/main/java/**/**/*.java

clean: lib2048.gyp third_party/gtest.gyp
	@echo "Removing generated files" 
	@rm -rf build/*
	@rm -rf android/build/*
	@rm -rf android/app/build/*
	@rm -rf android/app/obj/*
	@rm -rf third_party/build/*
	@rm -rf ios/Twenty48/Djinni/*
	@rm -rf include/*
	@rm -rf android/jni-src/*
	@rm -rf android/app/src/main/java/com/boloutaredoubeni/twenty48/djinni/*
	@rm -f *.mk
	

$(GYP):
	@echo "Checking out GYP"
	@cd $(GYP) && git checkout -q 0bb67471bca068996e15b56738fa4824dfa19de0

$(DJINNI): ./third_party/djinni/src/ $(GYP)
	@echo "Generating interface files" 
	@$(DJINNI) \
		--idl ./djinni/twenty_forty_eight.djinni \
		\
		--cpp-out include/Twenty48 \
		--cpp-namespace twenty48 \
		--ident-cpp-method FooBar \
		--ident-cpp-enum FooBar \
		\
		--objcpp-include-cpp-prefix Twenty48/ \
		--objcpp-out ./ios/Twenty48/Djinni \
		--objcpp-namespace twenty48::objc \
		\
		--objc-out ./ios/Twenty48/Djinni \
		--objc-type-prefix T48 \
		\
		--jni-out android/jni-src \
		--jni-namespace twenty48::jni \
		--ident-jni-file NativeFooBar \
		--jni-include-cpp-prefix Twenty48/ \
		--ident-jni-class NativeFooBar \
		\
		--java-out ./android/app/src/main/java/com/boloutaredoubeni/twenty48/djinni \
		--java-package com.boloutaredoubeni.twenty48.djinni
		
	

lib2048.xcodeproj: $(GYP) djinni
	 @$(GYP)/gyp --depth=. -DOS=mac -f xcode \
		--generator-output=./build/mac/ -I./common.gypi lib2048.gyp
		
test: test-cpp

test-cpp: lib2048.xcodeproj
	@echo "Run tests"
	@xcodebuild -project build/mac/lib2048.xcodeproj/ -configuration Debug -target "test" | ${xb-prettifier} \
		&& ${valgrind-exe} ./build/Debug/test


ios.xcodeproj: djinni
	@$(GYP)/gyp --depth=. -DOS=ios -f xcode \
		--generator-output=./build/ios/ -I./common.gypi lib2048.gyp


ios: ios.xcodeproj
	@xcodebuild -project build/ios/lib2048.xcodeproj/ -configuration Debug -target lib2048_ios | ${xb-prettifier}


android: gyp_android

gyp_android: djinni
	@PYTHONPATH=$(GYP)/pylib ANDROID_BUILD_TOP=$(shell dirname `which ndk-build`) $(GYP)/gyp \
		--depth=. -f android 	-DOS=android -I./common.gypi lib2048.gyp --root-target=lib2048_jni


ios_app: ios
	@echo "Building ios app"
	@xcodebuild -workspace ios/Twenty48.xcworkspace -scheme Twenty48 -configuration Debug -sdk iphonesimulator | ${xb-prettifier}
	
android_app: android
	@echo "Running android project"
	@react-native run-android

.PHONY: $(DJINNI) test clean ios android
