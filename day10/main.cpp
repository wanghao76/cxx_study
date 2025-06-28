#include <iostream>
#include "Complex.h"
#include "String.h"

int main() {
    // std::cout << "Hello, World!" << std::endl;

    // const Complex my_object(42.0, 32.0); // 创建一个Complex对象
    // *如若get_x()非const成员函数，则会编译报错
    // my_object.get_x(); // 调用成员函数获取值。
    // std::cout << "x: " << my_object.get_x() << std::endl; // 输出值

    //* 复数运算试验
    Complex obj1(10.0, 20.0);

    // 两复数相加的 += 调用
    // Complex obj2(5.0, 15.0);
    // obj1 = obj1 + obj2; // 使用运算符重载进行加法操作
    // obj1 += obj2; // 使用运算符重载进行加法操作

    // 实数 + 复数
    // double value = 3.0;
    // obj1 = value + obj1;   // operator + (double, complex)called

    // 复数 + 实数
    // double value = 3.0;    //operator + (complex, double)called
    // obj1 = obj1 + value; 

    // std::cout << "Results of addition: x = " << obj1.get_x() 
    //           << ", y = " << obj1.get_y() << std::endl; // 输出结果
    // std::cout << "obj1 conj is: " << conj(obj1) << std::endl
    //           << "obj1 is" << obj1 << std::endl;


    // String实现 深拷贝
    {
        String s1;
        String s2("hello");
        std::cout << "s2: " << s2 << std::endl;
        String *p = new String("hello");
        std::cout << "p-> : " << *p << std::endl;

        delete p;
    }

    {
        String s1("Hello");
        std::cout << "s1: " << s1 << std::endl;
        // String s2(s1);
        String s2 = s1;
        std::cout << "s2: " << s2 << std::endl;
    }
    return 0;
}