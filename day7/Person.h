#include <iostream>

#ifndef PERSON_H
#define PERSON_H

struct Person {

    Person() = default;  // 默认构造函数

    // 带参数的构造函数
    Person(const std::string& name) : full_name(name) {}

    Person(const std::string& name, unsigned age, const std::string& address)
        : full_name(name), age(age), address(address) {}

    Person(std::istream& is);

    // 成员函数
    inline std::string name() const {
        return full_name;  // 返回全名
    }

    // 数据成员
    std::string full_name;  // 全名
    unsigned age = 0;       // 年龄
    std::string address;    // 地址
};

std::istream& read(std::istream&, Person&);
std::ostream& print(std::ostream&, const Person&);

#endif