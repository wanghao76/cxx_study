#include <iostream>
#include "Myclass.h"

int main() {
    // std::cout << "Hello, World!" << std::endl;

    // const MyClass my_object(42.0, 32.0); // 创建一个MyClass对象

    // my_object.get_x(); // 调用成员函数获取值
    // std::cout << "x: " << my_object.get_x() << std::endl; // 输出值
    // This is a placeholder for the main function.
    // You can add your code here to implement the functionality you need.

    MyClass obj1(10.0, 20.0);
    MyClass obj2(5.0, 15.0);
    obj1 = obj1 + obj2; // 使用运算符重载进行加法操作
    std::cout << "Result of addition: x = " << obj1.get_x() 
              << ", y = " << obj1.get_y() << std::endl; // 输出结果

    
    std::cout << "obj1 conj is: " << conj(obj1) << std::endl
              << "obj1 is" << obj1 << std::endl;
    

    return 0;
}