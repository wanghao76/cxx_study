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
