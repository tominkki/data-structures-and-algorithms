#include "life.h"

Life::Life(int rows, int columns): maxrow(rows), maxcol(columns) {}

int Life::neighbor_count(int row, int col) {
  int count = 0;
  int i = row  == 1 ? 1 : row - 1;
  
  for (i; i <= row + 1 && row <= maxrow; i++) {
    
    int j = col == 1 ? 1 : col - 1;
    for (j; j <= col + 1 && col <= maxcol; j++) {
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
          new_grid[row][col] = grid[row][col]; 
          break;
        }
        case 3: {
          new_grid[row][col] = 1;
          break;
        }
        default: {
          new_grid[row][col] = 0;
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
  std::vector<int> tmp = {};

  for (int i = 0; i <= maxcol + 1 ; i++) {
    tmp.push_back(0);
  }

  for (int i = 0; i <= maxrow + 1; i++) {
    grid.push_back(tmp);
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
