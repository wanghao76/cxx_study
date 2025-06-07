#ifndef FACT_H
#define FACT_H

#include <iostream>
#include <string>

#define CONSTEXPR_VALUE 10

/**
 * @brief 计算非负整数的阶乘
 * @param val 要计算阶乘的非负整数
 * @return 返回计算得到的阶乘结果，如果输入无效（如负数），则返回-1并输出错误信息
 */
int fact(int val);

/**
 * @brief 交换两个整数的值
 * @param a 指向第一个整数的指针
 * @param b 指向第二个整数的指针
 * @return 返回0表示成功，返回-1表示错误（如传入空指针）
 */
int swap(int *a, int *b);

/**
 * @brief 打印整型数组的所有元素。
 * @param a 指向整型数组的指针。
 * @param s 数组元素的个数。
 * @return 返回0表示成功，返回-1表示错误（如传入空指针）
 */
int print (const int *a, size_t s);

/**
 * @brief 错误代码枚举
 * @details 用于表示不同的错误类型
 */
enum class ErrCode { OK, INVALID, NULLPTR, UNKNOWN };

/**
 * @brief 计算整数列表的和
 * @param il 整数列表
 * @return 返回列表中所有整数的和
 * @details 使用std::initializer_list来接收任意数量的整数
 * @note std::initalizer_list 只能接受同一类型的元素，且不能修改其内容。不同类型可以用* 省略号(...)来接收。
 */ 
int sum_list(std::initializer_list<int> il);

// 例如：
// int get_param(int size, ...);

/**
 * @brief 输出错误信息
 * @param e 错误代码
 * @param il 错误信息列表
 * @details 根据错误代码输出相应的错误信息
 */
void error_msg (ErrCode e, std::initializer_list<std::string> il);


// 这两因为int可以隐式转换为const int，所以这两种函数是等价的
// void f1(int, int);
// void f1(const int, const int);

// 但是f1(const double, const int)和f1(int, int)是不同的函数
// void f1(const double, const int);

// 默认参数
// void f1(double height, int weight = 3, int age = 18);

/**
 * @brief 返回较短的字符串
 * @param str1 第一个字符串
 * @param str2 第二个字符串
 * @return 返回较短的字符串的引用
 * @details 如果两个字符串长度相同，则返回第一个字符串
 * @note 1. 此函数使用了内联函数特性以提高性能。一般来说，内联函数适合小而频繁调用的函数。
 * @note 2. 其特点是能够直接在调用处展开，减少函数调用的开销。
 * @note 3. inline函数的实现通常在头文件中定义，以便在多个源文件中共享，否则会导致链接错误。
 */
inline const std::string &
shorter_string(const std::string& str1, const std::string& str2) {
    return (str1.size() < str2.size()) ? str1 : str2;
}

/**
 * @brief 获取编译时常量的值
 * @return 返回一个编译时常量的值
 * @details 该函数使用了constexpr特性，允许在编译时计算其值。
 * @note 1. constexpr函数在编译时求值，可以用于常量表达式。
 * @note 2. 这使得它们可以在编译时进行优化，提高性能。
 */
constexpr int get_constexpr_value() {
    return CONSTEXPR_VALUE; // 使用宏定义的编译时常量
}

/**
 * @brief 计算一个数的缩放值
 * @param cnt 要缩放的数
 * @return 返回缩放后的值
 * @details 该函数使用了constexpr特性，允许在编译时计算其值。
 * @note 1. 但是必须遵循以下规则：返回类型和所有形参类型必须是字面值类型。
 * @note 2. 必须只能有一个return语句。
 */
constexpr size_t scale (size_t cnt) {
    return get_constexpr_value() * cnt; // 使用constexpr函数
}

// 函数匹配实验
// void f1();
// void f1(int x);
// void f1(double x);
// void f1(int x, int y);
// void f1(int x, double y); 
// void f1(double x, double y = 1.143);

#endif // FACT_H