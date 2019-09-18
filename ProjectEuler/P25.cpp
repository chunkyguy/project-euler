//
//  P25.cpp
//  ProjectEuler
//
//  Created by Sid on 19/10/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

/*
 1000-digit Fibonacci number
 
 The Fibonacci sequence is defined by the recurrence relation:
 
 Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
 
 Hence the first 12 terms will be:
 
 F1 = 1
 F2 = 1
 F3 = 2
 F4 = 3
 F5 = 5
 F6 = 8
 F7 = 13
 F8 = 21
 F9 = 34
 F10 = 55
 F11 = 89
 F12 = 144
 
 The 12th term, F12, is the first term to contain three digits.
 
 What is the first term in the Fibonacci sequence to contain 1000 digits?
 */

#include <cassert>
#include <iostream>
#include <map>
#include <list>
#include "Utilities/BigInt.h"

#define ENABLE_DEBUG
#define ENABLE_LOOKUP

//class BigInt {
//public:
//    BigInt(int num = 0)
//    {
//        while (num) {
//            int n = num % 10;
//            store_.push_front(n);
//            num /= 10;
//        }
//    }
//    
//    friend BigInt operator+(const BigInt &a, const BigInt &b);
//    friend std::ostream &operator<<(std::ostream &os, const BigInt &bInt);
//    friend bool operator==(const BigInt &a, const BigInt &b);
//    
//    std::size_t Digits() const
//    {
//        return store_.size();
//    }
//
//private:
//    std::list<int> store_;
//};
//
//bool operator==(const BigInt &a, const BigInt &b)
//{
//    return (a.store_ == b.store_);
//}
//
//BigInt operator+(const BigInt &a, const BigInt &b)
//{
//    BigInt output;
//    std::list<int>::const_reverse_iterator aIt = a.store_.rbegin();
//    std::list<int>::const_reverse_iterator bIt = b.store_.rbegin();
//    int c = 0;
//    
//    for (; (aIt != a.store_.rend()) && (bIt != b.store_.rend()); ++aIt, ++bIt) {
//        int z = *aIt + *bIt + c;
//        int n = z % 10;
//        c = z / 10;
//        output.store_.push_front(n);
//    }
//    
//    for (; aIt != a.store_.rend(); ++aIt) {
//        int z = *aIt + c;
//        int n = z % 10;
//        c = z / 10;
//        output.store_.push_front(n);
//    }
//
//    for (; bIt != b.store_.rend(); ++bIt) {
//        int z = *bIt + c;
//        int n = z % 10;
//        c = z / 10;
//        output.store_.push_front(n);
//    }
//    
//    if (c) {
//        output.store_.push_front(c);
//    }
//
//    return output;
//}
//
//std::ostream &operator<<(std::ostream &os, const BigInt &bInt)
//{
//    std::copy(bInt.store_.begin(), bInt.store_.end(), std::ostream_iterator<int>(os));
//    return os;
//}

#ifdef ENABLE_LOOKUP
typedef BigInt<int> Fibvalue;
//typedef long Fibvalue;
std::map<int, Fibvalue> cachedFib;
#endif

#ifdef ENABLE_DEBUG
int lookups = 0;
int process = 0;
#endif

Fibvalue Fibonacci(const int num)
{
    Fibvalue fib = Fibvalue(1);
    
#ifdef ENABLE_LOOKUP
    // look up
    std::map<int, Fibvalue>::const_iterator it = cachedFib.find(num);
    if (it != cachedFib.end()) {
        fib = it->second;
#ifdef ENABLE_DEBUG
        lookups++;
#endif
    } else if (num > 2) {
#endif
        // calculate
        fib = Fibonacci(num - 1) + Fibonacci(num - 2);
#ifdef ENABLE_DEBUG
        process++;
#endif
#ifdef ENABLE_LOOKUP
        // store
        cachedFib[num] = fib;
    }
#endif
    
    return fib;
}

int Digits(std::size_t num)
{
    int digits = 0;
    while (num) {
        num /= 10;
        digits++;
    }
    return digits;
}

std::size_t Digits(const BigInt<int> &num)
{
    return num.Digits();
}

int TermWithDigits(const int digits)
{
    int num = 0;
    while (Digits(Fibonacci(num)) != digits) {
        num++;
    }
    return num;
}

int P25_Main()
{
    assert(Digits(5) == 1);
    assert(Digits(5) != 2);
    assert(Digits(21) == 2);
    assert(Digits(27) != 1);
    assert(Digits(27) != 3);
    
    assert(Fibonacci(1) == 1);
    assert(Fibonacci(2) == 1);
    assert(Fibonacci(12) == 144);
    assert(TermWithDigits(3) == 12);
    
        std::cout << TermWithDigits(1000) << std::endl;

    //        std::cout << TermWithDigits(1000) << std::endl;
   
#ifdef ENABLE_DEBUG
    std::cout << "Process: " << process << std::endl;
#ifdef ENABLE_LOOKUP
    std::cout << "Lookups: " << lookups << std::endl;
    std::cout << "Cache size: " << cachedFib.size() << std::endl;
#endif
#endif

    return 0;
}
