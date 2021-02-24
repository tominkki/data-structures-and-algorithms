#ifndef EXTENDED_QUEUE_H
#define EXTENDED_QUEUE_H

#include "../queue/queue.h"

class Extended_queue : public Queue {
  public:
    bool full(void) const;
    int size(void) const;
    void clear(void);
    Error_code serve_and_retrieve(Queue_entry &item);
};

#endif
