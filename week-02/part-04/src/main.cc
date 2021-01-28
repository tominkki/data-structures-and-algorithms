#include "utility/utility.h"
#include "life/life.h"

int main(void) {
  Life* game = new Life();
  game->instructions();
  game->initialize();
  game->print();
  game->loop();
  game->save_state();

  return 0;
}
