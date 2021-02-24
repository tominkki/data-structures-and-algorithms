#ifndef QUEUE_H
#define QUEUE_H

typedef double Queue_entry;

enum Error_code {
	success, fail, utility_range_error, underflow, overflow, fatal,
	not_present, duplicate_error, entry_inserted, entry_found,
	internal_error
};

const int maxqueue = 64;

class Queue {
  protected:
    int _count;
    int _front;
    int _rear;
    Queue_entry _entry[ maxqueue ];
  public:
    Queue(void);
    bool empty(void) const;
    Error_code serve(void);
    Error_code append(const Queue_entry &item);
    Error_code retrieve(Queue_entry &item) const;
};

#endif
