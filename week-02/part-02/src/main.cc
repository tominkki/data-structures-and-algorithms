#include "utility/utility.h"
#include "life/life.h"

int main(void) {
  Life* game = new Life();
  game->instructions();
  game->initialize();
  game->print();
  std::cout << "Continue viewing new generations?\n";

  while (utils::user_says_yes()) {
    game->update();
    game->print();
    std::cout << "Continue viewing new generations?\n";
  }

  return 0;
}
