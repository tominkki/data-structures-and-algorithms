#include "queue.h"

template<typename T>
Queue<T>::Queue(void)
  : _count(0), _front(nullptr), _back(nullptr) {}

template<typename T>
bool Queue<T>::empty(void) const {
  return this->_count == 0;
}

template<typename T>
int Queue<T>::length(void) const {
  return this->_count;
}

template<typename T>
void Queue<T>::clear(void) {
  Node<T> *current = this->_front;
  Node<T> *tmp;

  while (current != nullptr) {
    tmp = current->_next;
    delete current;
    current = tmp;
  }

  this->_front = nullptr;
  this->_back = nullptr;
  this->_count = 0;
}

template<typename T>
T Queue<T>::front(void) const {
  return this->_front->_value;
}

template<typename T>
T Queue<T>::back(void) const {
  return this->_back->_value;
}

template<typename T>
T Queue<T>::pop(void) {
  T value;
  Node<T> *tmp;

  if (this->empty()) {
    throw "Queue is empty";
  } else if (this->length() == 1) {
    value = this->_front->_value;
    delete this->_front;
    this->_front = nullptr;
    this->_back = nullptr;
  } else {
    value = this->_front->_value;
    tmp = this->_front->_next;
    delete this->_front;
    this->_front = tmp;
  }
  this->_count--;
  return value;
}

template<typename T>
void Queue<T>::push(const T item) {
  if (this->empty()) {
    this->_back = new Node<T>(item);
    this->_front = this->_back;
  } else {
    this->_back->_next = new Node<T>(item);
    this->_back = this->_back->_next;
  }
  this->_count++;
}

template<typename T>
Queue<T>::~Queue() {
  this->clear();
}
