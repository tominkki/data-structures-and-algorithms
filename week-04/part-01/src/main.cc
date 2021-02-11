#include "./stack/stack.h"

Error_code copy_stack(Stack &dest, const Stack &source);

int main(void) {
  Stack dst, src;

  for (int i = 0; i < 100; i++) {
    src.push(1);
  }

  src.copy_stack(dst);

  return 0;
}

/* a)
Error_code copy_stack(Stack &dest, Stack &source) {
  try {
    dest = source;
    return success;
  } catch (...) {
    return fatal;
  }
}

b)
Error_code copy_stack(Stack &dest, const Stack &source) {
  Stack tmp1, tmp2 = source;
  Stack_entry entry;

  try {
    while (!tmp2.empty()) {
      tmp2.top(entry);
      tmp1.push(entry);
      tmp2.pop();
    }

    while (!tmp1.empty()) {
      tmp1.top(entry);
      dest.push(entry);
      tmp1.pop();
    }

    return success;
  } catch (...) {
    return fatal;
  }
}
*/