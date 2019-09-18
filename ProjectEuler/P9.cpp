//
//  P9.cpp
//  ProjectEuler
//
//  Created by Sid on 20/01/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

/*
 
 
 A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 a2 + b2 = c2
 
 For example, 32 + 42 = 9 + 16 = 25 = 52.
 
 There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 Find the product abc.
 */

#include <cmath>
#include <cstdio>
#include <cassert>

#define SQ(x) (x * x)

static bool isPythTrip(int a, int b, int c)
{
 if (SQ(a)+SQ(b)==SQ(c)) {
  return true;
 } else if (SQ(a)+SQ(c)==SQ(b)) {
  return true;
 } else if (SQ(c)+SQ(b)==SQ(a)) {
  return true;
 }
 return false;
}

static int pythTripletProduct(int n)
{
 for (int c = n-1; c; --c) {
  for (int b = 1; b < c; ++b) {
   for (int a = 0; a < b; ++a) {
	if ((a+b+c == n) && isPythTrip(a, b, c)) {
     return a*b*c;
    }
   }
  }
 }
 return -1;
}

int P9_Main()
{
 assert(pythTripletProduct(12) == 60);
 printf("%d\n", pythTripletProduct(1000));
 return 0;
}
