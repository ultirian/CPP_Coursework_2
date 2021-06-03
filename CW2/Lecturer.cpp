//
// Created by x4 on 27/04/2021.
//

#include <iostream>
#include "inputvalidation.h"
#include "Lecturer.h"
#include "User.h"
void main_menu();
// Default Constructor

Lecturer::Lecturer()
{
    m_usertype = 2;
}

// Setters

void Lecturer::setUsertype()
{
    m_usertype = 2;
}
// Getters

int Lecturer::getUsertype(){ return m_usertype; }

// Functions
void Lecturer::lecturer_menu_tree(Lecturer &lecturer_obj) {

    std::cout << "*********************************" << std::endl;
    std::cout << "USW Lecturer Landing" << std::endl;
    std::cout << "Select 1 For Create New Lecturer User" << std::endl;
    std::cout << "Select 2 For Log in to Lecturer Portal" << std::endl;
    std::cout << "Select 3 For Create Module Announcement" << std::endl;
    std::cout << "*********************************" << std::endl;

    int selection = getInput<int>("Enter Selection:");
    switch (selection) {
        case 1:
            create_lecturer_user(lecturer_obj);
            main_menu();
            break;
        case 2:
            log_in(lecturer_obj);
            main_menu();
            break;
        case 3:
            // Create Module Announcement
            break;
        default:
            std::cout << "Invalid Selection" << std::endl;
    }
}

    void Lecturer::create_lecturer_user(Lecturer &lecturer_obj) {

        // Sets User Type?
        lecturer_obj.setUsertype();
        // Creates User
        lecturer_obj.create_user(lecturer_obj);

    }
