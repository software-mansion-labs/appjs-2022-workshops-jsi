#include "react-native-appjs.h"

void install(jsi::Runtime &rt) {
  task1(rt);
  task2(rt);
  task3(rt);
  task4(rt);
  task5(rt);
  task6(rt);
  task7(rt);
  task8(rt);
  task9(rt);
  task10(rt);
  task11(rt);
  task12(rt);
  task13(rt);
  task14(rt);
}

void task1(jsi::Runtime &rt) {
  const char *propertyName = "answerToTheUltimateQuestionOfLifeTheUniverseAndEverything";
  jsi::Value value = jsi::Value(42);
  rt.global().setProperty(rt, propertyName, value);
}

void task2(jsi::Runtime &rt) {
  const char *propertyName = "isWednesday";
  jsi::Value value = jsi::Value(true);
  rt.global().setProperty(rt, propertyName, value);
}

void task3(jsi::Runtime &rt) {
  const char *propertyName = "conferenceName";
  jsi::Value value = jsi::String::createFromUtf8(rt, "App.js");
  rt.global().setProperty(rt, propertyName, value);
}

void task4(jsi::Runtime &rt) {
  const char *propertyName = "myAwesomeArray";
  jsi::Array arrayValue(rt, 3);
  arrayValue.setValueAtIndex(rt, 0, 42);
  arrayValue.setValueAtIndex(rt, 1, true);
  arrayValue.setValueAtIndex(rt, 2, "App.js");
  rt.global().setProperty(rt, propertyName, arrayValue);
}

void task5(jsi::Runtime &rt) {}

void task6(jsi::Runtime &rt) {}

void task7(jsi::Runtime &rt) {}

void task8(jsi::Runtime &rt) {}

void task9(jsi::Runtime &rt) {}

void task10(jsi::Runtime &rt) {}

void task11(jsi::Runtime &rt) {}

void task12(jsi::Runtime &rt) {}

void task13(jsi::Runtime &rt) {}

void task14(jsi::Runtime &rt) {}
