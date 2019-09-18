//
//  P6.cpp
//  ProjectEuler
//
//  Created by Sid on 16/01/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

/*
 
 The sum of the squares of the first ten natural numbers is,
 12 + 22 + ... + 102 = 385
 
 The square of the sum of the first ten natural numbers is,
 (1 + 2 + ... + 10)2 = 552 = 3025
 
 Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
 
 Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 */

#include <iostream>
#include <cassert>

static unsigned int square_of_sum(const unsigned int num)
{
 int sum = 0;
 for (int i = 1; i <= num; ++i) {
  sum += i;
 }
 return sum * sum;
}

static unsigned int sum_of_squares(const unsigned int num)
{
 int sum = 0;
 for (int i = 1; i <= num; ++i) {
  sum += (i*i);
 }
 return sum;
}

int P6_Main()
{
 assert(square_of_sum(10) - sum_of_squares(10) == 2640);
 std::cout << square_of_sum(100) - sum_of_squares(100) << std::endl;
 return 0;
}
