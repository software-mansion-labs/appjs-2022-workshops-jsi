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

void task5(jsi::Runtime &rt) {
  const char *propertyName = "giveMeFive";
  auto functionBody = [](
    jsi::Runtime &rt, 
    const jsi::Value &thisValue, 
    const jsi::Value *args, 
    size_t count
  ) -> jsi::Value {
    return jsi::Value(5);
  };
  jsi::Function func = jsi::Function::createFromHostFunction(
    rt, 
    jsi::PropNameID::forAscii(rt, propertyName),
    0,
    functionBody
  );
  rt.global().setProperty(rt, propertyName, func);
}

void task6(jsi::Runtime &rt) {
  const char *functionName = "sumMeThis";
  auto functionBody = [](
    jsi::Runtime &rt, 
    const jsi::Value &thisValue, 
    const jsi::Value *args, 
    size_t count
  ) -> jsi::Value {
    const jsi::Value &firstNumJs = std::move(args[0]);
    const jsi::Value &lastNumJs = std::move(args[1]);
    double firstNum = firstNumJs.asNumber();
    double lastNum = lastNumJs.asNumber();
    return jsi::Value(firstNum + lastNum);
  };
  jsi::Function func = jsi::Function::createFromHostFunction(
    rt, 
    jsi::PropNameID::forAscii(rt, functionName),
    0,
    functionBody
  );
  rt.global().setProperty(rt, functionName, func);
}

void task7(jsi::Runtime &rt) {
  const char *functionName = "divideMeThis";
  auto functionBody = [](
    jsi::Runtime &rt, 
    const jsi::Value &thisValue, 
    const jsi::Value *args, 
    size_t count
  ) -> jsi::Value {
    const jsi::Value &firstNumJs = std::move(args[0]);
    const jsi::Value &lastNumJs = std::move(args[1]);
    double firstNum = firstNumJs.asNumber();
    double lastNum = lastNumJs.asNumber();
    if (lastNum == 0) {
      throw jsi::JSError(rt, "Unable to divide by 0");
    }
    return jsi::Value(firstNum / lastNum);
  };
  jsi::Function func = jsi::Function::createFromHostFunction(
    rt, 
    jsi::PropNameID::forAscii(rt, functionName),
    0,
    functionBody
  );
  rt.global().setProperty(rt, functionName, func);
}

void task8(jsi::Runtime &rt) {
  const char *functionName = "reverseMeThis";
  auto functionBody = [](
    jsi::Runtime &rt, 
    const jsi::Value &thisValue, 
    const jsi::Value *args, 
    size_t count
  ) -> jsi::Value {
    const jsi::Value &textJs = std::move(args[0]);
    std::string text = textJs.asString(rt).utf8(rt);
    std::reverse(text.begin(), text.end());
    jsi::Value value = jsi::String::createFromUtf8(rt, text);
    return value;
  };
  jsi::Function func = jsi::Function::createFromHostFunction(
    rt, 
    jsi::PropNameID::forAscii(rt, functionName),
    0,
    functionBody
  );
  rt.global().setProperty(rt, functionName, func);
}

void task9(jsi::Runtime &rt) {
  const char *functionName = "sumMeThisObject";
  auto functionBody = [](
    jsi::Runtime &rt, 
    const jsi::Value &thisValue, 
    const jsi::Value *args, 
    size_t count
  ) -> jsi::Value {
    const jsi::Object &objectToSum = std::move(args[0]).asObject(rt);
    double firstNum = objectToSum.getProperty(rt, "firstNum").asNumber();
    double lastNum = objectToSum.getProperty(rt, "lastNum").asNumber();
    jsi::Object result = jsi::Object(rt);
    result.setProperty(rt, "result", jsi::Value(firstNum + lastNum));
    return result;
  };
  jsi::Function func = jsi::Function::createFromHostFunction(
    rt, 
    jsi::PropNameID::forAscii(rt, functionName),
    0,
    functionBody
  );
  rt.global().setProperty(rt, functionName, func);
}

void task10(jsi::Runtime &rt) {
  const char *functionName = "sumMeThisArray";
  auto functionBody = [](
    jsi::Runtime &rt, 
    const jsi::Value &thisValue, 
    const jsi::Value *args, 
    size_t count
  ) -> jsi::Value {
    const jsi::Value &jsValue = std::move(args[0]);
    jsi::Array arrayToSum = jsValue.asObject(rt).asArray(rt);
    double sum = 0;
    for (int i = 0; i < arrayToSum.size(rt); i++) {
      sum += arrayToSum.getValueAtIndex(rt, i).asNumber();
    }
    return jsi::Value(sum);
  };
  jsi::Function func = jsi::Function::createFromHostFunction(
    rt, 
    jsi::PropNameID::forAscii(rt, functionName),
    0,
    functionBody
  );
  rt.global().setProperty(rt, functionName, func);
}

void task11(jsi::Runtime &rt) {}

void task12(jsi::Runtime &rt) {}

void task13(jsi::Runtime &rt) {}

void task14(jsi::Runtime &rt) {}
