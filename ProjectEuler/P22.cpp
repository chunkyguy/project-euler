//
//  P22.cpp
//  ProjectEuler
//
//  Created by Sid on 28/05/14.
//  Copyright (c) 2014 whackylabs. All rights reserved.
//

/**
 Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
 
 For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
 
 What is the total of all the name scores in the file?
 
 */

#include <cassert>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <regex>
#include <string>
#include <sstream>
#include <vector>

#include "Timer.h"

int Score(const std::string &name)
{
    int score = 0;
    for (std::string::const_iterator it = name.begin(); it != name.end(); ++it) {
        score += std::toupper(*it) - 'A' + 1;
    }
    return score;
}

class ScoreCalculator {
public:
    ScoreCalculator() :index(1) {}
    
    std::size_t operator()(const std::size_t val, const std::string &str)
    {
        return val + (Score(str) * index++);
    }
    
private:
    std::size_t index; /* index begins with 1 */
};

int P22_Main()
{
    assert(Score("COLIN") * 938 == 49714);

    /* open file */
    std::ifstream fin("/Volumes/DrivePlusPlus/Languages/c-cpp/Projects/project_euler/ProjectEuler/ProjectEuler/names.txt");
    assert(fin);

    /* read file into string */
    std::ostringstream oss;
    oss << fin.rdbuf();
    
    std::string fileContent(oss.str());
    //std::string fileContent("\"sid\",\"bhatti\",\"nik\",\"sam\",\"kc\"");

    /* split string into tokens */
    std::regex reg("[\"]*[,\"][\"]*");
    std::sregex_token_iterator tokenBegin(fileContent.begin(), fileContent.end(), reg, -1);
    std::sregex_token_iterator tokenEnd;

    /* insert tokens into array */
    std::vector<std::string> list;
    
    /* skip first empty string */
    for (++tokenBegin; tokenBegin != tokenEnd; ++tokenBegin) {
        list.push_back((*tokenBegin).str());
    }

    /* sort array */
    std::sort(list.begin(), list.end());

    assert(std::distance(list.begin(), std::lower_bound(list.begin(), list.end(), "COLIN"))+1 == 938);
    
    //std::copy(list.begin(), list.end(), std::ostream_iterator<std::string>(std::cout, " "));

    /* calculate score */
    TimerMS("Time: ");
    std::cout << std::accumulate(list.begin(), list.end(), 0, ScoreCalculator()) << std::endl;
    
    return 0;
}