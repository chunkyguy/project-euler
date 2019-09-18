//
//  P7.cpp
//  ProjectEuler
//
//  Created by Sid on 17/01/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

/*
 
 By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 
 What is the 10 001st prime number?
 */

#include <iostream>
#include <cassert>
#include <cmath>

static long next_prime(const long num)
{
 long n = num;
 while (++n) {
  long sq = sqrt(n);
  long i = 2;
  bool prime = true;
  for (;prime && i <= sq; ++i) {
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

static long prime_at(const int index)
{
 long prime = 1;
 for (int i = 0; i < index; ++i) {
  prime = next_prime(prime);
 }
 return prime;
}

int P7_Main()
{
 assert(prime_at(6) == 13);
 std::cout << prime_at(10001) << std::endl;
 return 0;
}
