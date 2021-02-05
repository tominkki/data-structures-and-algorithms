#include <iostream>
#include "./extended-stack/extended-stack.h"

int main(void) {
  Extended_stack stack = Extended_stack();

  stack.push('a');
  std::cout << stack.full() << '\n' << stack.size() << '\n';

  stack.clear();

  std::cout << stack.empty() << '\n' << stack.size() << '\n';

  return 0;
}
