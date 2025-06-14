#include <iostream>
#include <bitset>
#include <climits>

template <typename T>
void compare_multiplication(T x, T y) {
    // 将有符号数转换为对应的无符号数（二进制表示不变）
    typename std::make_unsigned<T>::type ux = x;
    typename std::make_unsigned<T>::type uy = y;
    
    // 有符号乘法并截断
    T signed_result = x * y;
    // 无符号乘法并截断
    typename std::make_unsigned<T>::type unsigned_result = ux * uy;
    
    // 转换为相同大小的bitset
    std::bitset<sizeof(T) * CHAR_BIT> signed_bits(signed_result);
    std::bitset<sizeof(T) * CHAR_BIT> unsigned_bits(unsigned_result);
    
    std::cout << "有符号数 x: " << x << " (二进制: " << std::bitset<sizeof(T) * CHAR_BIT>(x) << ")\n";
    std::cout << "有符号数 y: " << y << " (二进制: " << std::bitset<sizeof(T) * CHAR_BIT>(y) << ")\n";
    std::cout << "无符号数 x': " << ux << " (二进制: " << std::bitset<sizeof(T) * CHAR_BIT>(ux) << ")\n";
    std::cout << "无符号数 y': " << uy << " (二进制: " << std::bitset<sizeof(T) * CHAR_BIT>(uy) << ")\n";
    
    std::cout << "\n有符号乘法结果: " << signed_result << " (二进制: " << signed_bits << ")\n";
    std::cout << "无符号乘法结果: " << unsigned_result << " (二进制: " << unsigned_bits << ")\n";
    
    if (signed_bits == unsigned_bits) {
        std::cout << "\n结果: 二进制表示相同\n";
    } else {
        std::cout << "\n结果: 二进制表示不同\n";
    }
    std::cout << "----------------------------------------\n";
}

int main() {

    // int x = -1;
    // unsigned int y = 0;

    // if (x < y) {
    //     std::cout << x << " is less than " << y << std::endl; // 如果x小于y，输出提示信息
    // } else {
    //     std::cout << x << " is greater than " << y << std::endl; // 如果x小于y，输出提示信息
    // }
    // 测试8位整数
    std::cout << "测试8位整数:\n";
    int8_t x8 = 5;
    int8_t y8 = -3;
    compare_multiplication(x8, y8);
    
    x8 = -127;
    y8 = -127;
    compare_multiplication(x8, y8);
    
    // 测试16位整数
    std::cout << "\n测试16位整数:\n";
    int16_t x16 = 12345;
    int16_t y16 = -23456;
    compare_multiplication(x16, y16);
    
    // 测试32位整数
    std::cout << "\n测试32位整数:\n";
    int32_t x32 = 123456789;
    int32_t y32 = -987654321;
    compare_multiplication(x32, y32);
    
    return 0;
}