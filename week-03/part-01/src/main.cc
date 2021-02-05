#include <iostream>
#include <stack>
/* A)
int main(void) {
  int n;
  double item;
  std::stack<double> numbers;

  std::cout << " Type in an integer n followed by n decimal numbers.\n"
    << " The numbers will be printed in reverse order.\n";
  std::cin  >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> item;
    numbers.push(item);
  }

  std::cout << "\n\n";
  while (!numbers.empty()) {
    std::cout << numbers.top() << " ";
    numbers.pop();
  }
  std::cout << '\n';

  return 0;
}

B)

int main(void) {
  char c;
  std::stack<char> line;

  std::cout << "Type word and it will be printed in reverse order.\n";

  while (std::cin.peek() != '\n') {
    std::cin >> c;
    line.push(c);
  }

  std::cout << "\n\n";
  while (!line.empty()) {
    std::cout << line.top();
    line.pop();
  }
  std::cout << '\n';

  return 0;
}

C)
*/

bool isPalindrome(std::stack<char>& word) {
  std::stack<char> reverse, tmp = word;
  int mid = word.size() / 2;

  while (!tmp.empty()) {
    reverse.push(tmp.top());
    tmp.pop();
  }

  tmp = word;
  for (int i = 0; i <= mid; i++) {
    if (tmp.top() != reverse.top()) {
      return false;
    }
    tmp.pop();
    reverse.pop();
  }

  return true;
}

int main(void) {
    char c;
  std::stack<char> line;

  std::cout << "Type word and it will be printed in reverse order.\n";

  while (std::cin.peek() != '\n') {
    std::cin >> c;
    line.push(c);
  }

  std::string tmp = isPalindrome(line) ? "Input is palindrome.\n" : "Input is not palindrome.\n";

  std::cout << "\n\n" << tmp << "\n" ;

  while (!line.empty()) {
    std::cout << line.top();
    line.pop();
  }
  std::cout << '\n';

  return 0;
}
