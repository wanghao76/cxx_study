#include <iostream>
#include <algorithm>

#include "strVec.h"

std::allocator<std::string> strVec::alloc;

void strVec::push_back(const std::string& str) {
    // 确保有空间容纳新元素
    chk_n_alloc();
    // 在分配的内存中构造，first_free指向下一个空闲空间
    alloc.construct(first_free++, str);
    std::cout << "call copy constuctor push back" << std::endl;
}

void strVec::push_back(std::string&& s) {
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));
    std::cout << "call move constructor push back" << std::endl;
}

std::pair<std::string*, std::string*>
strVec::alloc_n_copy (const std::string* begin, const std::string* end)
{
    // 分配空间
    auto data = alloc.allocate(end - begin);
    // 按照给定的begin和end进行构造，并返回构造后的首指针和尾后
    return {data, std::uninitialized_copy(begin, end, data)};
}

void strVec::free()
{
    if (elements) {
        for (auto p = first_free; p != elements; /* blank */) {
            alloc.destroy(--p);
        }
        if (cap && cap > elements) {
            // 释放分配的内存
            alloc.deallocate(elements, cap - elements);
        }
    }

    // alloc.destroy()
}

strVec::strVec(const strVec& sv)
{
    auto it = alloc_n_copy(sv.begin(), sv.end());
    elements = it.first;
    first_free = cap = it.second;
}

strVec::strVec(const std::initializer_list<std::string>& sl)
{
    auto newdata = alloc_n_copy(sl.begin(), sl.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

strVec::~strVec() 
{
    free();
}

strVec& strVec::operator=(const strVec& sv)
{   
    // 放在前面避免字符值
    auto new_data = alloc_n_copy(sv.begin(), sv.end());
    free();
    elements = new_data.first;
    first_free = cap = new_data.second;
    return *this;
}

void strVec::reallocate()
{
    // 每次扩张 * 2
    std::size_t new_capacity = size() ? size() * 2 : 1;
    
    // 分配新内存
    auto newdata = alloc.allocate(new_capacity);
    // std::string* elem = elements; // 旧数组下一个元素
    // std::string* dest = newdata; // 新数组下一个空闲位置
    // for (std::size_t i = 0; i < size(); ++i) {
        // std::move的作用类似于拷贝指向string的指针，而不是拷贝元素
        // 相当于没有重新开辟内存空间，只是新数组接管了其使用权而已。
        // 目的在于节省内存开销。
    //     alloc.construct(dest++, std::move(*elem++));
    // }

    // 也可以不用for循环，直接用移动迭代器，将左值转为右值迭代器
    // 由于传的是右值，因此construct会使用移动构造
    auto last = std::uninitialized_copy(std::make_move_iterator(begin()),
                                        std::make_move_iterator(end()), newdata);
    free(); // 构造完，即释放旧的内存空间

    // 更新数据结构
    elements = newdata;
    first_free = last;
    cap = elements + new_capacity;
}

void strVec::alloc_n_move(size_t capacity)
{
    auto newdata = alloc.allocate(capacity);

    auto dest = newdata;
    auto elem = elements;

    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free(); // 释放旧的内存空间
    elements = newdata;
    first_free = dest;
    cap = elements + capacity;
}

void strVec::reserve(size_t n)
{
    if (n <= capacity()) return;
    alloc_n_move (n);
}

void strVec::resize(size_t n)
{
    resize(n, "");
}

void strVec::resize(size_t n, const std::string& s)
{
    if (n > size()) {
        if (n > capacity()) {
            reserve(n);
        }

        for (size_t i = size(); i < n; ++i) {
            alloc.construct(first_free++, s);
        }
    }
    else if (n < size()) {
        while ((elements+n) != first_free) {
            alloc.destroy(--first_free);
        }
    }
}

// 移动构造不会分配空间,只是接管
// 因此通常也不会报异常,为了防止编译器认为可能发生异常而做一些不必要的操作,我们加上noexcept
// 注意在声明和定义中都要加,except 加在 函数调用符 和 冒号 之间.
strVec::strVec(strVec&& s) noexcept :
elements(s.elements), first_free(s.first_free), cap(s.cap) // 接管s中的资源
{
    // 移动构造结束后,移动源对象会被销毁,因此会调用析构
    // 因此如果不把这些指针指为nullptr, 则会把this对象接管的资源给销毁了.
    s.elements = s.first_free = s.cap = nullptr;
}

strVec& strVec::operator=(strVec&& s) noexcept
{
    if (this != &s) {
        // 释放原有内存
        free();

        // 接管s中的资源
        elements = s.elements;
        first_free = s.first_free;
        cap = s.cap;

        // 将s置为可析构状态.
        s.elements = s.first_free = s.cap = nullptr;
    }

    return *this;
}

// 无需检查自身赋值的情况，因为initializer_list保证il不是自身。
strVec& strVec::operator=(const std::initializer_list<std::string> il)
{
    auto newdata = alloc_n_copy(il.begin(), il.end());
    free();
    elements = newdata.first;
    first_free = cap = newdata.second;
    return *this;
}