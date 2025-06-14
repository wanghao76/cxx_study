#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

class Account {

public:
    void calculate() {
        amount += amount * interestRate; // 计算利息
    }

    static double rate() {
        return interestRate; // 返回利率
    }

    // 静态数据成员也可以作为默认实参,但是普通的数据成员则不行, 因为静态成员独立于对象之外啊,跟类进行绑定的
    static void rate(double rate = interestRate);

private:
    std::string owner;
    double amount;

    // 一般推荐静态成员在类内声明，在类外定义。一个推荐的做法就是跟其他的非内联的函数放在一个文件里。
    static double interestRate; // 静态成员变量，所有对象共享
    static double initRate();

    // 静态成员如果是字面值常量类型，即constexpr，可以直接在类内初始化
    // !注意就算是静态成员,如果不是字面值常量类型,是不允许在类内初始化的,只能声明!!
    constexpr static int period = 30;

    // 而且也可以用在任何能使用常量表达式的地方：
    double daily_tbl[period];

    // 静态成员可以定义不完全类型；
    // static Account ac1;
    // static Account *ac2;

    //错误，普通类型只能用指针或者应用。
    // Account ac3;
    // Account *ac4;

    // 注意这里的引用，只能通过列表初始化来初始化， 不能通过赋值来初始化
    // 不能在类内定义引用成员变量，因为引用必须在初始化时绑定到一个对象上
    // Account &ac5;
};


#endif