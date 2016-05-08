// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from twenty_forty_eight.djinni

#pragma once

#include "Twenty48/player.hpp"
#include "djinni_support.hpp"

namespace twenty48 {
namespace jni {

class NativePlayer final
    : ::djinni::JniInterface<::twenty48::Player, NativePlayer> {
public:
  using CppType = std::shared_ptr<::twenty48::Player>;
  using CppOptType = std::shared_ptr<::twenty48::Player>;
  using JniType = jobject;

  using Boxed = NativePlayer;

  ~NativePlayer();

  static CppType toCpp(JNIEnv *jniEnv, JniType j) {
    return ::djinni::JniClass<NativePlayer>::get()._fromJava(jniEnv, j);
  }
  static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv *jniEnv,
                                                const CppOptType &c) {
    return {jniEnv, ::djinni::JniClass<NativePlayer>::get()._toJava(jniEnv, c)};
  }
  static ::djinni::LocalRef<JniType> fromCpp(JNIEnv *jniEnv, const CppType &c) {
    return fromCppOpt(jniEnv, c);
  }

private:
  NativePlayer();
  friend ::djinni::JniClass<NativePlayer>;
  friend ::djinni::JniInterface<::twenty48::Player, NativePlayer>;
};
}
} // namespace twenty48::jni
