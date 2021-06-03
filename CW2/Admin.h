//
// Created by x4 on 05/05/2021.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include "User.h"
#include "inputvalidation.h"

#ifndef CW2_ADMIN_H
#define CW2_ADMIN_H


class Admin : public User {
private:
    // Minimise interaction with this function by making it private.
    void setUsertype();
public:

    // Constructor
    Admin();
    // De-constructor
    ~Admin();

// Setters

// Getters
    int getUsertype();

// Functions
    // Menu Tree
    void admin_menu_tree(Admin &obj);
    // Create New Admin User
    static void create_admin_user(Admin &obj);
    // Delete any User
    // Set system wide message
    static void create_system_message(Admin &admin_obj);


};



#endif //CW2_ADMIN_H
