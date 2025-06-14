#include<iostream>
using namespace std;

int resued = 42;

int main() {
    // int a = 0, b = 0;
    // std::cout << "Enter two integers: ";
    // std::cin >> a >> b;
    // std::cout << "Hello, World!" << std::endl;
    // std::endl 作用其实是刷新输出缓冲区, 以及换行
    // std::cout << "You entered: " << a << " and " << b << std::endl;
    // std::cout << "You entered: " << a << " and " << b << " and " << "Sum: " << a + b << std::endl;

    // int sum = 0;
    // a = 10;
    // while (a > 0) {
    //     // std::cout << "a is less than 10, current value: " << a << std::endl;
    //     // --a;
    //     sum += a;
    //     --a;
    // }

    // int sum = 0;
    // for (int val = -100; val <= 100; ++val) sum += val;

    // int sum = 0;

    // while (std::cin >> a) {
    //     if (a < 0) break; // 如果输入的数小于0，则退出循环
    //     sum += a; // 累加输入的数
    // }
    // std::cout << "sum is: " << sum << std::endl;

    // int t = 6;

    // std::cout << "t is: " << t << std::endl;
    // std::cout << "resued is: " << resued << std::endl;


    // int resued = 100;
    // // 这里的 resued 是局部变量，遮蔽了全局变量 resued
    // std::cout << "resued is: " << resued << std::endl;
    // std::cout << "t is: " << t << std::endl;

    // std::cout << "global resued is: " << ::resued << std::endl;


    // int val = 111;
    // int sum = 0;
    // for (int val = 0; val < 10; ++val) {
    //     // 这里的 val 是循环变量，遮蔽了外部的 val
    //     // std::cout << "val is: " << val << std::endl;
    //     sum += val;
    // }

    // std::cout << "sum is: " << sum << std::endl;
    // std::cout << "val is: " << val << std::endl; // 这里的 val 是外部的 val

    // int i = 11;

    // int &rei = i; // rei 是 i 的引用
    // rei = 22; // 修改 rei 的值，也会修改 i 的值

    // std::cout << "i is: " << i << std::endl; // 输出 22
    // std::cout << "rei is: " << rei << std::endl; // 输出 22

    // int &rj = rei; // rj 是 rei 的引用
    // rj = 33; // 修改 rj 的值，也会修改 rei 和 i 的值
    // std::cout << "now i is: " << i << std::endl; // 输出 33
    // std::cout << "now rei is: " << rei << std::endl; // 输出 33
    // std::cout << "now rj is: " << rj << std::endl; // 输出 33

    // unsigned int ui = 42;
    // int i = -2;

    // unsigned int res = ui + i;
    // std::cout << "ui + i is: " << res << std::endl; // 输出 4294967294

    // int *i = nullptr; // i 是一个空指针
    // int j = 42;
    // i = &j; // i 现在指向 j 的地址

    // std::cout << "i points to: " << *i << std::endl; // 输出 42
    // std::cout << "Address of j is: " << &j << std::endl; // 输出 j 的地址
    // std::cout << "Address stored in i is: " << i << std::endl; // 输出 i 的值，即 j 的地址
    // std::cout << "Address of i is: " << &i << std::endl; // 输出 i 的地址
    // std::cout << "Size of i is: " << sizeof(i) << std::endl; // 输出指针 i 的大小
    // std::cout << "Size of j is: " << sizeof(j) << std::endl; // 输出变量 j 的大小
    // std::cout << "Size of int is: " << sizeof(int) << std::endl; // 输出 int 类型的大小
    // std::cout << "Size of pointer is: " << sizeof(int*) << std::endl; // 输出指针类型的大小

    // int *k = i; // k 现在指向 i 的地址，即 j 的地址

    // // std::cout << "k points to: " << *k << std::endl; // 输出 42
    // // std::cout << "Address stored in k is: " << k << std::endl; // 输出 k 的值，即 j 的地址
    // // std::cout << "Address of k is: " << &k << std::endl; // 输出 k 的地址

    // *k = 100; // 修改 k 指向的值，即修改 j 的值
    // std::cout << "After modifying k, j is: " << j << std::endl; // 输出 100
    // std::cout << "After modifying k, *i is: " << *i << std::endl; // 输出 100
    // std::cout << "After modifying k, *k is: " << *k << std::endl; // 输出 100
    // std::cout << "Address of j is: " << &j << std::endl; // 输出 j 的地址
    // std::cout << "Address stored in i is: " << i << std::endl; // 输出 i 的值，即 j 的地址
    // std::cout << "Address stored in k is: " << k << std::endl; // 输出 k 的值，即 j 的地址
    // std::cout << "Address of i is: " << &i << std::endl; // 输出 i 的地址
    // std::cout << "Address of k is: " << &k << std::endl; // 输出 k 的地址

    // 所以 i 和 k 都指向 j 的地址，修改 *k 的值会影响到 j 和 *i 的值。

    // double obj = 3.14, *pd = &obj; // pd 是一个指向 pv 的指针
    // void* pv = &obj; // pv 是一个指向 obj 的 void 指针

    // bool isEqual = (pd == pv); // 比较 pd 和 pv 是否相等
    // // std::boolalpha 用于输出布尔值时显示 true 或 false，而不是 1 或 0
    // std::cout << "pd == pv: " << std::boolalpha << isEqual << std::endl; // 输出 pd == pv: true

    // std::cout << "pd address: " << &pd << std::endl; // 输出 pd 的地址
    // std::cout << "pv address: " << &pv << std::endl; // 输出 pv 的地址
    // std::cout << "obj address: " << &obj << std::endl; // 输出 obj 的地址

    // std::cout << "pv value: " << pv << std::endl; 

    // std::cout << "pd value: " << *pd << std::endl; // 输出 pd 指向的值，即 obj 的值
    // std::cout << "pv value: " << *(static_cast<double*>(pv)) << std::endl; // 输出 pv 指向的值，即 obj 的值
    // std::cout << "pv value: " << *pv << std::endl;

    // int i = 0;
    // int *p = &i; 
    // std::cout << "i is: " << i << std::endl; // 输出 0
    // std::cout << "p points to: " << *p << std::endl; // 输出 0
    // std::cout << "Address of i is: " << &i << std::endl; // 输出 i 的地址
    // std::cout << "Address stored in p is: " << p << std::endl; // 输出 p 的值，即 i 的地址
    // std::cout << "Address of p is: " << &p << std::endl; // 输出 p 的地址

    // int *p = nullptr; // p 是一个空指针

    // std::cout << "*p : " << p << std::endl; // 输出 p 的值，即 nullptr

    // 编译时初始化
    // const int bufferSize = 1024; 

    // int i = 111;

    // int& j = i; // j 是 i 的引用

    // int k = 222;
    
    // double deval = 3.14;
    // const int &ri = deval;

    // std::cout << "deval is: " << deval << std::endl; // 输出 3.14
    // std::cout << "ri is: " << ri << std::endl; // 输出 3

    // // ri = 4; // 这行代码会导致编译错误，因为 ri 是一个 const 引用，不能修改其值
    // // std::cout << "ri address: " << &ri << std::endl; // 输出 ri 的地址

    // const int i = 1111;
    // int& j = i; // 这行代码会导致编译错误，因为 i 是一个 const int，不能被引用为非 const 引用

    int i = 1111; // 这里的 i 是一个普通的 int 变量
    const int &j = i; // j 是 i 的 const 引用
    // j = 2222; // 这行代码会导致编译错误，因为 j 是一个 const 引用，不能修改其值

    int &k = i; // k 是 i 的非 const 引用

    std::cout << "i is: " << i << std::endl; // 输出 1111
    std::cout << "j is: " << j << std::endl; // 输出 1111
    std::cout << "k is: " << k << std::endl; // 输出 1111

    k = 2222; // 修改 k 的值，也会修改 i 的值
    std::cout << "After modifying k, i is: " << i << std::endl; // 输出 2222
    std::cout << "After modifying k, const j is: " << j << std::endl; // 输出 2222
    std::cout << "After modifying k, k is: " << k << std::endl; // 输出 2222

    return 0;   
}