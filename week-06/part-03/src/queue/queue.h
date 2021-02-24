#ifndef QUEUE_H
#define QUEUE_H

#include "../node/node.h"

template<typename T>
class Queue {
  private:
    int _count;
    Node<T> *_front;
    Node<T> *_back;

  public:
    Queue(void);
    ~Queue();

    bool empty(void) const;
    int length(void) const;
    void clear(void);

    T front(void) const;
    T back(void) const;
    T pop(void);
    void push(const T item);
};

#include "queue.cc"

#endif
