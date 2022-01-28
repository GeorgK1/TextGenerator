//
// Created by Georg on 24.01.2022.
//

#include "split.h"

std::vector <std::wstring> split(std::wstring str) {
    std::wstring buf;                 // Have a buffer string
    std::wstringstream ss(str);       // Insert the string into a stream

    std::vector<std::wstring> tokens; // Create vector to hold our words

    while (ss >> buf)
        tokens.push_back(buf);
    return tokens;
}
