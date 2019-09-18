//
//  P19.cpp
//  ProjectEuler
//
//  Created by Sid on 28/04/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

/*
 * You are given the following information, but you may prefer to do some research for yourself.
 *
 * 1 Jan 1900 was a Monday.
 * Thirty days has September,
 * April, June and November.
 * All the rest have thirty-one,
 * Saving February alone,
 * Which has twenty-eight, rain or shine.
 * And on leap years, twenty-nine.
 * A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
 *
 * How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
 */


#include <cassert>
#include <iostream>

class Cal {
public:

  /* by default ignore weekday - set it as sunday */
  Cal(const int m, const int y, const int d = 0) :
  m_(m), y_(y), d_(d)
  {
    assert(m_ > 0 && m_ <= 12);
    assert(d < 7);
  }
  
  int Days() const
  {
    if (m_ == 2) {
      return (IsLeap() ? 29 : 28);
    } else if (m_ == 4 || m_ == 6 || m_ == 9 || m_ == 11) {
      return 30;
    }
    return 31;
  }
  
  Cal operator++()
  {
    d_ += Days();
    d_ %= 7;
    m_++;
    if (m_ == 13) {
      m_ = 1;
      y_++;
    }
    return Cal(m_, y_, d_);
  }
  
  bool operator<(const Cal &other)
  {
    if (y_ == other.y_) {
      return m_ < other.m_;
    }
    return y_ < other.y_;
  }
  
  bool operator==(const Cal &other)
  {
    return (y_ == other.y_ && m_ && other.m_);
  }
  
  /* [0, 6] : [Sunday, Saturday] */
  int WeekDay() const
  {
    return d_;
  }
  
  void Print() const
  {
    std::cout << "[" << m_ << "," << y_ << "]: " << d_ << std::endl;
  }

private:
  
  bool IsLeap() const
  {
    if (((y_%4 == 0) && (y_%100 != 0)) || (y_%400 == 0)) {
      return true;
    }
    return false;
  }

  int m_;
  int y_;
  int d_;
};

int P19_Main()
{
  assert(Cal(2, 2014).Days() == 28); /* NOT leap year: not divisible by 4 */
  assert(Cal(2, 2016).Days() == 29); /* leap year: divisible by 4 */
  assert(Cal(2, 1900).Days() == 28); /* NOT leap year: not divisible by 400 */
  assert(Cal(2, 2000).Days() == 29); /* leap year: divisible by 400 */

  int count = 0;
  Cal rangeStart(1, 1901);
  Cal rangeEnd(1, 2001);
  Cal startDate(1, 1900, 1); /* Jan 01, 1900 is monday */
  
  for (; startDate < rangeStart; ++startDate) {
  }
  
  for (;startDate < rangeEnd; ++startDate) {
    if (startDate.WeekDay() == 0) {
      count++;
    }
  }
  
  std::cout << count << std::endl;
  
  return 0;
}
