#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

class Employee {

public:
    Employee(const std::string& n) : name(n) {
        num = ++status;
    }
    Employee(const Employee&) = delete;   // 不需要有拷贝构造和拷贝赋值，因为id唯一
    Employee& operator=(const Employee&) = delete;
    const int get_id() { return num; }

private:
    std::string name;
    int num;    // 对象的唯一id

    static int status;  // 用于生成唯一id
};

#endif