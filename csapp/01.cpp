#include <iostream>

// 用位级运算实现交换函数
void inplace_swap(int *x, int *y) {
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

int main() {
    int a = 1, b = 2;

    std::cout << "a: " << a << " b: " << b << std::endl;

    inplace_swap(&a, &b);

    std::cout << "a: " << a << " b: " << b << std::endl;

    return 0;
}