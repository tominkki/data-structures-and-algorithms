#include <iostream>

#include "extended-queue/extended-queue.h"

int main(void) {
  Extended_queue* queue = new Extended_queue();

  queue->append(1);
  queue->append(2);
  queue->append(3);

  while (!queue->empty()) {
    Queue_entry entry;
    queue->serve_and_retrieve(entry);
    std::cout << entry << '\n';
  }

  std::cout << queue->empty() << '\n';

  delete queue;
  return 0;
}
