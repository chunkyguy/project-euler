//
//  P26.cpp
//  ProjectEuler
//
//  Created by Sid on 28/10/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

/*
 A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:
 
 1/2	= 	0.5
 1/3	= 	0.(3)
 1/4	= 	0.25
 1/5	= 	0.2
 1/6	= 	0.1(6)
 1/7	= 	0.(142857)
 1/8	= 	0.125
 1/9	= 	0.(1)
 1/10	= 	0.1
 Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.
 
 Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
 */

#include <iostream>
#include <cassert>
#include <cmath>
#include <set>

int DigitCount(int num)
{
    int count = 0;
    while (num) {
        num /= 10;
        count++;
    }
    return count;
}

size_t UnitFractions(const int divisor)
{
    int dividend = pow(10, DigitCount(divisor));
    int remainder = 0;
    std::set<int> usedRemainders;
    bool recurrence = false;
    
    while (dividend) {
        
        if (dividend < divisor) {
            dividend *= 10;
            continue;
        }
        
        remainder = dividend % divisor;
        
        if (!remainder) {
            break;
        }
        
        if (usedRemainders.insert(remainder).second == false) {
            recurrence = true;
            break;
        }
        
        dividend = remainder * 10;
    }

    size_t cycle = (recurrence ? usedRemainders.size() : 0);
    
    // std::cout << divisor << ": [" << cycle << "] recurrences" << std::endl;
    
    return cycle;
}

int P26_Main()
{
    assert(DigitCount(5) == 1);
    assert(DigitCount(27) == 2);
    assert(DigitCount(2127) == 4);
    
    assert(UnitFractions(2) == 0);
    assert(UnitFractions(3) == 1);
    assert(UnitFractions(4) == 0);
    assert(UnitFractions(5) == 0);
    assert(UnitFractions(6) == 1);
    assert(UnitFractions(7) == 6);
    assert(UnitFractions(8) == 0);
    assert(UnitFractions(9) == 1);
    assert(UnitFractions(10) == 0);
    
    size_t maxReccurence = 0;
    int maxNum = 0;
    
    for (int i = 2; i < 1000; ++i) {
        size_t recurrence = UnitFractions(i);
        if (recurrence > maxReccurence) {
            maxReccurence = recurrence;
            maxNum = i;
        }
    }
    
    std::cout << maxNum << " [" << maxReccurence << "] recurrences" << std::endl;
    
    return 0;
}
