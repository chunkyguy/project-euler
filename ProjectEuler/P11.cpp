//
//  P11.cpp
//  ProjectEuler
//
//  Created by Sid on 21/01/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

/*
 
 In the 20×20 grid below, four numbers along a diagonal line have been marked in red.
 
 08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08
 49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
 81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65
 52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91
 22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80
 24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50
 32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70
 67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21
 24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72
 21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95
 78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92
 16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57
 86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58
 19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40
 04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66
 88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69
 04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36
 20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16
 20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54
 01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48
 
 The product of these numbers is 26 × 63 × 78 × 14 = 1788696.
 
 What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20×20 grid?
 */

#include <cassert>
#include <iostream>

/* direction flags */
#define kDir_PX (0x1 << 1)
#define kDir_PY (0x1 << 2)
#define kDir_NX (0x1 << 3)

/* Calculate index in the grid from colum and row */
#define kGetIndex(c, r, w) (r*w + c)

namespace {
  /* Calculate product of 4 or less ints from the grid in a specific direction */
  int product4(const int index,
               const unsigned int dir_bitflag,
               const int width,
               const int height,
               const int *grid)
  {
    int mul = 1;
    int eff_index = index;
    for (int i = 0; i < 4 && eff_index >= 0 && eff_index < (width * height); ++i) {
      mul *= grid[eff_index];
      
      if (dir_bitflag & kDir_PX) {
        eff_index += 1;
      }
      if (dir_bitflag & kDir_PY) {
        eff_index += width;
      }
      if (dir_bitflag & kDir_NX) {
        eff_index -= 1;
      }
    }
    return mul;
  }

  /* parse next valid int in the string. If string ends, return '\0' */
  const char *get_next_int(const char *str)
  {
    while (*str != '\0' && (*str < '0' || *str > '9')) {
      str++;
    }
    return str;
  }

  /* max multiplication of 4 or less ints in the grid along a direction */
  int max_mul_ordered(const unsigned int dir_bitflag,
                      const int width,
                      const int height,
                      const int *grid)
  
  {
    int max = -1;
    for (int i = 0; i < width * height; ++i) {
      int mul = product4(i, dir_bitflag, width, height, grid);
      assert(mul < 100000000);
      if (mul > max) {
        max = mul;
      }
    }
    return max;
  }
  
  /* max multiplication of 4 or less ints in the grid */
  int max_mul(const int width,
              const int height,
              const int *grid)
  {
    int max = -1;
    unsigned int dirs[] = {
      kDir_PX, kDir_PY, kDir_PX|kDir_PY, kDir_NX|kDir_PY
    };
    for (int i = 0; i < 4; ++i) {
      // test straight
      int mul = max_mul_ordered(dirs[i], width, height, grid);
      if (mul > max) {
        max = mul;
      }
    }
    return max;
  }
}

int P11_Main()
{
  const char *grid_str = "\
  08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08\
  49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00\
  81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65\
  52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91\
  22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80\
  24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50\
  32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70\
  67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21\
  24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72\
  21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95\
  78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92\
  16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57\
  86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58\
  19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40\
  04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66\
  88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69\
  04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36\
  20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16\
  20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54\
  01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48\
  ";
  int w = 20;
  int h = 20;
  int grid[400];
  int grid_count = 0;
  /* convert string to array of ints */
  const char *ch = grid_str;
  while (*(ch = get_next_int(ch)) != '\0') {
    int d = (*ch++ - '0');
    int u = (*ch++ - '0');
    grid[grid_count++] = d * 10 + u;
  }
  
  assert(grid_count == 400);
  assert(grid[0] == 8);
  assert(grid[grid_count-1] == 48);
  assert(product4(kGetIndex(8,6,w), kDir_PX|kDir_PY, w, h, grid) == 1788696);
  std::cout << max_mul(w, h, grid) << std::endl;
  return 0;
}
