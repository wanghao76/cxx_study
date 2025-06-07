#include<iostream>
#include<string>
#include<stdexcept>
#include<initializer_list>

#include "chapter6.h"

int swap(int *a, int *b) {
    if (a == nullptr || b == nullptr) {
        std::cerr << "Error: Null pointer passed to swap function." << std::endl;
        return -1; // 返回-1表示错误
    }
    int temp = *a; // 使用临时变量交换值
    *a = *b;
    *b = temp;
    
    std::cout << "function swap's pointers values a,b addresses are " << &a << " and " << &a << std::endl;
    return 0; // 返回0表示成功
}

int print (const int *a, size_t s) 
{   
    if (a == nullptr || s <= 0) {
        return -1;
    } 

    for (size_t i = 0; i != s; ++i) {
        std::cout << a[i] << std::endl;
    }
    return 0;
}

int sum_list(std::initializer_list<int> il) 
{
    int sum = 0;
    for (const auto& val : il) {
        sum += val;
    }

    return sum;
}

// void f1(int, int) {
//     std::cout << "f1(int, int) called" << std::endl;
//     // 调用f2函数
//     // f1(1, 2);
// }

// void f1(const double, const int) {
//     std::cout << "f1(const double, const int) called" << std::endl;
//     // 调用f2函数
//     // f1(1, 2);
// }

// void f1(double height, int weight, int age) {
//     std::cout << "f1 called with height: " << height 
//               << ", weight: " << weight 
//               << ", age: " << age << std::endl;
//     // 这里可以添加更多的逻辑
// }

// void f1() {
//     std::cout << __func__ << " called" << std::endl;
// }

void f1(int a) {
    std::cout << __func__ << " called with int a: " << a << std::endl;
}

// void f1(double a) {
//     std::cout << __func__ << " called with double a: " << a << std::endl;
// }

// void f1(int a, int b) {
//     std::cout << __func__ << " called with int a: " << a << ", int b: " << b << std::endl;
// }

// void f1(int a, double b) {
//     std::cout << __func__ << " called with int a: " << a << ", double b: " << b << std::endl;
// }

void f1(double a, double b) {
    std::cout << __func__ << " called with double a: " << a 
                          << " and default b: " << b << std::endl;
}

