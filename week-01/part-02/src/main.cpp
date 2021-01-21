#include "utility/utility.h"
#include "life/life.h"

int main(void) {
  int rows, columns = {};

  std::cout << "Set grid size for Life game (rows columns).\n";
  std::cin >> rows >> columns;
  Life game(rows, columns);
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
