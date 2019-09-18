//
//  P5.cpp
//  ProjectEuler
//
//  Created by Sid on 16/01/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

/*
 
 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 
 What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */

#include <iostream>
#include <cassert>

static int evenly_div(const int max)
{
 int num = 0;
 while (++num) {

  bool done = true;
  
  for (int i = 1; i <= max; ++i) {
   if (num%i != 0) {
    done = false;
    break;
   }
  }
  
  if (done) {
   break;
  }
 }

 return num;
}

int P5_Main()
{
 assert(evenly_div(10) == 2520);
 std::cout << evenly_div(20) << std::endl;
 return 0;
}