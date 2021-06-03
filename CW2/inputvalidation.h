//
// Created by x4 on 23/04/2021.
//

#ifndef CW2_INPUTVALIDATION_H
#define CW2_INPUTVALIDATION_H
template<typename T>

T getInput(const std::string& message)
{
    std::cout << message << "\n";
    T out = T();

    while(!(std::cin >> out))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Incorrect Input, Try again\n";
        std::cout << message;
    }
    return out;
}
#endif //CW2_INPUTVALIDATION_H
