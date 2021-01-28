#include "life.h"

Life::Life() {}

void Life::set_grid(int rows, int columns) {
  this->_maxrow = rows;
  this->_maxcol = columns;
}

void Life::read_state(std::istream &stream) {
  int row = 0, col;
  std::string line;

  while (true) {
    col = 0;
    std::getline(stream, line);

    if (line.length() == 0) { break; }

    std::stringstream ss(line);
    while (ss.good()) {
      this->_grid[row][col] = ss.get() == '*' ? 1 : 0;
      col++;
    }
    row++;
  }
}

void Life::init_grid(void) {  

  std::cout << "Set initial state, living cells as * and dead cells as space.\n"
    << "Terminate with empty row\n";

  std::cin.ignore(INT64_MAX, '\n');

  this->read_state(std::cin);
}

void Life::load_grid(void) {
  std::string fname, comment;
  
  std::cout << "Enter filename: ";
  std::cin >> fname;

  std::ifstream file(fname);

  if (file.is_open()) {
    std::getline(file, comment);
    this->read_state(file);
  } else {
    std::cout << "Fuckken hell!\n";
  }

  file.close();
}

void Life::instructions(void) {
  int rows, columns;

  std::cout << "Welcome to Conway's game of Life.\n"
    << "This game uses a grid in which each cell can either be occupied by an organism or not.\n"
    << "The occupied cells change from generation to generation according to the number of neighboring cells which are alive.\n"
    << "Set grid size for game (rows columns).\n";

  std::cin >> rows >> columns;
  this->set_grid(rows, columns);
}

void Life::initialize(void) {

  std::vector<int> tmp = {};

  for (int i = 0; i <= this->_maxcol; i++) {
    tmp.push_back(0);
  }

  for (int i = 0; i <= this->_maxrow; i++) {
    this->_grid.push_back(tmp);
  }

  std::cout << "Do you want to load initial state from file";

  if (utils::user_says_yes()) {
    this->load_grid();
  } else {
    this->init_grid();
  } 
}

int Life::neighbor_count(int row, int col) {
  int count = 0;
  int i = row == 0 ? 0 : row - 1;
  
  for (i; i <= row + 1 && i <= this->_maxrow; i++) {
    int j = col == 0 ? 0 : col - 1;
    for (j; j <= col + 1 && j <= this->_maxcol; j++) {
      count += this->_grid[i][j];
    }
  }
  count -= this->_grid[row][col];
  return count;
}

void Life::update(void) {
  int row, col;
  int new_grid[this->_maxrow ][this->_maxcol];

  for (row = 0; row < this->_maxrow; row++) {
    for (col = 0; col < this->_maxcol; col++) {
      switch (neighbor_count(row, col)) {
        case 2: {
          new_grid[row][col] = this->_grid[row][col]; 
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

  for (row = 0; row < this->_maxrow; row++) {
    for (col = 0; col < this->_maxcol; col++) {
      this->_grid[row][col] = new_grid[row][col];
    }
  }
}

void Life::print(void) {
  int row, col;
  std::cout << "\nThe current Life configuration is:\n";
  for (row = 0; row < this->_maxrow; row++) {
    for (col = 0; col < this->_maxcol; col++) {
      if (this->_grid[row][col] == 1) {
        std::cout << '*';
      } else {
        std::cout << ' ';
      }
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}
