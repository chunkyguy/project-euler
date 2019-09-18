//
//  P4.cpp
//  ProjectEuler
//
//  Created by Sid on 16/01/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

/**
 A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 
 Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <iostream>
#include <cassert>

static bool is_palin(const int num)
{
 int num_cpy = num;
 int rev = 0;
 while (num_cpy) {
  rev = rev * 10 + num_cpy%10;
  num_cpy /= 10;
 }
 return (rev == num);
}

static int max_palin(const int begin, const int end)
{
 int max = -1;
 for (int i = begin; i > end; --i) {
  for (int j = begin; j > end; --j) {
   int num = i * j;
   if (num > max && is_palin(num)) {
    //std::cout << i << " x " << j << " = " << num << std::endl;
    max = num;
   }
  }
 }
 return max;
}

int P4_Main()
{
 assert(max_palin(99,9) == 9009);
 std::cout << max_palin(999,99) << std::endl;
 return 0;
}
