//
// Created by x4 on 27/04/2021.
//

#ifndef CW2_DUPLICATE_USER_CHECK_H
#define CW2_DUPLICATE_USER_CHECK_H
#include <iostream>
#include <windows.h> // (theForger's Win32 API Tutorial, n.d.)
#include <iterator>  // (Iterator library - cppreference.com, n.d.)
#include <algorithm> // (Algorithms library - cppreference.com, n.d.)
#include <vector>    // (vector - C++ Reference, n.d.)

bool duplicate_user_check(auto user_chk)
{

    // Crates vector for storing filenames
    std::vector<std::string> names;
    // searches specified folder plus ext.
    std::string search_path = R"(C:\Users\x4\CLionProjects\CW2\Users\*.*)";
    // calls windows.h library to find data in folder
    WIN32_FIND_DATA file_data;

    HANDLE hFind = ::FindFirstFile(search_path.c_str(), &file_data);
    if(hFind != INVALID_HANDLE_VALUE) {
        do {
            // read all (real) files in current folder
            // , delete '!' read other 2 default folder . and ..
            if(! (file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ) {
                names.emplace_back(file_data.cFileName);
            }
        }while(::FindNextFile(hFind, &file_data));
        ::FindClose(hFind);

        // prints out files found in folder Users (debugging).
        std::copy(names.begin(), names.end(), std::ostream_iterator<std::string>(std::cout, " | "));

    }
    // Carnage loop to return true and false
    {
        // Define extension .txt to add to comparison
        std::string file_ext = ".txt";

        for (auto &element : names) {
            if (element == user_chk + file_ext) {
                std::cout << "Username already taken." << std::endl;
                return true;
            }
        }
        std::cout << "Username available." << std::endl;
        return false;

    }

}

#endif //CW2_DUPLICATE_USER_CHECK_H
