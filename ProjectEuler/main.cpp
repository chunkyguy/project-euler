//
//  main.cpp
//  ProjectEuler
//
//  Created by Sid on 16/01/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//
#include <iostream>

// eg. int P21_Main();
#define Problem(x) P ## x ## _Main()

extern int Problem(29);

int main()
{
    int exit = Problem(29);
    std::cout << "exit main(" << exit << ")" << std::endl;
    return exit;
}

