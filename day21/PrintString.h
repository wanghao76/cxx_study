#ifndef PRINTSTRING_H

#include <iostream>
#include <string>
#include <vector>

class PrintString {

friend std::ostream& operator<<(std::ostream& os, PrintString& ps);

public:
    PrintString(std::istream& i) : is(i) { 
        std::string line;
        while(std::getline(is, line)) {
            svec.push_back(line);
        }
    }

private:
    std::istream& is;
    std::vector<std::string> svec;
};


std::ostream& operator<<(std::ostream& os, PrintString& ps);

#endif