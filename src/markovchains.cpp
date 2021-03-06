//
// Created by Georg on 22.01.2022.
//

#include "markovchains.h"

#include <utility>


MarkovChains::MarkovChains(int len, std::wstring s)
        : len{len},
          s{std::move(s)}
           {

}

std::wstring MarkovChains::getWord(std::vector<std::wstring> vec) {
    int rnumber = rand() % vec.size();
    return vec.at(rnumber);

}

std::vector<std::wstring> MarkovChains::followingWords(const std::wstring &word) const {
    std::vector<std::wstring> svec{split(s)};

    std::vector<std::wstring> fw;
    ///Get the next word from the random word
    for (size_t i = 0; i < svec.size() -1 ; ++i) {

        if (svec[i] == word) {
            fw.push_back(svec[i + 1]);
        }
    }

    return fw;
}


std::wstring MarkovChains::generateSentence() const {
    std::wstring sen;
    std::vector<std::wstring> svec{split(s)};
    std::wstring initword = getWord(svec);

    for (int i = 0; i < len; ++i) {
        std::vector<std::wstring> sel = followingWords(initword);
        std::wstring nextword = getWord(sel);

        initword = nextword;
        sen += nextword + L" ";
    }

    return sen;
}


