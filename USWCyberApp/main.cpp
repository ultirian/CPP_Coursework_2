//
// Created by Chris on 19/11/2020.
//
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

string insertName();
int vowelCount(string nameIn);
int enterAge();
int enterAcct();
int numberReverse(int ageIn);
int genPin(int vCount, int rAge);

// Main Program
int main()
{
        string nameout = insertName();
        int ageNumber = enterAge();
        int accountNumber = enterAcct();
        int pin = genPin(vowelCount(nameout), numberReverse(ageNumber));

        cout << "Hello: " << nameout << endl;
        cout << "Your account number has been created: " << accountNumber << endl;
        cout << "Your unique pin number is: " << pin << endl;

        // Debugging
        // cout << "Vowel Count is: " << endl;
        // cout << vowelCount(nameout) << endl;
        // cout << "Account Number is:" << accountNumber << endl;
        // cout << "Age is: " << ageNumber << endl;
        // cout << "Reversed Age is: " << numberReverse(ageNumber) << endl;
        // cout << "Pin is: " << pin << endl;

}

int genPin(int vCount, int rAge)
{
    //first digit pin var
    int firstDigitP = 0;
    // vowel count multiplied by reversed age
    int tpin = vCount * rAge;
    // If pin sum is less then 1000 generate random number.
    // The average vowel per word is 2 vowels per word so unlikely
    // for vCount to be > 10.
    if(tpin < 1000){

        // Can be predicted if user / attacker controls time.
        srand((unsigned) time(nullptr));
        firstDigitP = rand() % 9 +1;
    }

    //conversion of two ints into one string. First number first then rest of pin.
    ostringstream oss;
    // stream string first digit first then rest of pin.
    oss << firstDigitP << tpin;
    istringstream iss(oss.str());
    int pinOut;
    // String out as int
    iss >> pinOut;

    // Debugging
    // cout << "1st:" << firstDigitP << endl;
    // cout << "last 3: " << tpin << endl;
    // cout << "Pin is: " << pinOut << endl;

    // Return concatenated string.
    return pinOut;

}
// Count vowel for math
int vowelCount(string nameIn)
{
    int vowelCount;
    vowelCount = 0;
    // For every word in name | if i is less then 150 (max varsize for nameIn) could also use nameIn.length();
    // but this is a more robust range based loop (modernize-loop-convert, 2017).
    for(int i = 0; i < 150; ++i)
    {   // Check if vowel is present and if true
        if(nameIn[i]=='a' || nameIn[i]=='e' || nameIn[i]=='i' ||
                nameIn[i]=='o' || nameIn[i]=='u' || nameIn[i]=='A' ||
                nameIn[i]=='E' || nameIn[i]=='I' || nameIn[i]=='O' ||
                nameIn[i]=='U')
        {   // Increase vowel count by 1
            ++vowelCount;
        }
    }
    // Return vowel count
    return vowelCount;
}
// Reverse number for math
int numberReverse(int ageIn) {
    int rn = 0;

    // while numbers remain
    while (ageIn > 0)
    {   // reverse number * 10 add age in modulo 10
        rn = rn*10 + ageIn%10;
        // age in /10 for result.
        ageIn = ageIn/10;
    }
    return rn;
}
// Insert name 3 parts
string insertName()
{

    char firstName[50];
    char middleName[50];
    char lastName[50];
    const string spc = " ";

    cout << "Please enter first name:";
    cin.getline(firstName, 50);
    cout << "Please enter middle name:";
    cin.getline(middleName, 50);
    cout << "Please enter last name:";
    cin.getline(lastName, 50);

    string fN = firstName + spc + middleName + spc + lastName;
    return fN;

}
// a == Age
int enterAge()
{
    int a;
    cout << "Please enter your age:";
    cin >> a;
    return a;

}

// an == Account Number
int enterAcct()
{

    int an;
    cout << "Please enter account number:";
    cin >> an;
    return an;

}