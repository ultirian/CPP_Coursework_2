//
// Created by x4 on 11/05/2021.
//

#include "lecturer_announcement.h"
#include "system_announcement.h"

// Constructor derived from parent class system_announcement
lecturer_announcement::lecturer_announcement(std::string &theTimestamp, std::string &theSender, std::string &theSubject,
                                             std::string &theBody, std::string theModule)
                                             : system_announcement(theTimestamp, theSender, theSubject, theBody )
{

}
void system_announcement::setModule(std::string newModule)
{
    la_module = std::move(newModule);
}

std::string system_announcement::getModule() const { return la_module; }



