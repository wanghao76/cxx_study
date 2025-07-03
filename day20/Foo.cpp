#include <iostream>
#include <algorithm>

#include "Foo.h"

Foo Foo::sort() const &
{
    Foo ret(*this);
    std::sort(ret.data.begin(), ret.data.end());
    std::cout << "left value sorted." << std::endl;
    return ret; 
}

Foo Foo::sort() &&
{
    std::sort(data.begin(), data.end());
    std::cout << "right value sorted." << std::endl;
    return *this;
}