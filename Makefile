
clean:
	rm -rf generated-src

djinni: ./third_party/djinni/src/
	./third_party/djinni/src/run \
		--idl ./djinni/game_state.idl \
		--cpp-out ./generated-src/cpp \
		--ident-cpp-file FooBar \
		--cpp-namespace twentyfortyeight::cpp \
		--ident-cpp-method FooBar \
		--jni-out ./generated-src/jni \
		--jni-namespace twentyfortyeight::jni \
		--objc-out ./generated-src/objc \
		--objc-type-prefix TFE \
		--objcpp-out ./generated-src/objcpp \
		--objcpp-namespace twentyfortyeight::objc

.PHONY: djinni
