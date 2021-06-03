//
// Created by x4 on 22/04/2021.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>

#ifndef CW2_NEWUSER_H
#define CW2_NEWUSER_H

class User {

private:

protected:
    // Protected allows for variable to be accessed by child variable.
    // m_ prefix is member type
    std::string m_username;
    std::string m_username2;
    std::string m_firstname;
    std::string m_lastname;
    std::string m_password;
    std::string m_password2;
    int m_age;
    std::string m_pin;
    int m_usertype;
    bool log_in_status;


public:
    // Default Constructor
    User(std::string username = "NewUserNull",
         std::string firstname = "NewFirstNull",
         std::string lastname = "NewLastNull",
         std::string password = "NewPassNull",
         int age = 0,
         std::string pin_number = "",
         int usertype = 0);

    // Destructor
    ~User()
    {
#ifdef DEBUG
        std::cout << " User Object Destroyed" << std:: endl;
#endif
    };

    // Setters
    void setUsername(std::string un);
    void setUsername_comparison(std::string un2);
    void setFirstname(std::string fn);
    void setLastname(std::string ln);
    void setPassword(std::string pw);
    void setPassword_comparison(std::string pw2);
    void setAge(int age);
    void setPinNumber(std::string pn);

    // Getters
    std::string getUsername();
    std::string getUsername_comparison();
    std::string getFirstname();
    std::string getLastname();
    std::string getPassword();
    std::string getPassword_comparison();
    int getAge() const;
    std::string getPinNumber() const;
    bool getLogInState() const;
    int getUsertype() const;

    // Functions

    void create_user(User &obj);
    bool log_in(User &log_in_attempt_object);
    static void get_system_messages();

    // Overloading object with == operator.
    bool operator==(const User& obj) const;

    // Stream Out.
    friend std::ostream & operator << (std::ostream &out, const User & obj)
    {
        out << obj.m_username << "\n" << obj.m_firstname << "\n" << obj.m_lastname << "\n" <<
        obj.m_password << "\n" << obj.m_age << "\n" << obj.m_pin <<"\n" << obj.m_usertype << std::endl;
        return out;

    }

    // Stream In.
    friend std::istream & operator >> (std::istream &in, User &obj)
    {
        in >> obj.m_username;
        in >> obj.m_firstname;
        in >> obj.m_lastname;
        in >> obj.m_password;
        in >> obj.m_age;
        in >> obj.m_pin;
        in >> obj.m_usertype;
        return in;
    }

};
#endif //CW2_NEWUSER_H
