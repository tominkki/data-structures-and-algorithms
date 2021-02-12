#include <iostream>
#include "./stack/stack.h"

int main() {
  Stack<int> test;

  for (int i = 0; i < 5'000'000; i++) {
    test.push(i);
  }

  for (int i = 0; i < 5'000'000; i++) {
    test.pop();
  }

  return 0;
}
