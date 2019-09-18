//
//  P16.cpp
//  ProjectEuler
//
//  Created by Sid on 22/01/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//	2:57:04.4

/*
 
 215 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 
 What is the sum of the digits of the number 21000?
 */

#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>

struct Number {
  Number() :
  num("")
  {}

  Number(const char &ch) :
  num()
  {
    std::stringstream ss;
    ss << ch;
    ss >> num;
  }

  Number(const std::string &n) :
  num(n)
  {  }

  std::string num;
};

bool operator==(const Number &one, const Number &two)
{
  //std::cout << one.num << " == " << two.num << std::endl;
  return one.num == two.num;
}

Number operator+(const Number &one, const Number &two)
{
  //std::cout << one.num << " + " << two.num << std::endl;
  
  long i = one.num.length() - 1;
  long j = two.num.length() - 1;
  Number rsum;
  
  int c = 0;
  while ((i >= 0) || (j >= 0)) {
    int a = (i >= 0) ? one.num[i--] - '0' : 0;
    int b = (j >= 0) ? two.num[j--] - '0' : 0;
    int s = a+b+c;
    //std::cout << a << ' ' << b << ' ' << c << ' ' << s << std::endl;
    c = s/10;
    rsum.num += (s%10) + '0';
  }

  if (c) {
    rsum.num += c + '0';
  }
  
	//std::cout << " = " << rsum.num << std::endl;
  
  Number sum;
  for (std::string::reverse_iterator it = rsum.num.rbegin(); it != rsum.num.rend(); ++it) {
		sum.num += *it;
  }
  return sum;
}

Number operator<<(const Number &num, unsigned shift)
{
  //std::cout << num.num << " << " << shift << " = ";
  Number final = num;
  while (--shift) {
    final = final + final;
  }
  //std::cout << final.num << std::endl;
  return final;
}

Number SumOfDigits(const Number &num)
{
  Number sum;
  for (int i = 0; i < num.num.length(); ++i) {
    //std::cout << Number(num.num[i]).num << std::endl;
    sum = sum + Number(num.num[i]);
  }
  return sum;
}

template <typename T>
T Btoi(const char *num)
{
  T sum("0");
  int len = static_cast<int>(strlen(num));
  for (int i = 0; i < len; ++i) {
    sum = (sum + sum) + T(num[i]);
  }
  std::cout << std::endl;
  return sum;
}

class Binary {
public:
  Binary(const int n)
  {
    buffer_ = new char[n+1];
    buffer_[0] = '1';
    for (int i = 1; i < n; ++i) {
      buffer_[i] = '0';
    }
    buffer_[n] = '\0';
  }
  
  ~Binary()
  {
    delete [] buffer_;
  }
  
  const char *String() const
  {
    return buffer_;
  }
  
private:
  char *buffer_;
};

int P16_Main()
{
  assert(Number("12") + Number("45") == Number("57"));
  assert((Number("1") << 3) == Number("4"));
  assert((Number("1") << 16) == Number("32768"));
  assert(SumOfDigits(Number("32768")) == Number("26"));
  std::cout << SumOfDigits((Number("1") << 1001)).num << std::endl;
  // assert(Btoi<Number>(Binary(2).String()) == Number("4"));
  //  assert(Btoi<Number>(Binary(16).String()) == Number("32768"));
  return 0;
}