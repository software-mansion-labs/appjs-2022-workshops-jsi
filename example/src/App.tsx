import 'react-native-appjs';

import * as React from 'react';

import { Button, StyleSheet, View } from 'react-native';

export default function App() {

  const task1 = () => {
    console.log(answerToTheUltimateQuestionOfLifeTheUniverseAndEverything)
  }

  const task2 = () => {
    console.log(isWednesday)
  }

  const task3 = () => {
    console.log(conferenceName)
  }

  const task4 = () => {
    console.log(myAwesomeArray)
  }

  const task5 = () => {
    console.log(giveMeFive, giveMeFive())
  }

  const task6 = () => {
    console.log(sumMeThis(4, 5))
  }

  const task7 = () => {}

  const task8 = () => {}

  const task9 = () => {}

  const task10 = () => {}

  const task11 = () => {}

  const task12 = () => {}

  const task13 = () => {}

  const task14 = () => {}

  return (
    <View style={styles.container}>
      <Button title="task1" onPress={task1} />
      <Button title="task2" onPress={task2} />
      <Button title="task3" onPress={task3} />
      <Button title="task4" onPress={task4} />
      <Button title="task5" onPress={task5} />
      <Button title="task6" onPress={task6} />
      <Button title="task7" onPress={task7} />
      <Button title="task8" onPress={task8} />
      <Button title="task9" onPress={task9} />
      <Button title="task10" onPress={task10} />
      <Button title="task11" onPress={task11} />
      <Button title="task12" onPress={task12} />
      <Button title="task13" onPress={task13} />
      <Button title="task14" onPress={task14} />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
});
