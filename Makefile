
xb-prettifier := $(shell command -v xcpretty >/dev/null 2>&1 && echo "xcpretty -c" || echo "cat")
valgrind-exe := $(shell command -v valgrind)
clean: common.gypi lib2048.gyp third_party/gtest.gyp
	rm -rf generated-src/*
	rm -rf build/
	./third_party/gyp/tools/pretty_gyp.py common.gypi > common_tmp && mv common_tmp common.gypi
	./third_party/gyp/tools/pretty_gyp.py lib2048.gyp > lib_tmp && mv lib_tmp lib2048.gyp
	./third_party/gyp/tools/pretty_gyp.py third_party/gtest.gyp > gtest_tmp && mv gtest_tmp third_party/gtest.gyp

djinni: ./third_party/djinni/src/
	./third_party/djinni/src/run \
		--idl ./djinni/twenty_forty_eight.djinni \
		--cpp-out ./generated-src/cpp \
		--cpp-namespace twentyfortyeight::cpp \
		--ident-cpp-method FooBar \
		--ident-cpp-enum FooBar \
		--cpp-enum-hash-workaround false \
		--java-out ./generated-src/java \
		--java-package com.boloutaredoubeni.twentyfortyeight.djinni \
		--jni-out ./generated-src/jni \
		--jni-namespace twentyfortyeight::jni \
		--objc-out ./generated-src/objc \
		--objc-type-prefix TFE \
		--objcpp-out ./generated-src/objcpp \
		--objcpp-namespace twentyfortyeight::objc


gyp: ./third_party/gyp/gyp djinni
	PYTHONPATH=./third_party/gyp/pylib/ ./third_party/gyp/gyp --depth=. -DOS=mac -f xcode \
		--generator-output=./build/

test: test-cpp

test-cpp: lib2048
	xcodebuild -project build/lib2048.xcodeproj/ -configuration Debug -target "test" | ${xb-prettifier} \
		&& ${valgrind-exe} ./build/Debug/test

lib2048: gyp
	xcodebuild -project build/lib2048.xcodeproj/ -configuration Debug -target lib2048 | ${xb-prettifier}

lib2048_ios: lib2048
	xcodebuild -project build/lib2048.xcodeproj/ -configuration Debug -target lib2048_ios | ${xb-prettifier}


.PHONY: djinni gyp test clean
