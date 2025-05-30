#include<iostream>
using namespace std;

#define SIZE_MACRO 42

constexpr int size() {
        return SIZE_MACRO;
}

constexpr int ci = 0;


int main() {

    // int a = 1, b = 2;
    // int *p = &a; // p 是一个指针，指向 a 的地址

    // int *const ptr = &a; // ptr 是一个常量指针，指向 a 的地址

    // ptr = &b; // 错误，ptr 是常量指针，不能改变指向的地址
    // *ptr = 3; // 正确，可以修改 ptr 指向的值
    // cout << "a is: " << a << endl; // 输出 3

    // const int *p2 = &a; // p2 是一个指向常量的指针，不能通过 p2 修改 a 的值
    // // *p2 = 4; // 错误，不能通过 p2 修改 a 的值
    // p2 = &b; // 正确，可以改变 p2 指向的地址
    // cout << "*p2 is: " << *p2 << endl; // 输出 1

    // const int *const p3 = &a; // p3 是一个指向常量的常量指针，不能通过 p3 修改 a 的值，也不能改变 p3 指向的地址

    // // *p3 = 4; // 错误，不能通过 p3 修改 a 的值
    // // p3 = &b; // 错误，不能改变 p3 指向的地址
    // cout << "*p3 is: " << *p3 << endl; // 输出 1

    // const int *p2 = &a; // p2 是一个指向常量的指针，不能通过 p2 修改 a 的值

    // const int *const p3 = &b;

    // p2 = p3; // 正确，可以改变 p2 指向的地址

    // std::cout << "*p2 is: " << *p2 << std::endl; // 输出 2
    // std::cout << "*p3 is: " << *p3 << std::endl; // 输出 2

    // // constexpr用于定义编译时常量，通常用于需要在编译时计算的值, 也可以用作显示判断声明和定义的变量是常量表达式
    // constexpr int bufferSize = 1024; // 编译时常量
    // constexpr int limit = bufferSize + 11;
    // // 定义一个 size 函数，返回一个常量值

    // constexpr int sz = size(); // sz 是一个编译时常量，调用 size 函数获取值
    // // std::cout << "sz is: " << sz << std::endl;

    // constexpr int i = 0;
    // constexpr const int *p = &ci; // p 是一个指向 a 的常量指针

    // const int &i = 43; // i 是一个常量引用，引用了一个常量值 43
    // int &j = 43; // 这行代码会导致编译错误，因为不能引用一个常量值

    //要在一条语句中定义多个变量,切记,符号&和*只从属于声名符,而非基本数据类型的一部分, 因此定义的初始值必须是同一种类型:
    // int i = 1111;
    // const int ci = i;

    // auto &r = i, *pr = &ci; // 错误: i 是一个 int，ci 是一个 const int，不能将它们混合在一起
    // // auto &r = ci, *pr = &i; // 错误: ci 是一个 const int，不能被引用为非 const 引用

    // int i = 42, *p = &i, &r = i;
    // decltype(r) x; // x 是 int 类型，因为 r 是 int 的引用, 引用绑定的必须是已定义的变量或对象
    // decltype(r + 0) y; // y 是 int 类型，因为 r + 0 的结果是 int 类型
    // decltype(*p) c; // decltype(*p)的结果类型是int& 而非 int. 因为杰引用指针可以得到指针所指的对象,还能给对象赋值.

    // int i = 43;

    // decltype(i) j = i; // j 是 int 类型，因为 i 是 int 类型
    // decltype((i)) k = i; // k 是 int& 类型，因为 (i) 是一个 lvalue 表达式，引用了 i
    // // 注意decltype((i)) 和 decltype(i) 的区别:
    // // - decltype(i) 返回 i 的类型，即 int。
    // // - decltype((i)) 返回 (i) 的类型，即 int&，因为 (i) 是一个 lvalue 表达式。
    // // decltype((value)) 永远是引用类型, decltype(value) 是跟随value而定。

    // ++j; // j 的值变为 44
    // std::cout << "j is: " << j << std::endl; // 输出 44
    // std::cout << "i is: " << i << std::endl; // 输出 43

    // ++k; // k 的值变为 44
    // // i 的值也变为 44，因为 k 是 i 的引用
    // std::cout << "k is: " << k << std::endl; // 输出 44
    // std::cout << "i is: " << i << std::endl; // 输出 44
    
    // int a =0, b = 2;

    // decltype(a=b) c = a; // c 是 int 类型，因为 a = b 的结果是 int& 类型
    // c++;
    // std::cout << "c is: " << c << std::endl; // 输出 1
    // std::cout << "a is: " << a << std::endl; // 输出 1
    // std::cout << "b is: " << b << std::endl; // 输出 2

    // std::cout << "--------------------------------" << std::endl;

    // auto d = (a=b);

    // //表达式在右侧会改变a的值
    // std::cout << "d is: " << d << std::endl; // 输出 2
    // std::cout << "a is: " << a << std::endl; // 输出 2
    // std::cout << "b is: " << b << std::endl; // 输出 2
    // std::cout << "c is: " << c << std::endl; // 输出 2

    // std::cout << "--------------------------------" <<std::endl;

    // d++; // d 是 int 类型，d 的值变为 3, 但auto推导出来的不是引用,所以其他值不变.
    // std::cout << "d is: " << d << std::endl; // 输出 3
    // std::cout << "a is: " << a << std::endl; // 输出 2
    // std::cout << "b is: " << b << std::endl; // 输出 2
    // std::cout << "c is: " << c << std::endl; // 输出 2
    return 0;
}