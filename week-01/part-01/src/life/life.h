#pragma once

#include <iostream>

const int maxrow = 20, maxcol = 60;    //  grid dimensions

class Life {
public:
   void initialize(void);
   void print(void);
   void update(void);
   void instructions(void);
private:
   int grid[maxrow + 2][maxcol + 2];  //  allows for two extra rows and columns
   int neighbor_count(int row, int col);
};
