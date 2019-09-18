//
//  Timer.h
//  ProjectEuler
//
//  Created by Sid on 16/01/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#ifndef __ProjectEuler__Timer__
#define __ProjectEuler__Timer__

/** Log execution time of a block of code in nanoseconds and milliseconds
 * Just add a Timer object at the start of the code block.
 * Provide a prefix string about some context
 *
 * Example:
 * long LargestPrimeFactor(const long num)
 * {
 *  Timer t("LargestPrimeFactor:(" + std::to_string(num) + ") ");
 *	//stuff here..
 * }
 *
 * Output:
 * LargestPrimeFactor:(13195) 718315 ns 0ms
 */

#include <iostream>
#include <chrono>
#include <string>

class TimerNS {
public:
  TimerNS(const std::string &pre) :
  start(std::chrono::high_resolution_clock::now()),
  prefix(pre)
  {}
  
  ~TimerNS()
  {
    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
    std::chrono::nanoseconds dt = end - start;
    std::cout << prefix << dt.count() << " ns "    << std::endl;
  }
  
private:
  std::chrono::time_point<std::chrono::high_resolution_clock> start;
  std::string prefix;
};

#include <ctime>

class TimerMS {
public:
  TimerMS(const std::string &pre) :
  prefix(pre),
  start(clock())
  {}
  
  ~TimerMS()
  {
    std::cout << prefix << (clock() - start)/static_cast<double>(CLOCKS_PER_SEC)*1000.0 << " ms" << std::endl;
  }
  
private:
  std::string prefix;
  clock_t start;
};

#endif /* defined(__ProjectEuler__Timer__) */
