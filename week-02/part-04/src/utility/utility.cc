#include "utility.h"

bool utils::user_says_yes(void) {
  int c;
  bool initial_response = true;

  do {
    if (initial_response) {
      std::cout << " (y,n)? " << std::flush;
    } else {
      std::cout << "Respond with either y or n: " << std::flush;
    }
      
    do {
      c = std::cin.get();
    } while (c == '\n' || c ==' ' || c == '\t');

    initial_response = false;
  } while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');
  return (c == 'y' || c == 'Y');
}
