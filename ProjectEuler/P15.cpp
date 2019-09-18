//
//  P15.cpp
//  ProjectEuler
//
//  Created by Sid on 21/01/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

/*
 
 
 Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
 
 How many such routes are there through a 20×20 grid?
 */

#include <cassert>
#include <iostream>

#include "Timer.h"

#define INDEX(c, r, w) ((r)*(w) + (c))

//void fill_grid_col(int *grid,
//                   const int grid_w, const int grid_h,
//                   const int eff_grid_w, const int eff_grid_h,
//                   int col)
//{
//  for (int row = eff_grid_h -1; row >= 0; --row) {
//    if (col == grid_w-1) {
//      grid[INDEX(col, row, grid_w)] = 1;
//    } else {
//      grid[INDEX(col, row, grid_w)] += grid[INDEX(col+1, row, grid_w)]; //add right
//      if (row < grid_h - 1) {
//        grid[INDEX(col, row, grid_w)] += grid[INDEX(col, row+1, grid_w)]; //add down
//      }
//    }
//  }
//}


template <typename T>
void fill_grid_row(T *grid,
                   const T grid_w, const T grid_h,
                   const T eff_grid_w, const T eff_grid_h,
                   T row)
{
  for (T col = eff_grid_w - 1; col >= 0; --col) {
    if (row == grid_h-1) {
      grid[INDEX(col, row, grid_w)] = 1;
    } else {
      grid[INDEX(col, row, grid_w)] += grid[INDEX(col, row+1, grid_w)]; //add down
      if (col < grid_w - 1) {
        grid[INDEX(col, row, grid_w)] += grid[INDEX(col+1, row, grid_w)]; //add right
      }
    }
    
    grid[INDEX(row, col, grid_w)] = grid[INDEX(col, row, grid_w)];
  }
}

template <typename T>
void print_grid(const T *grid, const T w, const T h)
{
  for (T i = 0; i < w*h; ++i) {
    std::cout << grid[i] << (((i+1)%w)?' ':'\n');
  }
  std::cout << std::endl;
}

template <typename T>
T visit_grid2(const T w, const T h)
{
  T *grid = new T[w*h];
  
  for (T i = 0; i < w*h; ++i) {
    grid[i] = 0;
  }
  
  T r = h - 1;
  T c = w - 1;
  T eff_w = w;
  T eff_h = h;
  while (r >= 0 || c >= 0) {
    fill_grid_row(grid, w, h, eff_w, eff_h, r);
    //print_grid(grid,w,h);
    //fill_grid_col(grid, w, h, eff_w, eff_h, c);
    //print_grid(grid,w,h);
    
    r--;
    c--;
    eff_h--;
    eff_w--;
  }
  
  print_grid(grid,w,h);
  
  T ret = grid[0];
  delete [] grid;
  return ret;
}

int P15_Main()
{
  assert(visit_grid2(3, 3) == 6);

  TimerMS t("P15: ");
  std::cout << visit_grid2<long long>(21, 21) << std::endl;

  return 0;
}
