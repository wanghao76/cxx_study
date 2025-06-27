#include <iostream>
#include <algorithm>
#include <ostream>
#include "Complex.h"

std::ostream& operator<<(std::ostream& os, const Complex& obj) {
    os << "(" << obj.get_x() << ", " << obj.get_y() << ")";
    return os;
}


Complex& operator += (Complex& lhs, const Complex& rhs) {
    return __doapl(lhs, rhs); // 调用友元函数
}
inline Complex& __doapl(Complex& lhs, const Complex& rhs) {
    lhs.x += rhs.x; // 利用友元性质直接访问私有成员变量
    lhs.y += rhs.y;
    return lhs;
}


