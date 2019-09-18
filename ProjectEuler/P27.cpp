//
//  P27.cpp
//  ProjectEuler
//
//  Created by Sid on 02/11/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

/*
 
 
 Euler discovered the remarkable quadratic formula:
 
 n² + n + 41
 
 It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41² + 41 + 41 is clearly divisible by 41.
 
 The incredible formula  n² − 79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, −79 and 1601, is −126479.
 
 Considering quadratics of the form:
 
 n² + an + b, where |a| < 1000 and |b| < 1000
 
 where |n| is the modulus/absolute value of n
 e.g. |11| = 11 and |−4| = 4
 
 Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.

 */
#include <cassert>
#include <cmath>
#include <set>
#include <iostream>

class PrimeNumberCache {
public:
    PrimeNumberCache() :
    lastLookup(0)
    {}

    bool operator()(const int n)
    {
        /* check all lesser numbers for prime */
        while (lastLookup <= n) {
            if (IsPrime(lastLookup)) {
                primes.insert(lastLookup);
            }
            lastLookup++;
        }
        
        return (primes.find(n) != primes.end());
    }

private:

    bool IsPrime(const int n)
    {
        if (n < 2) {
            return false;
        }
        
        int sqrtn = sqrt(n);
        for (int i = 2; i <= sqrtn; ++i) {
            if ((n % i) == 0) {
                return false;
            }
        }
        return true;
    }

    int lastLookup;
    std::set<int> primes;
};

PrimeNumberCache pnc;

int QuadraticPrimes(const int a, const int b)
{
    int n = 0;
    while (pnc(n*n + a*n + b)) {
        n++;
    }
    return n;
}

int CoefProduct(const int range)
{
    int maxb = 0;
    int maxa = 0;
    int maxPrimes = 0;
    for (int b = -range+1; b < range; ++b) {
        for (int a = -range+1; a < range; ++a) {
            int primes = QuadraticPrimes(a, b);
            if (primes > maxPrimes) {
                maxPrimes = primes;
                maxa = a;
                maxb = b;
            }
        }
    }
    
    return maxa * maxb;
}

int P27_Main()
{
    assert(pnc(0) == false);
    assert(pnc(1) == false);
    assert(pnc(2) == true);
    assert(pnc(3) == true);
    assert(pnc(4) == false);
    assert(pnc(5) == true);
    assert(pnc(6) == false);
    assert(pnc(7) == true);
    assert(pnc(8) == false);
    assert(pnc(9) == false);
    assert(pnc(10) == false);
    assert(QuadraticPrimes(1, 41) == 40);
    assert(QuadraticPrimes(-79, 1601) == 80);
    std::cout << CoefProduct(1000) << std::endl;
    return 0;
}