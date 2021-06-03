//
// Created by x4 on 28/04/2021.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>

#ifndef CW2_PASSWORD_VALIDATION_H
#define CW2_PASSWORD_VALIDATION_H

bool passwordCheck(std::string &input)
{
    // Password length is the length of input
    int password_length_count = input.length();

    // password score is password length count 0 min max 3 and rounded
    // down by float (<cmath> (math.h) - C++ Reference, n.d.).
    int password_length_score =
            std::min(std::max((int)round((float)(password_length_count - 13) * 0.5), 0), 3);

    // Init to 0
    int password_upper_case_count = 0;
    int password_numbers_count = 0;
    int password_symbol_count = 0;

    // loops to increment counters based on bool for true false.
    for (char character : input)
    {
        if (isupper(character))
            password_upper_case_count++;
        else if (isdigit(character))
            password_numbers_count++;
        else if (!isalpha(character) && !isspace(character))
            password_symbol_count++;
    }

    // If uppercase is greater then 4 score is always 3 is > 4
    int password_upper_case_score = password_upper_case_count;
    if (password_upper_case_count > 4) password_upper_case_score = 3;
    // If uppercase is greater then 3 score is always 3 is > 4
    int password_numbers_score = password_numbers_count;
    if (password_numbers_count > 3) password_numbers_score = 3;

    // If uppercase is greater then 3 score is always 3 is > 4
    int password_symbol_score = password_symbol_count;
    if (password_symbol_count > 3) password_symbol_score = 3;
    // amalgamation of all vars for final score.
    int final_score = (password_length_score + password_upper_case_score
                       + password_numbers_score + password_symbol_score);

    // Debugging
    // std::cout << "final_score: " << final_score << std::endl;

    // Score output cascade.
    if (final_score < 3)
    {
        std::cout << "Invalid Password"<< std::endl;
        return false;
    }
    if (final_score < 6)
    {
        std::cout << "Weak Password"<< std::endl;
        return false;
    }
    if (final_score < 9)
    {
        std::cout << "Medium Password"<< std::endl;
        return false;
    }
    if (final_score >= 12)
    {
        std::cout << "Strong Password!" << std::endl;
        return true;
    }
//    return true;
}

#endif //CW2_PASSWORD_VALIDATION_H
