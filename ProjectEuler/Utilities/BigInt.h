//
//  BigInt.h
//  ProjectEuler
//
//  Created by Sid on 17/12/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

#ifndef __ProjectEuler__BigInt__
#define __ProjectEuler__BigInt__
#include <cassert>
#include <iostream>
#include <list>

/* forward decl for friend function
 * http://stackoverflow.com/questions/1297609/overloading-friend-operator-for-template-class
 */
template <typename INT> class BigInt;
template <typename INT> std::ostream &operator<<(std::ostream &os, const BigInt<INT> &);

template <typename INT>
class BigInt {
    
public:
    BigInt(const INT num = 0)
    {
        append(num);
    }
    
    void operator=(const INT num)
    {
        append(num);
    }
    
    BigInt<INT> operator+(const BigInt<INT> &other)
    {
        BigInt<INT> sum(0);
        typename std::list<INT>::const_reverse_iterator it1 = val_.rbegin();
        typename std::list<INT>::const_reverse_iterator it2 = other.val_.rbegin();
        
        INT carry = INT(0);
        for (; (it1 != val_.rend()) && (it2 != other.val_.rend()); ++it1, ++it2) {
            INT v = *it1 + *it2 + carry;
            sum.val_.push_front(v%INT(10));
            carry = v/INT(10);
        }
        
        if (it1 != val_.rend()) {
            for (; it1 != val_.rend(); ++it1) {
                INT v = *it1 + carry;
                sum.val_.push_front(v%INT(10));
                carry = v/INT(10);
            }
        }
        
        if (it2 != other.val_.rend()) {
            for (; it2 != other.val_.rend(); ++it2) {
                INT v = *it2 + carry;
                sum.val_.push_front(v%INT(10));
                carry = v/INT(10);
            }
        }
        
        if (carry != INT(0)) {
            sum.val_.push_front(carry);
        }
        
        return sum;
    }
    
    BigInt<INT> &operator+=(const BigInt<INT> &other)
    {
        *this = (*this + other);
        return *this;
    }
    
    BigInt<INT> operator-(const BigInt<INT> &other)
    {
        BigInt<INT> diff(0);
        typename std::list<INT>::const_reverse_iterator it1 = val_.rbegin();
        typename std::list<INT>::const_reverse_iterator it2 = other.val_.rbegin();
        
        bool borrow = false;
        for (; (it1 != val_.rend()) && (it2 != other.val_.rend()); ++it1, ++it2) {
            INT v;
            if (borrow) {
                v = (*it1 - INT(1)) - *it2;
            } else {
                v = *it1 - *it2;
            }
            if (v < INT(0)) {
                v += INT(10);
                borrow = true;
            } else {
                borrow = false;
            }
            diff.val_.push_front(v);
        }
        
        if (it1 != val_.rend()) {
            INT v;
            if (borrow) {
                v = (*it1 - INT(1));
            } else {
                v = *it1;
            }
            if (v < INT(0)) {
                v += INT(10);
                borrow = true;
            } else {
                borrow = false;
            }
            diff.val_.push_front(v);
        }
        
        return diff;
    }
    
    BigInt<INT> &operator--()
    {
        *this = (*this - INT(1));
        return *this;
    }
    
    BigInt<INT> operator/(const BigInt<INT> &other)
    {
        assert(other == BigInt<INT>(10));
        BigInt<INT> div(*this);
        div.val_.pop_back();
        return div;
    }
    
    BigInt<INT> &operator/=(const BigInt<INT> &other)
    {
        *this = *this/other;
        return *this;
    }
    
    BigInt<INT> operator%(const BigInt<INT> &other)
    {
        assert(other == BigInt<INT>(10));
        BigInt<INT> rem(val_.back());
        return rem;
    }
    
    BigInt<INT> &operator%=(const BigInt<INT> &other)
    {
        *this = *this%other;
        return *this;
    }
    
    BigInt<INT> operator*(const BigInt<INT> &other)
    {
        BigInt<INT> zero(INT(0));
        BigInt<INT> mul(zero);
        for (BigInt<INT> count = other; count != zero; --count) {
            mul += *this;
        }
        return mul;
    }
    
    BigInt<INT> &operator*=(const BigInt<INT> &other)
    {
        *this = *this * other;
        return *this;
    }
    
    bool operator==(const BigInt<INT> &other) const
    {
        typename std::list<INT>::const_reverse_iterator it1 = val_.rbegin();
        typename std::list<INT>::const_reverse_iterator it2 = other.val_.rbegin();
        

        for (; (it1 != val_.rend()) && (it2 != other.val_.rend()); ++it1, ++it2) {
            if (*it1 != *it2) {
                return false;
            }
        }
        
        if (it1 != val_.rend()) {
            for (; it1 != val_.rend(); ++it1) {
                if (*it1 != INT(0)) {
                    return false;
                }
            }
        }
        
        if (it2 != other.val_.rend()) {
            for (; it2 != other.val_.rend(); ++it2) {
                if (*it2 != INT(0)) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool operator!=(const BigInt<INT> &other) const
    {
        return !(*this == other);
    }
    
    std::size_t Digits() const
    {
        return val_.size();
    }

    /* specialization */
    friend std::ostream &operator<<<>(std::ostream &os, const BigInt<INT> &bigInt);
    
private:
    void append(const INT num)
    {
        INT i = num;
        if (num < INT(0)) {
            sign_ = INT(-1);
            i *= sign_;
        } else {
            sign_ = INT(1);
        }
        
        for (; i; i /= 10) {
            val_.push_front(i%10);
        }
    }
    
    std::list<INT> val_;
    INT sign_;
};

template <typename INT>
std::ostream &operator<<(std::ostream &os, const BigInt<INT> &bigInt)
{
    if (bigInt.sign_ < INT(0)) {
        os << '-';
    }
    for (typename std::list<INT>::const_iterator it = bigInt.val_.begin(); it != bigInt.val_.end(); ++it) {
        os << *it;
    }
    return os;
}

#endif