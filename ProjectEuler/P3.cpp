//
//  P3.cpp
//  ProjectEuler
//
//  Created by Sid on 16/01/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//
/**
 The prime factors of 13195 are 5, 7, 13 and 29.
 
 What is the largest prime factor of the number 600851475143 ?
 */

#include <cassert>
#include <iostream>

#include <cmath>

/*find next prime number between (num, LONG_MAX] 
 * num is prime if there exists no number in range (num, sqrt(num)] that completely divides num
 */
static long next_prime(const long num)
{
 long n = num;
 while (++n) {
  bool prime = true;
  long sq = sqrt(n);
  for (long i = 2; prime && i <= sq; ++i) {
   if (n%i == 0) {
    prime = false;
   }
  }
  if (prime) {
   break;
  }
 }
 return n;
}

/*get largest prime factor for num*/
static long largest_prime(const long num)
{
 long max_factor = num;
 long i = 2; /*starting with lower primes as there are more primes at the starting of number system*/
 for (; max_factor > 2; ) {
  for (; i < max_factor; i = next_prime(i)) {
   if (max_factor%i == 0) { /*factor breaking at i*/
    long j = max_factor/i; /*max_factor = i * j */
    max_factor = (i > j) ? i : j; /*pick the next big factor between i and j to break next*/
	break;
   }
  }
  if (i == max_factor) { /*unbreakable factor found*/
   return max_factor;
  }
 }

 return max_factor; /*should be either 1 or 2*/
}

int P3_Main()
{
 assert(largest_prime(13195) == 29);
 std::cout << largest_prime(600851475143) << std::endl;
 return 0;
}
