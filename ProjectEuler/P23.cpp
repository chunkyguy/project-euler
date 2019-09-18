//
//  P23.cpp
//  ProjectEuler
//
//  Created by Sid on 29/05/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

/**
 Non-abundant sums
 
 A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 
 A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
 
 As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
 
 Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
 
 */

#include <cassert>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <unordered_set>

#include "Timer.h"

/* all number above this are guaranteed to be written as sum of two abundants */
const int kMinAbundantSum = 28123;

bool IsAbundant(const int &num)
{
    int sum = 0;
    for (int i = 1; i < num; ++i) {
        if (num % i == 0) {
            sum += i;
        }
    }

    return sum > num;
}

bool IsSumOfNums(const int &num, const std::vector<int> & nums)
{
    for (std::vector<int>::const_iterator ita = nums.begin();
         ita != nums.end(); ++ita) {
        
        for (std::vector<int>::const_iterator itb = std::next(ita);
             itb != nums.end(); ++itb) {
            
            if (*ita + *itb == num) {
                return true;
            }
        }
    }

    return false;
}

int P23_Main()
{
    assert(IsAbundant(28) == false);
    for (int i = 0; i < 12; ++i) {
        assert(IsAbundant(i) == false);
    }
    assert(IsAbundant(12) == true);

    /* find all abundant numbers */
    std::vector<int> abundants;
    for (int i = 12; i <= kMinAbundantSum; ++i) {
        if (IsAbundant(i)) {
            abundants.push_back(i);
        }
    }
    
    //    std::copy(abundants.begin(), abundants.end(), std::ostream_iterator<int>(std::cout, " "));
    // std::cout << abundants.size() << std::endl;
    
    /* find all abundants sums */
    std::unordered_set<int> abundantSums;
    TimerMS timer("P23: ");
    for (std::vector<int>::const_iterator ita = abundants.begin(); ita != abundants.end(); ++ita) {
        for (std::vector<int>::const_iterator itb = ita; itb != abundants.end(); ++itb) {
            int sum = *ita + *itb;
            if (sum <= kMinAbundantSum) {
                abundantSums.insert(sum);
            } else {
                break;
            }
        }
    }
    
    /* sum all non abundant sums */
    int sum = 0;
    for (int i = 0; i <= kMinAbundantSum; ++i) {
        if (abundantSums.find(i) == abundantSums.end()) {
            sum += i;
        }
    }
    std::cout << sum << std::endl;
    
    

    //    std::copy(abundantSums.begin(), abundantSums.end(), std::ostream_iterator<int>(std::cout, " "));
    
    return 0;
}