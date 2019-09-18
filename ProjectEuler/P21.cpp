//
//  P21.cpp
//  ProjectEuler
//
//  Created by Sid on 26/05/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

/**
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
 * If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
 *
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The
 * proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
 *
 * Evaluate the sum of all the amicable numbers under 10000.
 *
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>
#include <set>
#include "Timer.h"

int DivisorSum(const int num)
{
    int sum = 0;
    for (int n = 1; n < num; ++n) {
        if ((num % n) == 0) {
            sum += n;
        }
    }
    return sum;
}

int AmicableNumbers(const int max)
{
    int *divSum = new int[max];
    std::set<int> amicables;
    
    for (int num = 0; num < max; ++num) {
        divSum[num] = DivisorSum(num);
    }

    for (int num = 0; num < max; ++num) {
        int dSum = divSum[num];
        if (dSum < max && divSum[dSum] == num && dSum != num) {
            amicables.insert(num);
            amicables.insert(dSum);
        }
    }
    
    delete [] divSum;
    
    //std::copy(amicables.begin(), amicables.end(), std::ostream_iterator<int>(std::cout, " "));
    
    return std::accumulate(amicables.begin(), amicables.end(), 0);
}

int P21_Main()
{
    assert(DivisorSum(220) == 284);
    assert(DivisorSum(284) == 220);
 
    TimerMS("P21: ");
    std::cout << AmicableNumbers(10000) << std::endl;
    
    return 0;
}