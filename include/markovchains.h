//
// Created by Georg on 22.01.2022.
//

#ifndef MARKOVCHAINS_H
#define MARKOVCHAINS_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include "split.h"
#include <random>
#include <algorithm>
#include <iterator>


class MarkovChains {
public:
    int len = 5;
    std::wstring s;


    MarkovChains() = default;
    MarkovChains(int len, std::wstring s);

    static std::wstring getWord(std::vector<std::wstring> vec);
    std::vector<std::wstring> followingWords(const std::wstring& vec) const;
    std::wstring generateSentence() const;





};

#endif //MARKOVCHAINS_H
