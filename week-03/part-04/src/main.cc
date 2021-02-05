#include <iostream>
#include <stack>

int main(void) {
  std::stack<int> nums;

  std::cout << "Input sequence of integers of increasing value.\n"
    << "Input terminates as soon as an integer that does not exceed its predecessor in value is read.\n>>> ";

  while (true) {
    int tmp;
    std::cin >> tmp;

    if (!nums.empty() && tmp <= nums.top()) { break; }
    nums.push(tmp);
  }

  std::cout << "\nIntegers in decreasing order:\n";
  while (!nums.empty()) {
    std::cout << nums.top() << " ";
    nums.pop();
  }

  std::cout << '\n';
  return 0;
}
