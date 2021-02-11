#include "stack.h"

Stack::Stack() {
  count = 0;
}

Error_code Stack::push(const Stack_entry &item) {
  Error_code outcome = success;
  if (count >= maxstack) {
    outcome = overflow;
  } else {
    entry[count++] = item;
  }
      
  return outcome;
}

Error_code Stack::pop() {
  Error_code outcome = success;
  if (count == 0){
    outcome = underflow;
  } else {
    --count;
  }

  return outcome;
}

Error_code Stack::top(Stack_entry &item) const {
  Error_code outcome = success;
  if (count == 0) {
    outcome = underflow;
  } else {
    item = entry[count - 1];
  }
  
  return outcome;
}

bool Stack::empty() const {
  bool outcome = true;
  if (count > 0) {
    outcome = false;
  }

  return outcome;
}

Error_code Stack::copy_stack(Stack &dest) {
  if (this-> count == 0) { return underflow; }

  if (!dest.empty()) {
    while (!dest.empty()) {
      dest.pop();
    }
  }

  for (int i = 0; i < this->count; i++) {
    dest.push(this->entry[i]);
  }

  return success;
}
