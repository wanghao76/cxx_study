#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <algorithm>

class Complex {
public:
    Complex() = default; // 默认构造函数

    Complex(double value1, double value2) : x(value1), y(value2) {} // 带参数的构造函数

    double get_x() const {
        return x; // 返回一个double类型的值
    }

    double get_y() const {
        return y; // 返回一个double类型的值
    }


    // *成员函数的运算符重载实现
    // (可以选择成员/非成员，但是同一类型只能选择一个，否则编译器会不知道选哪个)
    // Complex& __doapl(Complex* ths, const Complex& other);
    // Complex& operator += (const Complex& other);

    // 成员函数（complex + double）实现
    // Complex operator + (double rhs);

    // 这里也可以选择用友元
    // 其实友元函数声明等价于一次普通的函数声明
    // 但是如果你希望在不包含类的地方也能用，比如其他的cpp文件，建议在类外再写一遍声明。
    friend Complex& __doapl(Complex& lhs, const Complex& rhs);
    friend Complex& operator += (Complex& lhs, const Complex& rhs);

    

private:

    // data几乎没有例外，要放到private里，而fuc()几乎没有例外，要放到public里
    double x; // 私有成员变量
    double y;
};

// *inline的定义方法
// 可以在类外，但是inline函数必须要在同一个头文件中，在另一个例如同名的cpp文件中，则会编译报错。

// *成员函数的类外定义
// 这里+=只有一个参数，是因为会有一个隐藏的this指针，指向当前对象。
// inline Complex& Complex::operator += (const Complex& other) {
//     return __doapl(this, other);
// }
// inline Complex& Complex::__doapl(Complex* ths, const Complex& other) {
//     ths->x += other.x;
//     ths->y += other.y;
//     return *ths;
// }

// 成员函数complex + double的实现。
// *但是注意用成员函数无法完整实现operator + 的所有功能。
// *例如double + complex就无法实现了。
// inline Complex Complex::operator+ (double rhs) {
//     std::cout << "operator + (complex, double) called" << std::endl;
//     return Complex(this->get_x() + rhs, this->get_y());
// }

// *非成员函数 + 友元实现类似效果
Complex& __doapl(Complex& lhs, const Complex& rhs);
// 注意，如果是非成员函数就没有this指针了，所以需要传入两个参数。
Complex& operator += (Complex& lhs, const Complex& rhs);


// *非成员函数的运算符重载
// 一定得return by value, 因为local的对象会被销毁，需要创建临时对象
// 如果这里return by reference, 那么会返回一个已经被销毁的对象的引用，导致未定义行为。
inline Complex operator + (const Complex& lhs, const Complex& rhs) {

    // *临时对象
    // 一般用在不需要知道他的名字，可能到下一行他的生命周期就结束了，临时的
    // 类似这种classname(), classname(double, double)的写法都是临时对象。
    std::cout << "operator + (complex, complex) called" << std::endl;
    return Complex(lhs.get_x() + rhs.get_x(), lhs.get_y() + rhs.get_y());
}

//* 注意为什么operator + 不写成成员函数
// 因为成员函数的左操作数必须是本身(this), 因此double+complex就不行了。
inline Complex operator + (const Complex& lhs, double rhs) {
    std::cout << "operator + (complex, double)called" << std::endl;
    return Complex(lhs.get_x() + rhs, lhs.get_y());
}

inline Complex operator + (double lhs, const Complex& rhs) {
    std::cout << "operator + (double, complex)called" << std::endl;
    return Complex(lhs + rhs.get_x(), rhs.get_y());
}

// 如果只有一个形参，那这里就是负号，+同理。会根据形参个数判断
inline Complex operator - (const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.get_x() - rhs.get_x(), lhs.get_y() - rhs.get_y());
}

inline Complex operator * (const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.get_x() * rhs.get_x(), lhs.get_y() * rhs.get_y());
}

inline Complex conj (const Complex& obj) {
    // 这里的conj是一个函数名，表示共轭操作
    // 例如复数的共轭操作
    return Complex(obj.get_x(), -obj.get_y());
}

// * 输出操作符重载
// 建议声明和定义成非成员函数， 因为变成成员函数的话，就变成了x << cout了。
// 就算写成员函数，也应到ostream的类里面。
// 也可以先声明再到Complex.cpp中定义，注意g++别忘记链接Complex.cpp文件了
std::ostream& operator << (std::ostream& os, const Complex& obj);
// 后面可以持续的定义


#endif // COMPLEX_H