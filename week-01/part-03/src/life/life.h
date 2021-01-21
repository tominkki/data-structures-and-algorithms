#pragma once

#include <iostream>
#include <vector>

class Life {
public:
   Life(int rows, int columns);
   void initialize(void);
   void print(void);
   void update(void);
   void instructions(void);
private:
   int maxrow;
   int maxcol;
   std::vector<std::vector<int>> grid;  
   int neighbor_count(int row, int col);
};
