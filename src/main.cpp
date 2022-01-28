#include "markovchains.h"
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include<windows.h>
int main() {
    // Set console code page to UTF-8 so console known how to interpret string data, comment it out when not on windows.
    SetConsoleOutputCP(CP_UTF8);

    // Enable buffering to prevent VS from chopping up UTF-8 byte sequences
    setvbuf(stdout, nullptr, _IOFBF, 1000);

    srand(time(nullptr));

    std::wifstream wif;

    wif.open("../presets/gnulinux.txt");

    std::wstring msg;
    if(wif.is_open()) {
        std::wstring line;

        while ( std::getline(wif,line) ) {
            msg+=line;

        }
        wif.close();
    } else {
        std::cout << "Unable to open the file";
    }

    msg.erase(std::remove_if(msg.begin(), msg.end(), [](char c) { return c==','||c=='.'|| c=='!'; }), msg.end());

    MarkovChains mc{50, msg};

    std::wcout << mc.generateSentence() << std::endl;

    return 0;
}
