#include "utility/utility.h"
#include "life/life.h"

int main(void) {
  Life game;
  game.instructions();
  game.initialize();
  game.print();
  std::cout << "Continue viewing new generations? " << std::endl;

  while (user_says_yes()) {
    game.update();
    game.print();
    std::cout << "Continue viewing new generations? " << std::endl;
  }

  return 0;
}
