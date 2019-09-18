//
//  BigIntTests.cpp
//  ProjectEuler
//
//  Created by Sid on 17/12/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//
#include "BigInt.h"
#include "gtest/gtest.h"

TEST(BigIntTests, Add)
{
    EXPECT_EQ(BigInt<int>(48), BigInt<int>(21) + BigInt<int>(27));
    EXPECT_EQ(BigInt<int>(99) + BigInt<int>(1), BigInt<int>(100));
    EXPECT_EQ(BigInt<int>(100), BigInt<int>(1) + BigInt<int>(99));
    
    EXPECT_EQ(BigInt<int>(00), BigInt<int>(0));
    EXPECT_EQ(BigInt<int>(18) + BigInt<int>(3), BigInt<int>(21));
    EXPECT_EQ(BigInt<int>(9) + BigInt<int>(3), BigInt<int>(12));
    EXPECT_EQ(BigInt<int>(12) + BigInt<int>(3), BigInt<int>(15));
    EXPECT_EQ(BigInt<int>(3) + BigInt<int>(12), BigInt<int>(15));
}

TEST(BigIntTests, Arithmetic)
{
    BigInt<int> a(2127);
    BigInt<int> b(2127);
    
    EXPECT_EQ(a, b);
    
    BigInt<int> c(100);
    
    EXPECT_NE(a, c);
    
    BigInt<int> d(4254);
    EXPECT_NE(a, d);
    
    
    BigInt<int> e = a + b;
    EXPECT_EQ(e, d);
    
    b += a;
    EXPECT_EQ(b, e);
    
    BigInt<int> g = d - a;
    EXPECT_EQ(g, a);
    
    BigInt<int> f(99);
    --c;
    //std::cout << c << std::endl;
    EXPECT_EQ(c, f);
    
    BigInt<int> h(1234);
    BigInt<int> i(123);
    h /= 10;
    EXPECT_EQ(h, i);
    
    BigInt<int> j(3);
    i %= 10;
    EXPECT_EQ(i, j);
    
    BigInt<int> k(33);
    j *= 11;
    EXPECT_EQ(j, k);
    
    BigInt<int> l(10);
    EXPECT_NE(l, BigInt<int>(1));
}