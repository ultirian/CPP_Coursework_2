//
// Created by x4 on 05/05/2021.
//
#include <vector>
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include "Admin.h"
#include "User.h"

#ifndef CW2_SYSTEM_ANNOUNCEMENT_H
#define CW2_SYSTEM_ANNOUNCEMENT_H

class system_announcement : public User {

    // Private
    private:

    friend std::ostream &operator <<(std::ostream &out, system_announcement & mobj);
// Set Timestamp (date / time)
    std::string sa_timestamp;
    std::string sa_formatted_timestamp;
    // Set Sender
    std::string sa_sender;
    // Set Message Subject
    std::string sa_subject;
    // Set Message Body
    std::string sa_message_body;
    // Set Module for lecturer child class
    std::string la_module;
    // Public
    public:

    // Map
    typedef std::map<std::ostream *, bool> UserMap;
    static UserMap User_flag;

    system_announcement(std::string& theTimestamp, std::string& theSender, std::string& theSubject, std::string& theBody);
    // Vector to hold messages
    static std::vector<system_announcement> messages;
    // Constructors
    system_announcement()
    {
        sa_timestamp = "NoTime";
        sa_sender = "NoSender";
        sa_subject = "NoSubject";
        la_module = "NULL";
        sa_message_body = "NoMessage";
    };

    // De-constructor
    ~system_announcement();
    // Setter / mutator
    // Set Timestamp (date / time)
    void setTimestamp(std::string timestamp);
    void setFormattedTimestamp(std::string newFormattedTimestamp);
    // Set Sender
    void setSender(std::string sender);
    // Set Message Subject
    void setSubject(std::string subject);
    // Set Message Body
    void setMessage(std::string body);
    // Getter / accessor
    std::string getTimestamp() const;
    std::string getFormattedTimestamp();
    std::string getSender() const;
    std::string getSubject() const;
    std::string getMessage() const;

    // Functions
    static system_announcement create_new_message(system_announcement &new_message, Admin &admin_object);

    // Overloading object with == operator.
    bool operator==(const system_announcement& mobj) const;

    // Stream In.
    friend std::istream & operator >> (std::istream &in, system_announcement &mobj)
    {
        in >> mobj.sa_formatted_timestamp;
        in >> mobj.sa_sender;
        in >> mobj.sa_subject;
        in >> mobj.la_module;
        in >> mobj.sa_message_body;
        return in;
    }

    void setModule(std::string newModule);

    std::string getModule() const;


};


#endif //CW2_SYSTEM_ANNOUNCEMENT_H
