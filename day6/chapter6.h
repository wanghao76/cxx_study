#ifndef FACT_H
#define FACT_H

#include <iostream>

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

#endif // FACT_H