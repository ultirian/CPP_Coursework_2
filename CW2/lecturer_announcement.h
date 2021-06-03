//
// Created by x4 on 11/05/2021.
//

#ifndef CW2_LECTURER_ANNOUNCEMENT_H
#define CW2_LECTURER_ANNOUNCEMENT_H
#include "system_announcement.h"

class lecturer_announcement : system_announcement {
private:

public:
    // Constructor
    lecturer_announcement(std::string& theTimestamp, std::string& theSender, std::string& theSubject,
                          std::string& theBody, std::string theModule);
    // Setter / Mutator
    // is child of system announcement
    void setModule(std::string newModule);
    // Getter / Accessor

    // Is child of system_announcement
    std::string getModule() const;


};








#endif //CW2_LECTURER_ANNOUNCEMENT_H
