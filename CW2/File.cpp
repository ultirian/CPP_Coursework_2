//
// Created by x4 on 03/05/2021.
//


// Filesystem had problems with miniGW
#include <filesystem>
#include <ostream>
#include <iterator>
#include "File.h"
#include "system_announcement.h"
#include <string>
#include <algorithm>
#include "EncryptFile.h"

// Default constructor
File::File() = default;

// Bool function to read log in attempt object.
bool File::read_user_object(User &log_in_attempt_object)
{
    // uin == local variable in.
    auto uin = getInput <std::string> ("Please enter your username: ");
    // Open file to read from for comparison check
    std::ifstream in(R"(C:\Users\x4\CLionProjects\CW2\Users\)" + uin + ".txt");
    // Debugging


    // Streams in object from file.
    in >> log_in_attempt_object;

    std::cout << log_in_attempt_object.getUsername() << std::endl;
    std::cout << log_in_attempt_object.getFirstname() << std::endl;
    std::cout << log_in_attempt_object.getLastname() << std::endl;
    std::cout << log_in_attempt_object.getPassword() << std::endl;
    // Closes file
    in.close();
    // Non existent username catch.
    if(in.fail())
    {
        std::cout << "Username Does Not Exist" << std::endl;
        // Returns Empty Object
        return false;

    } else
    {
        // Returns loaded object, Huzzah.
        return true;
    }
}


void File::write_user_object(User &write_object_in)
{
    // Open File to write to
    std::ofstream out(R"(C:\Users\x4\CLionProjects\CW2\Users\)" + write_object_in.getUsername() + ".txt");
    // Write object to file
    out << write_object_in;
    // Closes file
    out.close();

    // Open file to read from for comparison check
    std::ifstream in(R"(C:\Users\x4\CLionProjects\CW2\Users\)" + write_object_in.getUsername() + ".txt");
    // Read user in for debug and check
    User user_read_in_object;
    // Streams in object from file.
    in >> user_read_in_object;
    // Closes file
    in.close();

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

    // Checks to see that create_new_user matches with read in data; ( debugging )
    assert(create_new_user == user_read_in_object); */
#endif
}

void File::write_sys_announcement(system_announcement &write_sys_in)
{


    std::cout << "File Written out on " << write_sys_in.getTimestamp() << std::endl;

    // Open File to write to
    std::ofstream out(R"(C:\Users\x4\CLionProjects\CW2\SystemAnnouncements\)" + write_sys_in.getSender() + write_sys_in.getTimestamp() +".txt");
    // Write object to file
    out << write_sys_in;
    // Closes file
    out.close();

    // Open file to read from for comparison check
    std::ifstream in(R"(C:\Users\x4\CLionProjects\CW2\SystemAnnouncements\)" + write_sys_in.getSender() + write_sys_in.getTimestamp() +".txt");
    // Read user in for debug and check
    User user_read_in_object;
    // Streams in object from file.
    in >> user_read_in_object;
    // Closes file
    in.close();

}

void File::listSystemAnnouncements() {

    // Create vector of files
    std::vector<std::string> list;
    std::vector<std::string> announcements_in;

    // iterate through Message directory and output file names. Then push back filenames to vector.
    for (auto& dirEntry: std::filesystem::recursive_directory_iterator("C:/Users/x4/CLionProjects/CW2/SystemAnnouncements/"))
    {

        if (!dirEntry.is_regular_file())
        {
#ifdef DEBUG
            std::cout << "Directory: " << dirEntry.path() << std::endl;
#endif
            continue;
        }
        std::filesystem::path file = dirEntry.path();
#ifdef DEBUG
        std::cout << "Filename: " << file.filename() << " extension: " << file.extension() << std::endl;
#endif
        list.push_back(file.filename());
    }

    // Write Announcement List.

    std::ofstream out("C:/Users/x4/CLionProjects/CW2/SystemAnnouncements/AnnouncementList.txt");
    std::copy(list.begin(), list.end(), std::ostream_iterator<std::string>(out, "\n"));

    /* loop through each file in the Announcement List and open the file. then get lines of the file and push_back
     the retrieved lines into a vector (announcements_in)*/

    // for loop that iterates through list vector to write file content to announcement vector.
    for (auto it = begin (list); it != end (list); ++it)
    {
        // f_n = file in local variable with pointer position from iterator.
        std::string f_n = (*it);
        // opens stream an_in (Announcements in)
        std::ifstream an_in;
        // Creates file
        an_in.open("C:/Users/x4/CLionProjects/CW2/SystemAnnouncements/" + *it);
        // Declare string type to feed line by line data into.
        std::string g_line;
        // loop to get and push data into vector of announcements_in
        while(getline(an_in, g_line))
        {
            announcements_in.push_back(g_line);
        }

    }
    // Read Announcements From File using a constant iterator and pointer (Content cannot be changed.)
    for (std::vector<std::string>::const_iterator i = announcements_in.begin(); i != announcements_in.end(); ++i)
    {std::cout << *i << "\n";}

}

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

    // Checks to see that create_new_user matches with read in data; ( debugging )
    assert(create_new_user == user_read_in_object); */
#endif


