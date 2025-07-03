#include <iostream>
#include <string>

#include "HasPtr.h"


// HasPtr& HasPtr::operator=(const HasPtr& hpr)
// {
    // self assignment check
//     if (this == &hpr) {
//         return *this;
//     }

    // temp存在的目的是: new异常发生时，原资源保持不变。
//     std::string *temp_ps = new std::string(*hpr.ps);  // 先分配新资源
//     delete ps;  // 再删除旧资源
//     ps = temp_ps;
//     i = hpr.i;
// }

// HasPtr::~HasPtr() {
//     delete ps;
//     ps = nullptr; //不需要这么做，因为你设置为nullptr之后，他随即就被释放了，没什么意义。
// }

HasPtr& HasPtr::operator=(HasPtr&& hpr) noexcept 
{
    if (this != &hpr) {
        delete ps;
        ps = hpr.ps;
        i = hpr.i;

        hpr.ps = nullptr;
    }
    std::cout << "call the move assignment function." << std::endl;
    return *this;
}