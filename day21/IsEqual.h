#ifndef ISEQUAL_H
#define ISEQUAL_H

#include <iostream>

class IsEqual {

public:
    IsEqual(int v) : value(v) {}
    bool operator() (int num) {
        return value == num;
    }

private: 
    int value;
};


#endif