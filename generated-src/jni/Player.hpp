// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from twenty_forty_eight.idl

#pragma once

#include "Player.hpp"
#include "djinni_support.hpp"

namespace twentyfortyeight { namespace jni {

class Player final : ::djinni::JniInterface<::twentyfortyeight::cpp::Player, Player> {
public:
    using CppType = std::shared_ptr<::twentyfortyeight::cpp::Player>;
    using CppOptType = std::shared_ptr<::twentyfortyeight::cpp::Player>;
    using JniType = jobject;

    using Boxed = Player;

    ~Player();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<Player>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<Player>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    Player();
    friend ::djinni::JniClass<Player>;
    friend ::djinni::JniInterface<::twentyfortyeight::cpp::Player, Player>;

};

} }  // namespace twentyfortyeight::jni