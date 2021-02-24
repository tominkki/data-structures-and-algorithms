#include "node.h"

template<typename T>
Node<T>::Node(const T value)
  : _value(value), _next(nullptr) {}

template<typename T>
Node<T>::~Node() {}
