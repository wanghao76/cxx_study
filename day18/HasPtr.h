#ifndef HASPTR_H
#define HASPTR_H

#include <iostream>
#include <string>

class HasPtr {

    friend void swap(HasPtr &lhs, HasPtr &rhs);

public: 
    HasPtr(const std::string &s = std::string()) :
        ps(new std::string(s)), i(0) {}

    HasPtr(const HasPtr& hpr) : ps(new std::string(*hpr.ps)), i(hpr.i) { 
        std::cout << "call the copy conductor function." << std::endl;
    }

    // HasPtr& operator=(const HasPtr& hpr);

    // copy and swap
    HasPtr& operator=(HasPtr hpr) {
        std::cout << "call the copy assignment function." << std::endl;
        swap(*this, hpr);
        return *this;
    }

    const std::string& getPs() const {
	    return *ps;
    }

    ~HasPtr() {
        delete ps;
    };
private:
    std::string *ps;
    int i;
};

inline 
void swap(HasPtr &lhs, HasPtr &rhs) {

    // 这里有个很微妙的点！！
    // 如果用using 这种写法
    // 编译器会首先看，交换的类成员中是否自己实现了swap
    // 如果实现了：优先用自己实现的
    // 没实现才会用标准库中的std::swap

    // ?这里留一个问题，为什么这里用了using，但是std::swap不会覆盖自定义swap呢？

    //答案：因为 ADL（Argument-Dependent Lookup） 机制。当调用 swap(lhs.ps, rhs.ps) 时：
    // 编译器首先在 HasPtr 的命名空间查找 swap（由于 ps 是 std::string*，ADL 不会生效）。
    // 如果没有找到，再通过 using std::swap 引入 std::swap。
    // 由于 std::string* 没有特化的 swap，最终调用的是 std::swap（即指针交换）。
    // 如果 ps 是一个类类型（比如 std::string 而非指针），ADL 会优先查找该类型的 swap 特化版本。

    using std::swap;
    swap(lhs.i, rhs.i);
    swap(lhs.ps, rhs.ps);
    std::cout << "call the swap function." << std::endl;
}

// 使用copy and swap技术实现拷贝赋值（绝佳）
// 这简单的两句解决了拷贝赋值的所有问题：
// 自赋值问题：不存在， 因为hpr是值传递，是hpr的一个副本，swap交换就就换了，hpr副本的销毁，不影响this pointer指向的对象
// new的异常问题：new发生异常必然在swap之前，因为在值传递的时候就进行拷贝构造了
// 之前的动态内存是否被释放：必然的，因为swap之后，hpr掌管着之前的string指针所指向的那片内存，
// 而由于hpr是一个临时对象，必然在离开函数作用域后被销毁，所以就会调用其对应的析构，从而delete掉对应的动态内存
// 因此不存在内存泄漏

// 妈的，谁他妈想出来了，真的妙！！！
inline 
HasPtr& HasPtr::operator=(HasPtr hpr) {
    std::cout << "call the copy assignment function." << std::endl;
    swap(*this, hpr);
    return *this;
}



#endif