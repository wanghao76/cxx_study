#include <iostream>
#include <string>

#include "HasPtrPointer.h"

HasPtrPointer::~HasPtrPointer()
{
    if (--*use_count == 0) {
        delete ps;
        delete use_count;
    }
}


HasPtrPointer& HasPtrPointer::operator=(const HasPtrPointer& hpr)
{
    // self assignment check
    if (this == &hpr) {
        return *this;
    }

    ++*hpr.use_count; // 递增运算符右侧对象的引用技术

    // destory
    if (--*use_count == 0) {
        delete ps;
        delete use_count;
    }

    // assignment
    ps = hpr.ps;
    use_count = hpr.use_count;
    i = hpr.i;
    return *this;
}
