// Cypher Encryption Algorithm offset 17
// Created by Chris Weaver on 11/05/2021.
// https://stackoverflow.com/questions/20929594/c-caesar-cipher-understanding-ascii-keys
// Would have implemented a better encryption algorithm, however was unable to complete in time. Proof of concept.
// (The Story of Cryptography : Historical Cryptography, n.d.)
#ifndef CW2_ENCRYPTFILE_H
#define CW2_ENCRYPTFILE_H

#include<iostream>
#include<fstream>

template<typename ENC>
ENC encrypt(ENC &str)
{
    std::string result = "";

    int offset = 17;

    for (int i = 0; i < str.length(); ++i)
    {
        // Capital Letters
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            result += (char) (str[i] - 'A' + offset) % ('Z' - 'A') + 'A';
            continue;
        }

        // Non Capital
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            result += (char) (str[i] - 'a' + offset) % ('z' - 'a') + 'a';
            continue;
        }

        // Ignores special chars.
        result += str[i];
    }
    // Return the resulting string
#ifdef DEBUG
    std::cout << "encrypted" << std::endl;
#endif
    return result;

}


#endif //CW2_ENCRYPTFILE_H
