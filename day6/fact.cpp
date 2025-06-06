#include<iostream>
#include<string>
#include<stdexcept>

#include "chapter6.h"


int fact(int val)
{
    if (val < 0) {
        std::cout << "Error: Factorial of a negative number is undefined." << std::endl;
        return -1; // 返回一个错误值    
    }

    int ret = 1; // 初始化阶乘结果为1
    if (val == 0) {
        return ret; // 0的阶乘是1
    }
    while (val > 1) {
        ret *= val--;
    }

    std::cout << "Calculation complete!" << std::endl;

    return ret; // 返回计算得到的阶乘结果
}
