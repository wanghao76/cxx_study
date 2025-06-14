#include<iostream>
#include<string>
#include<stdexcept>
#include<vector>
#include<iterator>
#include<cstdlib>
#include<cassert>


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

// 调试
// void print_debug(const int array[],size_t size) {
//     //  g++ -D NDEBUG main.cpp这样就不会调用此调试语句, 对于assert语句也是同样的道理。
//     #ifndef NDEBUG
//         std::cerr << "Debugging information: " 
//                   << __FILE__ << ": in function "
//                   << __func__ << " at line "
//                   << __LINE__ << " compiled on " << std::endl
//                   << __DATE__ << " at "
//                   << __TIME__ << std::endl;
//     #endif
// }

// 函数指针
// void myfunc(int a) {
//     std::cout << "myfunc called with int: " << a << std::endl;
// }

// typedef decltype(myfunc) *func_ptr; // 定义函数指针类型FuncPtr

// typedef void (*func_ptr2)(int); // 另一种定义函数指针类型的方式

// typedef decltype(myfunc) func_ptr3; // 函数类型，会在传进函数的时候自动转为函数指针，跟数组类似

// void myfunc2(func_ptr3 f, int a) {
//     if (f != nullptr) {
//         f(a); // 调用函数指针指向的函数
//     } else {
//         std::cerr << "Function pointer is null." << std::endl;
//     }
// }

// void myfunc2(void (*f)(int a), int a) {
//     if (f != nullptr) {
//         f(a); // 调用函数指针指向的函数
//     } else {
//         std::cerr << "Function pointer is null." << std::endl;
//     }
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


    // 10. 函数重载
    // int a = 1, b = 2; // 定义两个整数变量a和b
    // f1(a, b); // 调用f1函数，使用int类型参数

    // const double c = 3.14; const int d = 4; // 定义两个常量整数变量c和d
    // f1(c, d); // 调用f1函数，使用const int类型参数

    // f1(1.75); // 调用f1函数，使用double类型参数和默认的weight值

    // 11. inline 和 constexpr 函数
    // shorter_string("Hello", "World1"); // 调用shorter_string函数，比较两个字符串
    // std::string str1 = "Hello", str2 = "World1"; // 定义两个字符串变量
    // std::cout << "Shorter string: " << shorter_string(str1, str2) << std::endl; // 输出较短的字符串
    
    // size_t scale_value = scale(5); // 调用scale函数，计算5倍的编译时常量
    // std::cout << "Scale value: " << scale_value << std::endl; // 输出计算结果
    // return EXIT_SUCCESS; // 或者使用宏定义的EXIT_SUCCESS, 来表示成功结束，但需要引入cstdlib库
    
    // 12. 调试函数的使用
    // print_debug(nullptr, 0); // 调用调试函数，传入空指针和大小为0    
    // size_t threshold = 10; // 定义一个阈值
    // std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; // 定义一个整数向量
    // 需要引入cassert头文件来使用assert断言
    // 但是如果加上-D NDEBUG编译选项，则不会调用所有的assert 和#ifndef NODEBUG下的语句。
    // assert(numbers.size() < threshold); // 使用assert断言，确保向量大小大于阈值


    // 13. 函数匹配
    // f1(3, 4); // 调用f1(int, int)版本
    // f1(4, 0); // 调用f1(int, int)版本
    // f1(4, 0.0); // 调用f1(int, double)版本
    // f1(3.0, 4.0) // 调用f1(double, double)版本

    // f1(3.14); 
    // 这里虽然f1(int) 和 f1(double, default) 都可以匹配，
    // 但是f1(int)需要隐式转换，符合候选函数要求，但是不符合可行函数要求，测排除

    // f1(3, 3.14); 
    // 如果只有f1(int, int) 和 f1(double, double) 两个候选函数，
    // 那么就会导致二义性错误，因为对于第一个参数前者可行，第二个参数后者可行。

    // 14. 函数指针的使用
    // myfunc2(myfunc, 42); // 调用myfunc2函数，传入函数指针和参数

    return 0; // 返回0表示程序正常结束
}
