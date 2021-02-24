#ifndef NODE_H
#define NODE_H

template<typename T>
class Node {
  public:
    T _value;
    Node<T> *_next;

    Node(const T value);
    ~Node();
};

#include "node.cc"

#endif
