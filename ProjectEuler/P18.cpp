//
//  P18.cpp
//  ProjectEuler
//
//  Created by Sid on 27/04/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

/*
 * By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
 *
 * 3
 * 7 4
 * 2 4 6
 * 8 5 9 3
 *
 * That is, 3 + 7 + 4 + 9 = 23.
 */


#include <cassert>
#include <cstring>
#include <iostream>

const char *testCaseSmall =
"3\n"
"7 4\n"
"2 4 6\n"
"8 5 9 3\n";

const char *testCaseBig =
"75\n"
"95 64\n"
"17 47 82\n"
"18 35 87 10\n"
"20 04 82 47 65\n"
"19 01 23 75 03 34\n"
"88 02 77 73 07 63 67\n"
"99 65 04 28 06 16 70 92\n"
"41 41 26 56 83 40 80 70 33\n"
"41 48 72 33 47 32 37 16 94 29\n"
"53 71 44 65 25 43 91 52 97 51 14\n"
"70 11 33 28 77 73 17 78 39 68 17 57\n"
"91 71 52 38 17 14 91 43 58 50 27 29 48\n"
"63 66 04 68 89 53 67 30 73 16 69 87 40 31\n"
"04 62 98 27 23 09 70 98 73 93 38 53 60 04 23\n";

int Process(const char *testCase)
{
  int num = 0;
  int row = 0;
  int col = 0;
  int nodes[100][100] = {0};
  size_t len = strlen(testCase);
  
  for (int i = 0; i < len; ++i) {
    char ch = testCase[i];
    switch (ch) {
      case ' ':
        //        std::cout << "{" << row << ", " << col << "} = " << num << std::endl;
        nodes[row][col] = num;
        col++;
        num = 0;
        break;
        
      case '\n':
        //        std::cout << "{" << row << ", " << col << "} = " << num << std::endl;
        nodes[row][col] = num;
        row++;
        col = 0;
        num = 0;
        break;
        
      default:
        num = num*10 + (ch-'0');
        break;
    }
  }
  
  int max = -1;
  col = 2;
  for (int r = 1; r < row; ++r) {
    max = -1;
    for (int c = 0; c < col; ++c) {
      int v1 = -1;
      int v2 = -1;
      if (r-1 >= 0) {
        if (c >= 0) {
          v1 = nodes[r-1][c];
        }
        if (c-1 >= 0) {
          v2 = nodes[r-1][c-1];
        }
      }
			nodes[r][c] += (v1 > v2) ? v1 : v2;
      if (nodes[r][c] > max) {
        max = nodes[r][c];
      }
    }
    col++;
  }
  
  //  for (int r = 0; r < row; ++r) {
  //    for (int c = 0; c < col; ++c) {
  //      std::cout << nodes[r][c] << " ";
  //    }
  //    std::cout << std::endl;
  //  }
  return max;
}

int P18_Main()
{
  assert(Process(testCaseSmall) == 23);
  std::cout << Process(testCaseBig) << std::endl;

  return 0;
}
