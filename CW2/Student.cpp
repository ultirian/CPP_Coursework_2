//
// Created by x4 on 27/04/2021.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include "inputvalidation.h"
#include "Student.h"
#include "User.h"
void main_menu();
// Constructors

Student::Student(){}

// Setters

void Student::setUsertype()
{
    m_usertype = 3;
}
// Getters

int Student::getUsertype(){ return m_usertype; }

// Functions

// Menu Tree for student
void Student::student_menu_tree(Student &student_obj) {

    std::cout << "*********************************" << std::endl;
    std::cout << "USW Student Landing" << std::endl;
    std::cout << "Select 1 For Create New Student User" << std::endl;
    std::cout << "Select 2 For Log in to Student Portal" << std::endl;
    std::cout << "Select 3 For Get Results" << std::endl;  // TODO
    std::cout << "*********************************" << std::endl;

    int selection = getInput<int>("Enter Selection:");
    switch (selection) {
        case 1:
            create_student_user(student_obj);
            main_menu();
        case 2:
            log_in(student_obj);
            main_menu();
        case 3:
            // Create Module Announcement
            break;
        default:
            std::cout << "Invalid Selection" << std::endl;
    }
}

// Student User creation
void Student::create_student_user(Student &student_obj)
{
    student_obj.setUsertype();
    //create new Student user inheriting from parent class User
    student_obj.create_user(student_obj);
}


