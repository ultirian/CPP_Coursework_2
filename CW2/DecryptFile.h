// Cypher Decryption Algorithm offset 8
// Created by Chris Weaver on 11/05/2021.
// https://stackoverflow.com/questions/20929594/c-caesar-cipher-understanding-ascii-keys
// Would have implemented a better decryption algorithm, however was unable to complete in time. Proof of concept.
// (The Story of Cryptography : Historical Cryptography, n.d.)
#ifndef CW2_DECRYPTFILE_H
#define CW2_DECRYPTFILE_H

#include<iostream>
#include<fstream>

template<typename DEC>
DEC decrypt(DEC str)
{

    std::string result = "";

    int offset = 8;

    for (int i = 0; i < str.length(); ++i)
    {
        // For capital letters
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            result += (char) (str[i] - 'A' + offset) % ('Z' - 'A') + 'A';
            continue;
        }

        // For non-capital
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            result += (char) (str[i] - 'a' + offset) % ('z' - 'a') + 'a';
            continue;
        }

        // For others
        result += str[i];
    }

    // Return the resulting string
#ifdef DEBUG
    std::cout << "decrypted" << std::endl;
#endif

    return result;

}
#endif //CW2_DECRYPTFILE_H
