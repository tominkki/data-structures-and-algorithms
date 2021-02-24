#include "queue.h"

Queue::Queue(void) {
  this->_count = 0;
  this->_front = 0;
  this->_rear = maxqueue - 1;
}
  
bool Queue::empty(void) const {
  return this->_count == 0;
}

Error_code Queue::serve(void) {
  if (this->empty()) {
    return underflow;
  }

  this->_count--;
  this->_front = this->_front + 1 == maxqueue ? 0 : this->_front + 1;

  return success;
}

Error_code Queue::append(const Queue_entry &item) {
  if (this->_count == maxqueue) {
    return overflow;
  }

  this->_count++;
  this->_rear = this->_rear + 1 == maxqueue ? 0 : this->_rear + 1;
  this->_entry[this->_rear] = item;

  return success;
}

Error_code Queue::retrieve(Queue_entry &item) const {
  if (this->empty()) {
    return underflow;
  }

  item = this->_entry[this->_front];

  return success;
}
