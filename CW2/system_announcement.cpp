//
// Created by x4 on 05/05/2021.
//

#include <iterator>
#include <string>
#include <ctime>
#include "system_announcement.h"
#include "Admin.h"
#include "File.h"

// Constructor
system_announcement::system_announcement( std::string& theTimestamp, std::string& theSender, std::string& theSubject, std::string& theBody)
: sa_timestamp(theTimestamp), sa_sender(theSender), sa_subject(theSubject), sa_message_body(theBody)
{
    setTimestamp(theTimestamp);
    setSender(theSender);
    setSubject(theSubject);
    setMessage(theBody);
}

// Associates objects with variables and returns the data.

bool system_announcement::operator==(const system_announcement &mobj) const
{
    return (sa_timestamp == mobj.sa_timestamp) &&(sa_sender == mobj.sa_sender ) &&
           (sa_subject == mobj.sa_subject) && (sa_message_body == mobj.sa_message_body);
}

// Setters
void system_announcement::setTimestamp(std::string newTimestamp)
{
    sa_timestamp = std::move(newTimestamp);
}
void system_announcement::setFormattedTimestamp(std::string newFormattedTimestamp)
{
    sa_timestamp = std::move(newFormattedTimestamp);
}
void system_announcement::setSender(std::string newSender)
{
    sa_sender = std::move(newSender);
}
void system_announcement::setSubject(std::string newSubject)
{
    sa_subject = std::move(newSubject);
}
void system_announcement::setMessage(std::string newBody)
{
    sa_message_body = std::move(newBody);
}
// Getters
std::string system_announcement::getTimestamp() const { return sa_timestamp; }
std::string system_announcement::getFormattedTimestamp() { return sa_formatted_timestamp;}
std::string system_announcement::getSender() const { return sa_sender; }
std::string system_announcement::getSubject() const { return sa_subject; }
std::string system_announcement::getMessage() const { return sa_message_body; }

// Map Function (Cogswell and Mueller, 2014)

system_announcement::UserMap system_announcement::User_flag;
std::ostream &operator <<(std::ostream &out, system_announcement &mobj) {
    bool is_lecturer = false;
    system_announcement::UserMap::iterator iter =
            system_announcement::User_flag.find(&out);
    if (iter != system_announcement::User_flag.end()) {
        is_lecturer = iter->second;
    }

    // Is lecturer
    if (is_lecturer) {
        out << "Timestamp : ";
        out << mobj.getFormattedTimestamp() << "\n";
        out << "Sender : ";
        out << mobj.getSender() << "\n";
        out << "Module : ";
        out << mobj.getModule() << "\n";
        out << "Subject : ";
        out << mobj.getSubject() << "\n";
        out << "Body : ";
        out << mobj.getMessage() << "\n";

    }
    else // Not Lecturer
    {
        out << "Timestamp : ";
        out << mobj.getTimestamp() << "\n";
        out << "Sender : ";
        out << mobj.getSender() << "\n";
        out << "Subject : ";
        out << mobj.getSubject() << "\n";
        out << "Body : ";
        out << mobj.getMessage() << "\n";
    }
    return out;
}

    // Manipulators to control the outputs of Admin and/or Lecturer announcement to reuse class code.
    struct LecturerManipulatorOutput{};

    void LecturerBool(LecturerManipulatorOutput x){}
    typedef void(*LectPointer)(LecturerManipulatorOutput);

    std::ostream &operator << (std::ostream &out, LectPointer)
    {
        system_announcement::User_flag[&out] = true;
        return out;
    }

    struct AdminManipulatorOutput{};

    void AdminBool(AdminManipulatorOutput x){}
    typedef void(*AdminPointer)(AdminManipulatorOutput);

    std::ostream &operator << (std::ostream &out, AdminPointer)
    {
        system_announcement::User_flag[&out] = false;
        return out;
    }
    // write message as a single file object
system_announcement system_announcement::create_new_message(system_announcement &new_message, Admin &admin_object)
{
    if( admin_object.getUsertype() == 1) {
        // control to make sure user is adming
        // TODO create control flow to make sure user is admin and logged in.
        // Get time
        // TODO create full timestamp with separators
        std::time_t t = std::time(0);
        std::tm *now = std::localtime(&t);
        int year = (now->tm_year + 1900);
        int month = (now->tm_mon + 1);
        int day = now->tm_mday;
        std::string slash = "/";
        // Convert time ints to strings
        std::stringstream ss;
        ss << day << month << year;
        std::string combined_time;
        ss >> combined_time;

        // Debugging
        std::cout << "Combined time : " << combined_time << std::endl;

        std::stringstream sss;
        std::string date_formatted;
        sss << day << slash << month << slash << year;
        sss >> date_formatted;
        // Debug
        std::cout << "Date Formatted : " << date_formatted << std::endl;

        // Inputs for message
        // TODO input validation to accept strings with spaces, will have to use getline but try and work it into header?
        auto sender_local = getInput<std::string>("Enter Sender :"); // Default to username?
        auto subject_local = getInput<std::string>("Enter Subject: ");
        auto body_local = getInput<std::string>("Enter message body: ");
        // set message for writeout.

        new_message.setTimestamp(combined_time);
        new_message.setFormattedTimestamp(date_formatted);
        new_message.setSender(sender_local);
        new_message.setSubject(subject_local);
        new_message.setMessage(body_local);

    }
    else {std::cout << "You are not an administrator" << std::endl;}

#ifdef DEBUG
    std::cout << new_message.sa_timestamp << std::endl;
    std::cout << new_message.sa_sender << std::endl;
    std::cout << new_message.sa_subject << std::endl;
    std::cout << new_message.sa_message_body << std::endl;
#endif
    File f;
    f.write_sys_announcement(new_message);

    // TODO what to do with this return ?
    return new_message;
}

// read vector to work with vector before write as a vector before writing out.

system_announcement::~system_announcement() {

}





