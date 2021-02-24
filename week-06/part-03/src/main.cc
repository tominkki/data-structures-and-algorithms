#include <iostream>

#include "./queue/queue.h"

char read_and_compare(void);

int main(void) {
  while (true) {
    std::cout << read_and_compare() << '\n';
  }

  return 0;
}

char read_and_compare(void) {
  Queue<char> *queue = new Queue<char>();
  bool same = true;

  while ((std::cin.peek() != ':') && (std::cin.peek() != '\n')) {
    queue->push(std::cin.get());
  }

  if (std::cin.peek() == '\n') {
    std::cin.ignore(INT16_MAX, '\n');
    return 'N';
  }

  std::cin.get();

  while (std::cin.peek() != '\n') {
    if (queue->empty()) {
      std::cin.ignore(INT16_MAX, '\n');
      return 'R';
    } else if (std::cin.get() != queue->pop()) {
      same = false;
    }
  }

  std::cin.ignore(INT16_MAX, '\n');

  if (!queue->empty()) {
    return 'L';
  }

  return same ? 'S' : 'D';
}