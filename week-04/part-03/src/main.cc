#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <algorithm>

bool is_prime(const int &num);
std::vector<int> find_divisors(const int &num);

int main(void) {
  std::vector<int> divisors;
  std::stack<int> prime_divisors;
  int num, tmp;

  std::cout << "Input number to find all of its prime divisors.\n>>>";
  std::cin >> num;

  divisors = find_divisors(num);
  
  while (!divisors.empty()) {
    tmp = divisors.back();
    divisors.pop_back();

    if (is_prime(tmp)) {
      prime_divisors.push(tmp);
    }
  }

  std::cout << num << " prime divisors:\n";

  while (!prime_divisors.empty()) {
    tmp = prime_divisors.top();
    prime_divisors.pop();

    std::cout << tmp << " ";
  }
  std::cout << '\n';

  is_prime(1);

  return 0;
}

bool is_prime(const int &num) {
  int i = 5;

  if (num <= 3) {
    return 1 < num;
  }

  if (num % 2 == 0 || num % 3 == 0) {
    return false;
  }

  while (std::pow(i, 2) <= num) {
    if (num % i == 0 || num % (i + 2) == 0) {
      return false;
    }
    i += 6;
  }

  return true;
}

std::vector<int> find_divisors(const int &num) {
  std::vector<int> divisors;

  for (int i = 1; i <= std::sqrt(num); i++) {
    if (num % i == 0) {
      if (num / i == i) {
        divisors.push_back(i);
      } else {
        divisors.push_back(i);
        divisors.push_back(num / i);
      }
    }
  }

  std::sort(divisors.begin(), divisors.end(), [](const int a, const int b) { return a > b; });

  return divisors;
}
