#include "life.h"

int Life::neighbor_count(int row, int col) {
  int i, j;
  int count = 0;
  for (i = row - 1; i <= row + 1; i++) {
    for (j = col - 1; j <= col + 1; j++) {
      count += grid[i][j];
    }
  }
  count -= grid[row][col];
  return count;
}

void Life::update(void) {
  int row, col;
  int new_grid[maxrow + 2][maxcol + 2];

  for (row = 1; row <= maxrow; row++) {
    for (col = 1; col <= maxcol; col++) {
      switch (neighbor_count(row, col)) {
        case 2: {
          new_grid[row][col] = grid[row][col];  //  Status stays the same.
          break;
        }
        case 3: {
          new_grid[row][col] = 1;                //  Cell is now alive.
          break;
        }
        default: {
          new_grid[row][col] = 0;                //  Cell is now dead.
        }
      }
    }
  }

  for (row = 1; row <= maxrow; row++) {
    for (col = 1; col <= maxcol; col++) {
      grid[row][col] = new_grid[row][col];
    }
  }
}


void Life::instructions(void) {
  std::cout << "Welcome to Conway's game of Life." << std::endl
    << "This game uses a grid of size "
    << maxrow << " by " << maxcol << " in which" << std::endl
    << "each cell can either be occupied by an organism or not." << std::endl
    << "The occupied cells change from generation to generation" << std::endl
    << "according to the number of neighboring cells which are alive." << std::endl;
}


void Life::initialize(void) {
  int row, col;

  for (row = 0; row <= maxrow+1; row++) {
    for (col = 0; col <= maxcol+1; col++) {
      grid[row][col] = 0;
    }
  }

  std::cout << "List the coordinates for living cells." << std::endl
    << "Terminate the list with the special pair -1 -1" << std::endl;

  std::cin >> row >> col;

  while (row != -1 || col != -1) {
    if (row >= 1 && row <= maxrow) {
      if (col >= 1 && col <= maxcol) {
        grid[row][col] = 1;
      } else {
        std::cout << "Column " << col << " is out of range." << std::endl;
      }
    } else {
      std::cout << "Row " << row << " is out of range." << std::endl;
    }
    std::cin >> row >> col;
  }
}


void Life::print(void) {
  int row, col;
  std::cout << "\nThe current Life configuration is:" << std::endl;
  for (row = 1; row <= maxrow; row++) {
    for (col = 1; col <= maxcol; col++) {
      if (grid[row][col] == 1) {
        std::cout << '*';
      } else {
        std::cout << ' ';
      }
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}