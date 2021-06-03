#include <iostream>
#include <sstream>
#include "User.h"
#include "Admin.h"
#include "Student.h"
#include "Lecturer.h"
#include "File.h"
#include "system_announcement.h"

#define DEBUG 1
void new_admin_object()
{
    Admin admin_obj;
    admin_obj.admin_menu_tree(admin_obj);
}
void new_lecturer_object()
{
    Lecturer lecturer_obj;
    lecturer_obj.lecturer_menu_tree(lecturer_obj);
}
void new_student_object()
{
    Student student_obj;
    student_obj.student_menu_tree(student_obj);
}

void main_menu()
{
    std::cout << "*********************************" << std::endl;
    std::cout << "USW CyberAPP Landing" << std::endl;
    std::cout << "Select 1 For Admin Portal" << std::endl;
    std::cout << "Select 2 For Lecturer Portal" << std::endl;
    std::cout << "Select 3 For Student Portal" << std::endl;
    std::cout << "Select 4 For Exit" << std::endl;
    std::cout << "*********************************" << std::endl;

    int selection = getInput<int>("Enter Selection:");
    switch (selection) {
        case 1:
            new_admin_object();
            main_menu();
        case 2:
            new_lecturer_object();
            main_menu();
        case 3:
            new_student_object();
            main_menu();
        case 4:
            exit(EXIT_SUCCESS);
        default:
            std::cout << "Invalid Selection" << std::endl;
    }

}
int main() {
    main_menu();
}

