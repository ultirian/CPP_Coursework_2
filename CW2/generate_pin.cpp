//
// Created by x4 on 29/04/2021.
//

#include "generate_pin.h"

// Constructor
generate_pin::generate_pin()
{
#ifdef DEBUG
    std::cout << "generate_pin Created ";
#endif
}

// Destructor
generate_pin::~generate_pin()
{
#ifdef DEBUG
    std::cout << "generate_pin Destroyed ";
#endif
}

// Setters
void generate_pin::set_full_name_in(std::string fni)
{
    m_name_in = std::move(fni);
}

void generate_pin::set_age_in(int sai)
{
    m_age_in = sai;
}

void generate_pin::set_reverse_age(int sra)
{
    m_reverse_age = sra;
}

void generate_pin::set_vowel_count(int vc)
{
    m_vowel_count = vc;
}

// Getters
std::string generate_pin::get_full_name_in(){ return m_name_in; }
int generate_pin::get_age() const { return m_age_in; }
int generate_pin::get_reverse_age() const { return m_reverse_age; }
int generate_pin::get_vowel_count() const { return m_vowel_count; }

// Functions
void generate_pin::genPin()

{
    vowelCount();
    numberReverse();
    //first digit pin var
    int firstDigitP = 0;
    // vowel count multiplied by reversed age
    int tpin = get_vowel_count() * get_reverse_age();
    // If pin sum is less than 1000 generate random number.
    // The average vowel per word is 2 vowels per word so unlikely
    // for vCount to be > 10.
    if(tpin < 1000)
    {
        // Can be predicted if user / attacker controls time.
        srand((unsigned) time(nullptr));
        firstDigitP = rand() % 9 +1;
    }
    //conversion of two ints into one string. First number first then
    //    rest of pin.
    std::ostringstream oss;
    // stream string first digit first then rest of pin.
    oss << firstDigitP << tpin;
//    std::istringstream iss(oss.str());
//    int pinOut;
//    // String out as int
//    iss >> pinOut;
    std::string PinOut;
    std::stringstream ss(oss.str());
    ss >> PinOut;


#ifdef DEBUG
    // Debugging
    std::cout << "1st:" << firstDigitP << std::endl;
    std::cout << "last 3: " << tpin << std::endl;
    std::cout << "Pin is: " << pinOut << std::endl;
#endif
    // return pin
    User::setPinNumber(PinOut);
}

void generate_pin::vowelCount()
{
    std::string nameIn = get_full_name_in();

    int vowelCount;
    vowelCount = 0;
    // For every word in name | if i is less then 150 (max varsize for
    // nameIn) could also use nameIn.length();
    // but this is a more robust range based loop (modernize-loop-convert, 2017).
    for(int i = 0; i < 150; ++i)
    { // Check if vowel is present and if true
        if(nameIn[i]=='a' || nameIn[i]=='e' || nameIn[i]=='i' ||
           nameIn[i]=='o' || nameIn[i]=='u' || nameIn[i]=='A' ||
           nameIn[i]=='E' || nameIn[i]=='I' || nameIn[i]=='O' ||
           nameIn[i]=='U')
        { // Increase vowel count by 1
            ++vowelCount;
        }
    }
    // Sets vowel count
    set_vowel_count(vowelCount);
}
// Reverse number for math
void generate_pin::numberReverse() {
    int rn = 0;
    int a_in = get_age();
    // while numbers remain
    while (a_in > 0)
    { // reverse number * 10 add age in modulo 10
        rn = rn*10 + a_in%10;
        // age in /10 for result.
        a_in = a_in/10;
    }
    set_reverse_age(rn);
}
