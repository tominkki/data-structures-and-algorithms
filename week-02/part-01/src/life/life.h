#pragma once

#include <iostream>
#include <vector>
#include <sstream>

class Life {
   public:
      Life();
      void initialize(void);
      void print(void);
      void update(void);
      void instructions(void);
   private:
      int _maxrow;
      int _maxcol;
      std::vector<std::vector<int>> _grid;  
      int neighbor_count(int row, int col);
      void set_grid(int rows, int columns);
};
