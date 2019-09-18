//
//  P24.cpp
//  ProjectEuler
//
//  Created by Sid on 18/10/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

/**
 Lexicographic permutations
 
 A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
 
 012   021   102   120   201   210
 
 What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 
 */

#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

//#define BREAK_SIZE 1000000

void PrintList(const std::vector<int> &vec)
{
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout));
    std::cout << std::endl;
}

void PrintListOfList(const std::vector<std::vector<int>> &vec)
{
    std::for_each(vec.begin(), vec.end(), PrintList);
}

std::vector<int> FilterSource(std::vector<int> source, std::vector<int> working)
{
    std::sort(source.begin(), source.end());
    std::sort(working.begin(), working.end());
    
    std::vector<int> output;
    std::set_difference(source.begin(), source.end(), working.begin(), working.end(), std::back_inserter(output));
    
    return output;
}

void Permutations(std::vector<std::vector<int>> &output,
                  const std::vector<int> &source,
                  const std::vector<int> &working = {})
{
    if (source.size() == working.size()) {
        output.push_back(working);
#ifdef BREAK_SIZE
        if (output.size() == BREAK_SIZE) {
            PrintList(working);
            exit(0);
        }
#endif
        return;
    }

    std::vector<int> filteredSource = FilterSource(source, working);
    
    std::for_each(filteredSource.begin(), filteredSource.end(), [&](const int &val){
        std::vector<int> newWorking(working);
        newWorking.push_back(val);
        Permutations(output, source, newWorking);
    });
}

void testCase()
{
    std::vector<std::vector<int>> expected = {
        {0,1,2},
        {0,2,1},
        {1,0,2},
        {1,2,0},
        {2,0,1},
        {2,1,0}
    };

    std::vector<std::vector<int>> output;
    std::vector<int> source = {0, 1, 2};
    Permutations(output, source);
    
    assert(expected == output);
}

int P24_Main()
{
    //    testCase();
    
    std::vector<std::vector<int>> output;
    std::vector<int> source = {0,1,2,3,4,5,6,7,8,9};
    Permutations(output, source);
    
    return 0;
}
