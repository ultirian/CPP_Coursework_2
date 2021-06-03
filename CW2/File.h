//
// Created by x4 on 03/05/2021.
//
#include <iterator>
#include <ostream>
#include "User.h"
#include "system_announcement.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#ifndef CW2_FILE_H
#define CW2_FILE_H


class File : public User {
private:

public:

    File();
    bool read_user_object(User &log_in_attempt_object);
    void write_user_object(User &write_object_in);
    void write_sys_announcement(system_announcement &write_sys_in);
    void listSystemAnnouncements();

};

#endif //CW2_FILE_H
