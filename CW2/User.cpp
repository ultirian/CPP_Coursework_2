//
// Created by x4 on 22/04/2021.
//

#include <iostream>
#include <string>
#include <iterator>
#include "User.h"
#include "inputvalidation.h"
#include "duplicate_user_check.h"
#include "password_validation.h"
#include "generate_pin.h"
#include "File.h"
#include "EncryptFile.h"
#include "DecryptFile.h"
#include "md5hash.h"
// Constructor
User::User(std::string username,
           std::string firstname,
           std::string lastname,
           std::string password,
           int age,
           std::string pin_number,
           int usertype) :
           m_username(std::move(username)),
           m_firstname(std::move(firstname)),
           m_lastname(std::move(lastname)),
           m_password(std::move(password)),
           m_age(age),
           m_pin(std::move(pin_number)),
           m_usertype(usertype)
           {

           }

// Associates objects with variables and returns the data.

// Overloaded Constructor
bool User::operator==(const User &obj) const {
    return (m_username == obj.m_username) && (m_firstname == obj.m_firstname ) &&
           (m_lastname == obj.m_lastname) && (m_password == obj.m_password) &&
           (m_age == obj.m_age) && (m_pin == obj.m_pin) && (m_usertype == obj.m_usertype);
}

// Setters
void User::setUsername(std::string un)
{
    m_username = std::move(un);
}
void User::setUsername_comparison(std::string un2)
{
    m_username2 = std::move(un2);
}
void User::setFirstname(std::string fn)
{
    m_firstname = std::move(fn);
}
void User::setLastname(std::string ln)
{
    m_lastname = std::move(ln);
}
void User::setPassword(std::string pw)
{
    m_password = std::move(pw);
}
void User::setPassword_comparison(std::string pw2)
{
    m_password2 = std::move(pw2);
}
void User::setAge(int age)
{
    m_age = age;
}
void User::setPinNumber(std::string pn)
{
    m_pin = std::move(pn);
}

// No setter for m_usertype as is encapsulated in child classes Admin Lecturer Student.

// Getters
std::string User::getUsername(){ return m_username; }
std::string User::getUsername_comparison(){ return m_username2; }
std::string User::getFirstname(){ return m_firstname;}
std::string User::getLastname(){ return m_lastname; }
std::string User::getPassword(){ return m_password; }
std::string User::getPassword_comparison(){ return m_password2; }
int User::getAge() const{ return m_age; }
std::string User::getPinNumber() const { return m_pin; }
bool User::getLogInState() const { return log_in_status; }
int User::getUsertype() const{ return m_usertype; }

