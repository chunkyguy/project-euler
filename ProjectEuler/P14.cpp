//
//  P14.cpp
//  ProjectEuler
//
//  Created by Sid on 21/01/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

/* 28:03.7
 
 The following iterative sequence is defined for the set of positive integers:
 
 n → n/2 (n is even)
 n → 3n + 1 (n is odd)
 
 Using the rule above and starting with 13, we generate the following sequence:
 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 
 It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
 
 Which starting number, under one million, produces the longest chain?
 
 NOTE: Once the chain starts the terms are allowed to go above one million.
 */
#include <cassert>
#include <iostream>

template <typename T>
static const T collatz_count(const T start)
{
  T count = 0;
  for (T n = start; n != 1; count++) {
    if (n%2 == 0) {
      n = n/2;
    } else {
      n = 3*n+1;
    }
  }
  return count+1; /* because count isn't incremented when n = 1 */
}

int P14_Main()
{
  unsigned long max_value = 0;
  unsigned long max_num = 0;
  
  for (unsigned long i = 2L; i < 1000000L; ++i) {
    const unsigned long ret = collatz_count(i);
    if (ret > max_value) {
      max_value = ret;
      max_num = i;
    }
  }
  
  std::cout << max_num << std::endl;
  
  return 0;
}