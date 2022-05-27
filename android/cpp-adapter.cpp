#include <jni.h>
#include "react-native-appjs.h"

using namespace facebook;

extern "C"
JNIEXPORT void JNICALL
Java_com_reactnativeappjs_AppjsModule_nativeInstall(JNIEnv *env, jobject clazz, jlong jsiPtr) {
  jsi::Runtime &runtime = *reinterpret_cast<jsi::Runtime *>(jsiPtr);
  install(runtime);
}