void User::create_user(User &user_obj)
{
    // Fill variables with input validation
    // t_ = temporary variables released at end of function.
    do
    {
        auto t_username = getInput<std::string>("Please insert desired username:");
        User::setUsername(t_username);

        // Check if username matches if not then loop.
    }while(duplicate_user_check(m_username) == true);

    // Set Firstname
    auto t_firstname = getInput <std::string> ("Please insert first name:");
    User::setFirstname(t_firstname);

    // Set Lastname
    auto t_lastname = getInput <std::string> ("Please insert last name:");
    User::setLastname(t_lastname);

    // create pin object
    generate_pin pin_obj;

    // Concatenates variables for vowel count function in generate_pin
    pin_obj.set_full_name_in( t_firstname + t_lastname );

    // Generate pin from inputs
    auto t_age = getInput <int> ("Please input your age");
    setAge(t_age);
    pin_obj.set_age_in(t_age);
    // Generate Pin
    pin_obj.genPin();
    std::cout << "*********************************" << std::endl;
    std::cout << "Please MAKE NOTE AS THIS IS NON RECOVERABLE: " << std::endl;
    std::cout << "Pin is: " << pin_obj.getPinNumber() << std::endl;
    std::cout << "*********************************" << std::endl;
    // If unable to recover can use md5 converter
    setPinNumber(pin_obj.getPinNumber());


    std::string generated_pin_hash_out = generate_hash_output(getPinNumber());

    // Set password1 with password strength check.
    do
    {
        std::cout << "*********************************" << std::endl;
        auto t_password1 = getInput <std::string> ("Please insert desired password:");
        std::cout << "*********************************" << std::endl;

        User::setPassword(t_password1);

    }while(passwordCheck(m_password) == false);

    // compares password1 to password2 before setting m_password (That is written out to file).
    do
    {
        std::cout << "*********************************" << std::endl;
        User::m_password2 = getInput<std::string>("Please re-enter desired password:");
        std::cout << "*********************************" << std::endl;

        if(m_password != m_password2)
        {
            std::cout << "*********************************" << std::endl;
            std::cout << "Passwords Do Not Match" << std::endl;
            std::cout << "*********************************" << std::endl;
        }
        else if (m_password == m_password2)
        {
            std::cout << "*********************************" << std::endl;
            std::cout << "Passwords Match!" << std::endl;
            std::cout << "*********************************" << std::endl;
            setPassword(m_password2);
        }

    // Keeps looping until m_password is equal to m_password2
    }while(m_password != m_password2);

    // Hash function call to write variable for writing out to object.
    std::string generated_password_hash_out = generate_hash_output(getPassword());
    // Debugging
    std::cout << "*********************************" << std::endl;
    std::cout << "GEN HASH OUT: " << generated_password_hash_out << std::endl;
    std::cout << "*********************************" << std::endl;

    // Encrypt Prep, passes through each getter line by line and encrypts varibles before passing them to object to
    // write out.

#ifdef DEBUG
    std::cout << "User name O is  :" << m_username << std::endl;
    std::cout << "First name O is :" << m_firstname << std::endl;
    std::cout << "Last name O is  :" << m_lastname << std::endl;
    std::cout << "Password O is   :" << m_password << std::endl;
    std::cout << "Usertype O is   :" << m_usertype << std::endl;
    std::cout << "age O is   :" << m_age << std::endl;
    std::cout << "pin O is   :" << m_pin << std::endl;
#endif

    std::string e_firstname = encrypt(m_firstname);
    std::string e_lastname = encrypt(m_lastname);

#ifdef DEBUG
    std::cout << "User name O is  :" << m_username << std::endl;
    std::cout << "First name O is :" << e_firstname << std::endl;
    std::cout << "Last name O is  :" << e_lastname << std::endl;
    std::cout << "Password O is   :" << e_password << std::endl;
    std::cout << "Usertype O is   :" << m_usertype << std::endl;
    std::cout << "age O is   :" << e_age << std::endl;
    std::cout << "pin O is   :" << e_pin << std::endl;
#endif

    // Create new object for file stream out username is not required to be encrypted
    User write_object_in(m_username,
                         e_firstname,
                         e_lastname,
                         generated_password_hash_out,
                         m_age,
                         generated_pin_hash_out,
                         m_usertype);

#ifdef DEBUG
//  Decrypt test

    std::string d_firstname = decrypt(e_firstname);
    std::string d_lastname = decrypt(e_lastname);

    std::cout << "First name O is :" << d_firstname << std::endl;
    std::cout << "Last name O is  :" << d_lastname << std::endl;
#endif
    // Create file object to write to file, required for modified hash variables.
    File file;
    file.write_user_object(write_object_in);

#ifdef DEBUG
    std::cout << "User name O is  :" << create_new_user.m_username << std::endl;
    std::cout << "First name O is :" << create_new_user.m_firstname << std::endl;
    std::cout << "Last name O is  :" << create_new_user.m_lastname << std::endl;
    std::cout << "Password O is   :" << create_new_user.m_password << std::endl;
    std::cout << "Usertype O is   :" << create_new_user.m_usertype << std::endl;

    // Read ins.
    std::cout << "User name I is  :" << user_read_in_object.m_username << std::endl;
    std::cout << "First name I is :" << user_read_in_object.m_firstname << std::endl;
    std::cout << "Last name  I is:" << user_read_in_object.m_lastname << std::endl;
    std::cout << "Password I is   :" << user_read_in_object.m_password << std::endl;
    std::cout << "Usertype I is   :" << user_read_in_object.m_usertype << std::endl;
#endif
}

