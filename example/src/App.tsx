import 'react-native-appjs';

import * as React from 'react';

import { Button, StyleSheet, View } from 'react-native';

declare const foo: number;

export default function App() {
  const handlePress = () => {
    console.log(foo);
  };

  return (
    <View style={styles.container}>
      <Button title="Click me!" onPress={handlePress} />
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
