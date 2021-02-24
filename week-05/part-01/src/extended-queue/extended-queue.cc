#include "extended-queue.h"

bool Extended_queue::full(void) const {
  return this->_count == maxqueue;
}

int Extended_queue::size(void) const {
  return this->_count;
}

void Extended_queue::clear(void) {
  this->_count = 0;
  this->_front = 0;
  this->_rear = maxqueue - 1;
}

Error_code Extended_queue::serve_and_retrieve(Queue_entry &item) {
  Error_code outcome = success;

  outcome = this->retrieve(item);
  outcome = this->serve();

  return outcome;
}
