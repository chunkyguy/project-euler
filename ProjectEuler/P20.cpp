//
//  P20.cpp
//  ProjectEuler
//
//  Created by Sid on 28/04/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

/*
 
 n! means n × (n − 1) × ... × 3 × 2 × 1
 
 For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
 and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 
 Find the sum of the digits in the number 100!
 
 */

#include <cassert>
#include <iostream>
#include <list>
#include "Utilities/BigInt.h"

/* Add digits of a int type */
template <typename INT>
INT Sum(const INT &num)
{
    INT s = 0;
    for (INT n = num; n != INT(0); n /= 10) {
        s += n%10;
    }
    return s;
}

template <typename INT>
INT Fact(const INT &num) {
    INT f = INT(1);
    for (INT i = num; i != INT(1); --i) {
        f *= i;
    }
    return f;
}

int P20_Main()
{
    assert(Sum(3628800) == 27);
    assert(Fact(10) == 3628800);
    
    assert(Fact(BigInt<int>(10)) == BigInt<int>(3628800));
    assert(Sum(BigInt<int>(3628800)) == BigInt<int>(27));
    
    //  std::cout << Fact(BigInt<int>(100)) << std::endl;
    std::cout << Sum(Fact(BigInt<int>(100))) << std::endl;
    
    std::cout << "--- P20 ---" << std::endl;
    return 0;
}
