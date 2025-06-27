#include <iostream>
#include <fstream>

#include "TextQuery.h"

void runQueries(std::ifstream& infile);

int main() {

    std::string file = "file.txt";
    std::ifstream infile(file);
    if (infile.is_open()) {
        runQueries(infile);
    }
    return 0;
}

void runQueries(std::ifstream& infile)
{
    TextQuery tq(infile);
    
    while (true) {
        std::cout << "enter a word to look for, or q to quit: ";

        std::string s;

        if (!(std::cin >> s) || s == "q") { break; }
        
        print(std::cout, tq.query(s)) << std::endl;
    } 
}