bool User::log_in(User &log_in_attempt_object)
{
    // New object to input data into.


    int log_in_attempts = 0;
    std::string entered_user;
    std::string entered_password;

    // Load object from file.
    File file;
    file.read_user_object(log_in_attempt_object);

    // Decrypt file object. Username is unencrypted so not required.

    std::ostream &operator<<(std::ostream &output, const User &log_in_attempt_object);
    std::cout << "*********************************" << std::endl;;
    std::cout << "DEBUG DATA: " << log_in_attempt_object << std::endl;
    std::cout << "*********************************" << std::endl;

    while (log_in_attempts < 3)
    {
        // Inputs For Comparison
        std::cout << "*********************************" << std::endl;
        auto confirm_username_in = getInput <std::string> ("Please Confirm your Username: ");
        std::cout << "*********************************" << std::endl;
        setUsername_comparison(confirm_username_in);

        // Enter Password for log in.
        std::cout << "*********************************" << std::endl;
        auto password_in = getInput<std::string>("Enter Password: ");
        std::cout << "*********************************" << std::endl;
        // Sets comparison varaible password
        setPassword_comparison(password_in);
        // Generates hash for password comparison
        std::string comparison_password_hash = generate_hash_output(getPassword_comparison());
        // Debugging
        std::cout << "Password Hash DEBUG:" << comparison_password_hash << std::endl;
        std::cout << "Password Hash m_password DEBUG:" << log_in_attempt_object.m_password << std::endl;
        // Enter Pin Log in
        std::cout << "*********************************" << std::endl;
        auto pin_in = getInput<std::string>("Enter Pin Number: ");
        std::cout << "*********************************" << std::endl;

        // Generates pin hash for comparison.
        std::string comparison_pin_hash = generate_hash_output(pin_in);
        //Debugging
        std::cout << "Pin Hash DEBUG:" << comparison_pin_hash << std::endl;
        std::cout << "Pin Hash m_pin DEBUG:" << log_in_attempt_object.m_pin << std::endl;

        // Condition check for User / password / pin all have to be true.
        if (getUsername_comparison() == log_in_attempt_object.m_username &&
            comparison_password_hash == log_in_attempt_object.m_password &&
            comparison_pin_hash == log_in_attempt_object.m_pin)
        {
            std::cout << "*********************************" << std::endl;
            std::cout << "Welcome Username: " << log_in_attempt_object.m_username << std::endl;
            std::cout << "Welcome First Name: " << decrypt(log_in_attempt_object.m_firstname) << std::endl;
            std::cout << "Welcome Last Name: " << decrypt(log_in_attempt_object.m_lastname) << std::endl;
            std::cout << "*********************************" << std::endl;
            // Return type true
            return log_in_status = true;
        }
        else
        {
            std::cout << "*********************************" << std::endl;
            std::cout << "MISCONDUCT! TRY AGAIN" << std::endl;
            std::cout << "*********************************" << std::endl;
#ifdef DEBUG
            std::cout << log_in_attempt_object.m_username << std::endl;
            std::cout << log_in_attempt_object.m_password << std::endl;
#endif
            // Increment log in attempts
            log_in_attempts++;
        }

    }
    //
    if (log_in_attempts == 3) {

        std::cout << "**********************************************************************" << std::endl;
        std::cout << "  __  __ _____  _____  _____ ____  _   _ _____  _    _  _____ _______ " << std::endl;
        std::cout << " |  \\/  |_   _|/ ____|/ ____/ __ \\| \\ | |  __ \\| |  | |/ ____|__   __|" << std::endl;
        std::cout << " | \\  / | | | | (___ | |   | |  | |  \\| | |  | | |  | | |       | |   " << std::endl;
        std::cout << " | |\\/| | | |  \\___ \\| |   | |  | | . ` | |  | | |  | | |       | |   " << std::endl;
        std::cout << " | |  | |_| |_ ____) | |___| |__| | |\\  | |__| | |__| | |____   | |   " << std::endl;
        std::cout << " |_|  |_|_____|_____/ \\_____\\____/|_| \\_|_____/ \\____/ \\_____|  |_|  " << std::endl;
        std::cout << "MISCONDUCT OF THE HIGHEST ORDER!!! You are not logged in, GOODBYE!!!" << std::endl;
        std::cout << "**********************************************************************" << std::endl;
        // Return type false
        return log_in_status = false;
    }
#ifdef DEBUG
    std::ostream &operator<<(std::ostream &output, const User &log_in_attempt_object);
    std::cout << "Username is: " << log_in_attempt_object << std::endl;
#endif
}
// get system messages declared user level as after setting all users will be given messages.
void User::get_system_messages() {
    // Declare object
    File f_obj;
    // Call function through object of file.
    f_obj.listSystemAnnouncements();
}











