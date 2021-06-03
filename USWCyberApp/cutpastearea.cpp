//
// Created by Chris on 19/11/2020.
//
#include <iostream>
#include <string>
#include <mysqlx/xdevapi.h>

using namespace std;

string insertName(){

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

    string fullName = firstName + spc + middleName + spc + lastName;
    return fullName;

}

int enterAge(){

    int a;
    cout << "Please enter your age:";
    cin >> a;
    return a;

};

int enterAcct(){

    int an;
    cout << "Please enter account number:";
    cin >> an;
    return an;

};

int main()

{
    auto fullName = insertName();
    int accountNumber = enterAcct();
    int ageNumber = enterAge();

    cout << fullName << endl;
    cout << accountNumber <<  endl;
    cout << ageNumber << endl;

}

