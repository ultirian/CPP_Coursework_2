//
// Created by x4 on 29/04/2021.
//
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include "User.h"

#ifndef CW2_GENERATE_PIN_H
#define CW2_GENERATE_PIN_H

class generate_pin : public User {

private:
    int m_vowel_count, m_reverse_age, m_age_in;
    std::string m_name_in;

public:

    // Constructor
    generate_pin();
    ~generate_pin();

    // Setters
    void set_full_name_in(std::string fni);
    void set_age_in(int sai);
    void set_reverse_age(int sra);
    void set_vowel_count(int vc);

    // Getters
    std::string get_full_name_in();
    int get_age() const;
    int get_reverse_age() const;
    int get_vowel_count() const;

    // Functions

    void genPin();
    void vowelCount();
    void numberReverse();

};

#endif //CW2_GENERATE_PIN_H
