#include "react-native-appjs.h"

void install(jsi::Runtime &rt) {
  rt.global().setProperty(rt, "foo", jsi::Value(42));
}
