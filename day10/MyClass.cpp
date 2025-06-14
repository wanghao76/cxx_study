#include <iostream>
#include <algorithm>
#include <ostream>
#include "MyClass.h"

std::ostream& operator<<(std::ostream& os, const MyClass& obj) {
    os << "(" << obj.get_x() << ", " << obj.get_y() << ")";
    return os;
}


MyClass& operator += (MyClass& lhs, const MyClass& rhs) {
    return __doapl(lhs, rhs); // 调用友元函数
}
inline MyClass& __doapl(MyClass& lhs, const MyClass& rhs) {
    lhs.x += rhs.x; // 利用友元性质直接访问私有成员变量
    lhs.y += rhs.y;
    return lhs;
}