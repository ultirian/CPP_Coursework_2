//
// Created by x4 on 05/05/2021.
//

#include "Admin.h"
#include "File.h"
#include <iostream>
#include <ostream>
#include "User.h"
#include "system_announcement.h"

void main_menu();

// Constructor

Admin::Admin()
{
    m_usertype = 1;
#ifdef DEBUG
    std::cout << "Admin Object Created" << std::endl;
#endif
}

Admin::~Admin()
{
#ifdef DEBUG
    std::cout << "Admin Object Destroyed";
#endif
}

// Setters
void Admin::setUsertype()
{
    m_usertype = 1;
}
// Getters

int Admin::getUsertype(){ return m_usertype; }

// Functions

void Admin::admin_menu_tree(Admin &admin_obj)
{
    get_system_messages();
    std::cout << "*********************************" << std::endl;
    std::cout << "USW Admin Landing" << std::endl;
    std::cout << "Select 1 For Create New Admin User" << std::endl;
    std::cout << "Select 2 For Log in to Admin Portal" << std::endl;
    std::cout << "Select 3 For Create System Announcement" << std::endl;
    std::cout << "Select 4 for Delete System Announcement" << std::endl;
    std::cout << "Select 5 For Delete User" << std::endl;
    std::cout << "*********************************" << std::endl;


    int selection = getInput<int>("Enter Selection:");
    switch (selection) {
        case 1:
            // Crate Admin New User
            create_admin_user(admin_obj);
            main_menu();
        case 2:
            log_in(admin_obj);
            main_menu();
        case 3:
            // Create System Announcement
            create_system_message(admin_obj);
            main_menu();
        case 4:
            // TODO Delete System Announcements
            break;
        case 5:
            // TODO Delete Users
        default:
            std::cout << "Invalid Selection" << std::endl;
    }
}

void Admin::create_admin_user(Admin &admin_obj)
{
    // Inherits object from main, keeping the object in the heap (10.10 — The stack and the heap | Learn C++, 2020).
    admin_obj.setUsertype();
    admin_obj.create_user(admin_obj);

}

void Admin::create_system_message(Admin &admin_obj)
{
    system_announcement new_message;
    system_announcement::create_new_message(new_message, admin_obj);
}


