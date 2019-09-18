//
//  P17.cpp
//  ProjectEuler
//
//  Created by Sid on 28/01/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

/*
 
 If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 
 If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
 
 NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
 */

#include <cassert>
#include <iostream>
#include <string>


const char *DigitToStr(const int num)
{
  switch (num) {
    case 1: return "one"; break;
    case 2: return "two"; break;
    case 3: return "three"; break;
    case 4: return "four"; break;
    case 5: return "five"; break;
    case 6: return "six"; break;
    case 7: return "seven"; break;
    case 8: return "eight"; break;
    case 9: return "nine"; break;
    case 10: return "ten"; break;
    case 11: return "eleven"; break;
    case 12: return "twelve"; break;
    case 13: return "thirteen"; break;
    case 14: return "fourteen"; break;
    case 15: return "fifteen"; break;
    case 16: return "sixteen"; break;
    case 17: return "seventeen"; break;
    case 18: return "eighteen"; break;
    case 19: return "nineteen"; break;
    case 20: return "twenty"; break;
    case 30: return "thrity"; break;
    case 40: return "forty"; break;
    case 50: return "fifty"; break;
    case 60: return "sixty"; break;
    case 70: return "seventy"; break;
    case 80: return "eighty"; break;
    case 90: return "ninety"; break;
    case 100: return "hundred"; break;
    case 1000: return "thousand"; break;
  }
  return "";
}



void PrintDigit(std::string &word, const int num, const int place)
{
  if (!place) {
    return;
  }
  
  int digit = num/place;
  
  bool done = false;
  
  if (digit) {
    if (place > 10) {
	    word += DigitToStr(digit);
      word += " ";
      word += DigitToStr(place);
      word += (num%place? " and" : "");
      word += " ";
    } else if (num < 20) {
	    word += DigitToStr(num);
      word += " ";
      done = true;
    } else {
	    word += DigitToStr(num/10*10);
      word += "-";
      word += DigitToStr(num%10);
      word += " ";
      done = true;
    }
  }
  
  if (!done) {
    PrintDigit(word, num%place, place/10);
  }
  
}

int Length(const std::string &word)
{
  int len = 0;
  for (std::string::const_iterator it = word.begin(); it != word.end(); ++it) {
    if (*it == ' ' || *it == '-') {
      continue;
    }
    len++;
  }
  return len;
}

int LetterCount(const int start, const int end)
{
  int lCount = 0;
  for (int i = start; i < end; ++i) {
    std::string word;
    PrintDigit(word, i, 1000);
    //std::cout << word << std::endl;
    lCount += Length(word);
  }
  return lCount;
}

int P17_Main()
{
  std::string word342;
  PrintDigit(word342, 342, 1000);
  assert(Length(word342) == 23);

  std::string word115;
  PrintDigit(word115, 115, 1000);
  assert(Length(word115) == 20);

  assert(LetterCount(1, 6) == 19);
  std::cout << LetterCount(1, 1001) << std::endl;

  return 0;
}