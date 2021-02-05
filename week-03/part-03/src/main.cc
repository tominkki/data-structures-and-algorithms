#include <iostream>
#include "./stack/stack.h"

int main(void) {
  Stack stack = Stack();

  std::cout << "Input line to be reversed.\n>>> ";

  while (std::cin.peek() != '\n') {
    stack.push(std::cin.get());
  }

  std::cout << "\nLine reversed:\n";

  while (!stack.empty()) {
    double item = {};
    stack.top(item);
    std::cout << (char)item;
    stack.pop();
  }

  std::cout << '\n';
  
  return 0;
}
