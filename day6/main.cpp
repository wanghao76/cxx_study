#include<iostream>
#include<string>
#include<stdexcept>
#include<vector>
#include<iterator>
#include<cstdlib>


#include "chapter6.h"

// void 函数返回值可以为return; 也可以是另一个返回值类型为void的函数。
// void f2() {
//     std::cout << "f2 called" << std::endl;
// }

// void f1() { return f2(); }

// std::vector<int> get_vector() {
//     return {1, 2, 3, 4, 5}; // 返回一个包含整数的vector
// }

// int f3(std::vector<int>& v, decltype(v.size())& i) {
//     if (i == v.size()) {
//         return 0; // 如果索引等于vector的大小，返回0表示结束递归
//     }

//     std::cout << v[i] << " "; // 输出当前索引的值
//     return f3(v, ++i); // 递归调用，索引自增
// }

// 返回指针数组的函数表示法：
// 1. 尾置返回类型
// auto f4(int i) -> int(*)[];

// 2. 使用decltype
// int odd[] = {1, 3, 5, 7, 9};
// decltype(odd) *f4 (int i);

// 3. 直接写
// int (*f4(int i))[5] {
//     return;
// }

int main(int argc, char* argv[]) 
{
    // 1. 阶层运算函数sample
    // int val = -1;
    // std::cout << "Enter a non-negative integer to calculate its factorial: ";
    // std::cin >> val;
    // if (std::cin.fail()) {
    //     std::cerr << "Invalid input. Please enter a valid integer." << std::endl;
    //     return 1; // 返回1表示输入错误
    // }
    // int result = fact(val);
    // if (result != -1) {
    //     std::cout << "Factorial of " << val << " is: " << result << std::endl;
    // }
    // else {
    //     std::cout << "Failed to calculate factorial due to invalid input." << std::endl;
    // }

    // 2. q,p指针的值传递
    // int a = 10, b = 20;
    // int *p = &a, *q = &b;
    // std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;

    // int swap_result = swap(p, q);

    // if (swap_result == 0) {
    //     std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
    // } else {
    //     std::cerr << "Swap operation failed." << std::endl;
    // }

    // p,q指针的地址和函数中形参a,b的地址不同，说明这样的方式是值传递。
    // 因此，更加推荐使用引用传递来交换两个变量的值。
    // std::cout << "function swap's pointers values p,q addresses are " << &p << " and " << &q << std::endl;

    // 3. 可以通过这种方法来计算数组的大小
    // int j[] = {1, 3};
    // auto size = std::end(j) - std::begin(j);
    // std::cout << "size: " << size << std::endl;

    // int a[] = {1, 2, 3, 4, 5, 6, 7};
    // print(a, std::end(a) - std::begin(a));


    // 4. argc和argv的使用示例
    // if (argc != 3) {
    //     std::cerr << "Usage: " << argv[0] << " <string1> <string2>" << std::endl;
    //     return 1; // 返回1表示参数错误
    // }
    // std::string str1 = argv[1];
    // std::string str2 = argv[2];

    // std::cout << str1 + str2 << std::endl; // 输出两个字符串的连接结果

    // for (size_t i = 0; i < argc; ++i) {
    //     std::cout << "Argument " << i << ": " << argv[i] << std::endl; // 输出每个参数
    // }

    // 5. initializer_list的使用示例
    // error_msg(ErrCode::OK, {});
    // error_msg(ErrCode::INVALID, {"Invalid input", "Please check your data."});
    // error_msg(ErrCode::NULLPTR, {});
    // error_msg(ErrCode::UNKNOWN, {});

    // 6. initializer_list的使用示例
    // int result = sum_list({1, 3, 5 ,6 ,7});
    // std::cout << "Sum of the list: " << result << std::endl; // 输出列表的和

    // 7. void的返回值可以是另一个void函数
    // f1(); // 调用f1函数，间接调用f2函数

    // 8. return值可以是{}的列表 
    // for (const auto& val : get_vector()) {
    //     std::cout << val << " "; // 输出vector中的每个元素
    // }
    // std::cout << std::endl; // 换行输出


    // 9. 递归实现vector遍历
    // std::vector<int> v = {1, 2, 3, 4, 5};
    // decltype(v.size()) i = 0;
    // f3(v, i);
    // std::cout << std::endl; // 换行输出


    
    return 0; // 返回0表示程序正常结束
    // return EXIT_SUCCESS; // 或者使用宏定义的EXIT_SUCCESS, 来表示成功结束，但需要引入cstdlib库

}
