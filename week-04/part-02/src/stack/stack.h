#ifndef STACK_H
#define STACK_H

typedef double Stack_entry;
enum Error_code {
  success, fail, utility_range_error, underflow, overflow, fatal,
  not_present, duplicate_error, entry_inserted, entry_found,
  internal_error
};
const int maxstack = 256;

class Stack {
  public:
    Stack();
    bool empty() const;
    Error_code pop();
    Error_code top(Stack_entry &item) const;
    Error_code push(const Stack_entry &item);
    Error_code copy_stack(Stack &dest);

  private:
    int count;
    Stack_entry entry[maxstack];   
};

#endif
