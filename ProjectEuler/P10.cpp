//
//  P10.cpp
//  ProjectEuler
//
//  Created by Sid on 21/01/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

/*
 The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 
 Find the sum of all the primes below two million.
 */
#include <cassert>
#include <cmath>
#include <iostream>

template <typename T>
static bool is_prime(const T num)
{
 for (T n = 2; n <= sqrt(num); ++n) {
  if (num % n == 0) {
   return false;
  }
 }
 return (num <= 1)?false:true;
}

template<typename T>
static T sum_of_primes(const T num)
{
 T sum = 0;
 for (T n = 0; n < num; ++n) {
  if (is_prime(n)) {
   sum += n;
  }
 }
 return sum;
}

int P10_Main()
{
 assert(is_prime(0) == false);
 assert(is_prime(1) == false);
 assert(is_prime(2) == true);
 assert(is_prime(3) == true);
 assert(is_prime(23) == true);
 assert(sum_of_primes(10) == 17);
 std::cout << sum_of_primes(2000000L) << std::endl;
 return 0;
}
