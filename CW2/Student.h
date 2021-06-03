//
// Created by x4 on 27/04/2021.
//

#ifndef CW2_STUDENT_H
#define CW2_STUDENT_H
#include "User.h"
#include "User.h"

class Student : public User {
private:
    // Minimise interaction with this function by making it private.
    void setUsertype();
public:

    // Constructor
    Student();
    // De-constructor
    ~Student()
    {
        std::cout << "Student object destroyed";
    }

// Setters

// Getters

    int getUsertype();

    // Functions

    void student_menu_tree(Student &student_obj);

    static void create_student_user(Student &student_obj);
};


#endif //CW2_STUDENT_H
