FORCE_GYP := $(shell make -C ../../GypAndroid.mk)
APP_ABI := all
APP_OPTIM := debug
NDK_TOOLCHAIN_VERSION := clang
# APP_PLATFORM := android-21
APP_STL := c++_shared
APP_BUILD_SCRIPT := jni/Android.mk
APP_MODULES := lib2048_jni
