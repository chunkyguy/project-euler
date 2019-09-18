//
//  P28.cpp
//  ProjectEuler
//
//  Created by Sid on 03/11/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//
/*
 
 
 Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:
 
 21 22 23 24 25
 20  7  8  9 10
 19  6  1  2 11
 18  5  4  3 12
 17 16 15 14 13
 
 It can be verified that the sum of the numbers on the diagonals is 101.
 
 What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?

 */
#include <cassert>
#include <iostream>

int Solve(int spiral)
{
    int sum = 0;
    while (spiral > 1) {
        int diff = spiral - 1;
        int num = spiral * spiral;
        for (int edge = 0; edge < 4; ++edge, num -= diff) {
            sum += num;
        }
        spiral -= 2;
    }
    return sum + 1;
}

int P28_Main()
{
    assert(Solve(5) == 101);
    std::cout << Solve(1001) << std::endl;
    return 0;
}
