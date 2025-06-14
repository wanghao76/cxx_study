#ifndef SALES_DATA_H
#define SALES_DATA_H
// 这里ifndef和define的作用是防止头文件被多次包含
// 如果头文件被多次包含，编译器会报错，因为同一个结构体或类不能被定义多次

#include <iostream>
#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

#endif