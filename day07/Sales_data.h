#ifndef SALES_DATA_H
#define SALES_DATA_H
// 这里ifndef和define的作用是防止头文件被多次包含
// 如果头文件被多次包含，编译器会报错，因为同一个结构体或类不能被定义多次

#include <iostream>
#include <string>

struct Sales_data {

    Sales_data() = default; // 默认构造函数

    // 带参数的构造函数， 没有提供其他成员的初始值，则会进行隐式初始化：
    // 隐式初始化规则：1. 寻找类内的初始值；2. 如果没有初始值，则成员变量将被默认初始化。
    // 这样看来其实使用隐式初始化不失为一件好的选择，以为不会对定义好的初始值发生没有必要的更改
    Sales_data (const std::string& s) : bookNo(s) {}

    // 带参数的构造函数，提供了初始值
    Sales_data (const std::string& s, unsigned n, double p) 
        : bookNo(s), units_sold(n), revenue(p * n) {}

    // 通过输入流读取数据的构造函数
    Sales_data (std::istream& is);

    // 成员函数
    // 获取ISBN号
    inline std::string isbn() const {
        // 存在一个隐式的 this 指针指向当前对象
        return bookNo;  
    }

    // 合并销售数据
    Sales_data& combine (const Sales_data& rhs);

    // 数据成员
    std::string bookNo = "1001";  // ISBN号
    unsigned units_sold = 0; // 销售数量
    double revenue = 0.0; // 销售收入
};

// 非成员接口函数
Sales_data add(const Sales_data&, const Sales_data&);

// 由于传入的是std::cout, 无法被拷贝，所以是引用类型；同时注意这里的第二个参数是const。
std::ostream& print(std::ostream&, const Sales_data&);

// 同理
std::istream& read(std::istream&, Sales_data&);

std::istream& operator>>(std::istream& is, Sales_data& item);

std::ostream& operator<<(std::ostream& os, const Sales_data& item);

#endif