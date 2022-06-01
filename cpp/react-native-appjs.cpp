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

void task11(jsi::Runtime &rt) {
  const char *functionName = "nativeMap";
  auto functionBody = [](
    jsi::Runtime &rt, 
    const jsi::Value &thisValue, 
    const jsi::Value *args, 
    size_t count
  ) -> jsi::Value {
    const jsi::Value &jsArray = std::move(args[0]);
    const jsi::Value &jsFunction = std::move(args[1]);
    jsi::Array arrayOfNumbers = jsArray.asObject(rt).asArray(rt);
    jsi::Function mapper = jsFunction.asObject(rt).asFunction(rt);
    jsi::Array mappedArray(rt, arrayOfNumbers.size(rt));
    for (int i = 0; i < arrayOfNumbers.size(rt); i++) {
      jsi::Value mappedValue = mapper.call(rt, arrayOfNumbers.getValueAtIndex(rt, i));
      mappedArray.setValueAtIndex(rt, i, mappedValue);
    }
    return mappedArray;
  };
  jsi::Function func = jsi::Function::createFromHostFunction(
    rt, 
    jsi::PropNameID::forAscii(rt, functionName),
    0,
    functionBody
  );
  rt.global().setProperty(rt, functionName, func);
}

void task12(jsi::Runtime &rt) {
  const char *functionName = "useJsFunction";
  auto functionBody = [](
    jsi::Runtime &rt, 
    const jsi::Value &thisValue, 
    const jsi::Value *args, 
    size_t count
  ) -> jsi::Value {
    jsi::Object console = rt.global().getProperty(rt, "console").asObject(rt);
    jsi::Function log = console.getProperty(rt, "log").asObject(rt).asFunction(rt);
    log.call(rt, "Hello from the native side!");
    return jsi::Value::undefined();
  };
  jsi::Function func = jsi::Function::createFromHostFunction(
    rt, 
    jsi::PropNameID::forAscii(rt, functionName),
    0,
    functionBody
  );
  rt.global().setProperty(rt, functionName, func);
}

class Date : public jsi::HostObject {
public:
  jsi::Value get(jsi::Runtime& rt, const jsi::PropNameID& name) override {
    if (name.utf8(rt) == "now") {
      time_t now = time(0);
      std::string dateTime = ctime(&now);
      return jsi::String::createFromUtf8(rt, dateTime.c_str());
    }
    else if (name.utf8(rt) == "day") {
      return jsi::Value(day);
    }
    else if (name.utf8(rt) == "month") {
      return jsi::Value(month);
    }
    else if (name.utf8(rt) == "year") {
      return jsi::Value(year);
    }
    
    return jsi::Value::undefined();
  }
  
  void set(jsi::Runtime& rt, const jsi::PropNameID& name, const jsi::Value& value) override {
    if (name.utf8(rt) == "day") {
      day = value.asNumber();
    }
    else if (name.utf8(rt) == "month") {
      auto month = value.asNumber();
      if (month > 12) {
        throw jsi::JSError(rt, "invalid argument for property month");
      }
      this->month = month;
    }
    else if (name.utf8(rt) == "year") {
      year = value.asNumber();
    }
  }
  
  std::vector<facebook::jsi::PropNameID> getPropertyNames(jsi::Runtime& rt) override {
    std::vector<facebook::jsi::PropNameID> properties;
    properties.push_back(facebook::jsi::PropNameID::forAscii(rt, "now"));
    properties.push_back(facebook::jsi::PropNameID::forAscii(rt, "day"));
    properties.push_back(facebook::jsi::PropNameID::forAscii(rt, "month"));
    properties.push_back(facebook::jsi::PropNameID::forAscii(rt, "year"));
    return properties;
  }
  
  int year;
  int month;
  int day;
  
  Date() {
    time_t rawtime;
    time(&rawtime);
    struct tm *timeinfo = localtime(&rawtime);
    year = timeinfo->tm_year + 1900;
    month = timeinfo->tm_mon;
    day = timeinfo->tm_mday;
  }
  ~Date() override {}
};

void task13(jsi::Runtime &rt) {
  const char *propertyName = "getDateObject";
  auto functionBody = [](
    jsi::Runtime &rt, 
    const jsi::Value &thisValue, 
    const jsi::Value *args, 
    size_t count
  ) -> jsi::Value {
    auto date = std::make_shared<Date>();
    jsi::Object jsDate = jsi::Object::createFromHostObject(rt, date);
    return jsDate;
  };
  jsi::Function func = jsi::Function::createFromHostFunction(
    rt, 
    jsi::PropNameID::forAscii(rt, propertyName),
    0,
    functionBody
  );
  rt.global().setProperty(rt, propertyName, func);
}

class InfinityObject : public jsi::HostObject {
public:
  jsi::Value get(jsi::Runtime& rt, const jsi::PropNameID& name) override {
    counter++;
    return jsi::Value(counter);
  }
  
  void set(jsi::Runtime& rt, const jsi::PropNameID& name, const jsi::Value& value) override {
    counter--;
  }
  
  std::vector<facebook::jsi::PropNameID> getPropertyNames(jsi::Runtime& rt) override {
    std::vector<facebook::jsi::PropNameID> properties;
    return properties;
  }
  
  int counter = 0;
  
  InfinityObject() {}
  ~InfinityObject() override {}
};

void task14(jsi::Runtime &rt) {
  const char *propertyName = "getInfinityObject";
  auto functionBody = [](
    jsi::Runtime &rt, 
    const jsi::Value &thisValue, 
    const jsi::Value *args, 
    size_t count
  ) -> jsi::Value {
    auto infinityObject = std::make_shared<InfinityObject>();
    return jsi::Object::createFromHostObject(rt, infinityObject);
  };
  jsi::Function func = jsi::Function::createFromHostFunction(
    rt, 
    jsi::PropNameID::forAscii(rt, propertyName),
    0,
    functionBody
  );
  rt.global().setProperty(rt, propertyName, func);
}
