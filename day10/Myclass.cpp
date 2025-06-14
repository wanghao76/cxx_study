#include <iostream>
#include <algorithm>
#include <ostream>
#include "Myclass.h"

std::ostream& operator<<(std::ostream& os, const MyClass& obj) {
    os << "(" << obj.get_x() << ", " << obj.get_y() << ")";
    return os;
}