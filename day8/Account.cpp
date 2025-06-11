#include <iostream>
#include <string>

#include "Account.h"

#define INIT_RATE 0.05 // 初始化利率

// 因为Account::后面就都是Account类的作用域了，所以及时initRate是私有的，也可以直接使用
double Account::interestRate = initRate(); // 静态成员变量的初始化，使用类内的静态函数来设置初始值

// 即使常量静态数据成员在类内初始化了，也应该在类外定义一次，以便编译器知道它的存在和大小
// 如果不这样做，将来需要把period传递给一个函数的时候，可能编译器会找不到
// 当然，如果period只是作为daily_tbl的大小使用，并且不需要在类外使用，那么可以不定义它，但是也有可能会报错，这就取决于编译器了
// *所以无论如何，我们都推荐：类内声明，类外定义。
constexpr int Account::period;

// static成员变量的定义和初始化， 类外定义无需制定static关键字
void Account::rate(double newRate) {
    interestRate = newRate; // 设置新的利率
}

double Account::initRate() {
    return INIT_RATE; 
}