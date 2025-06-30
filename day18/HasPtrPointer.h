#ifndef HASPTRPOINTER_H
#define HASPTRPOINTER_H

#include <iostream>
#include <string>

class HasPtrPointer {

public: 
    HasPtrPointer(const std::string &s = std::string()) :
        ps(new std::string(s)), i(0), use_count(new std::size_t(1)) {}

    HasPtrPointer(const HasPtrPointer& hpr) : 
        ps(hpr.ps), i(hpr.i), use_count(hpr.use_count) { *use_count++; }

    HasPtrPointer& operator=(const HasPtrPointer& hpr);

    ~HasPtrPointer();
private:
    std::string *ps;
    int i;

    // 注意这里不能用static， 要明白pointer-like class的真正意图
    // 比如A和B对象，我需要在通过A给B做赋值或者初始化的过程中，实现AB的共享
    // 而不是只要创建了AB对象，这两就共享了。
    // static int use_count;

    // 那应该怎么做呢？动态内存！！！我擦这个思路是真的牛皮
    std::size_t *use_count;
};


#endif