#include <iostream>

#include "./stack/stack.h"

bool full(Stack &s);
Error_code pop_top(Stack &s, Stack_entry &entry);
void clear(Stack &s);
int size (const Stack &s);
void delete_all(Stack &s, const Stack_entry &entry);

int main(void) {
  Stack test;
  Stack_entry tmp;

  test.push(1);
  test.push(2);
  test.push(1);

  delete_all(test, 1);

  while (!test.empty()) {
    test.top(tmp);
    test.pop();
    std::cout << tmp << '\n';
  }

  return 0;
}

bool full(Stack &s) {
  try {
    s.push(1);
    s.pop();
  } catch (...) {
    return true;
  }
  return false;
}

Error_code pop_top(Stack &s, Stack_entry &entry) {
  Error_code outcome = s.top(entry);
  if (outcome != 0) { return outcome; }
  return s.pop();
}

void clear(Stack &s) {
  while (!s.empty()) {
    s.pop();
  }
}

int size(const Stack &s) {
  Stack tmp = s;
  int count = 0;

  while (!tmp.empty()) {
    tmp.pop();
    count++;
  }

  return count;
}

void delete_all(Stack &s, const Stack_entry &entry) {
  Stack_entry top;
  Stack tmp;

  while (!s.empty()) {
    s.top(top);
    s.pop();
    if (top != entry) {
      tmp.push(top);
    }
  }

  while (!tmp.empty()) {
    tmp.top(top);
    tmp.pop();
    s.push(top);
  }
}
