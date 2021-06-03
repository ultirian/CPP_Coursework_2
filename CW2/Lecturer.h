//
// Created by x4 on 27/04/2021.
//

#ifndef CW2_LECTURER_H
#define CW2_LECTURER_H
#include "User.h"

class Lecturer : public User {
private:
    std::string module_message;
    // Minimise interaction with this function by making it private.
    void setUsertype();
public:

    // Constructor
    Lecturer();
    ~Lecturer()
    {
        std::cout << "Lecturer Object Destroyed";
    }

// Setters

// Getters

    int getUsertype();

    // Functions
    void lecturer_menu_tree(Lecturer &lecturer_obj);
    void create_lecturer_user(Lecturer &lecturer_obj);
};


#endif //CW2_LECTURER_H
