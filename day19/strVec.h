#ifndef STRVEC_H
#define STRVEC_H

#include <iostream>
#include <memory>
#include <string>
#include<initializer_list>

class strVec
{
public:
    strVec() : 
        elements(nullptr), first_free(nullptr), cap(nullptr) {  };
    strVec(const std::initializer_list<std::string>& sl);

    strVec(const strVec&);
    strVec& operator=(const strVec&);
    ~strVec();

    strVec(strVec&& s) noexcept;
    strVec& operator=(strVec&& s) noexcept;

    // 可以尝试把成员函数也提供两个版本，一个拷贝元素，一个移动元素
    // 一般来叔用移动元素效率更高更快，但是要注意移后源元素必须不再使用，除非赋值和销毁
    // 接受任何可以转为X类型的版本
    void push_back(const std::string&);
    // 接受一个可修改的右值
    void push_back(std::string&&);

    std::size_t size() const {
        return first_free - elements;
    }
    std::size_t capacity() const {
        return cap - elements;
    }

    std::string* begin() const {
        return elements;
    }

    std::string* end() const {
        return first_free;
    }


private:
    static std::allocator<std::string> alloc; // 分配元素

    void reserve(std::size_t n);
    void alloc_n_move(std::size_t capacity);
    
    void resize(std::size_t n);
    void resize (std::size_t n, const std::string& s);

    void reallocate();
    void free();

    void chk_n_alloc() {
        if (size() == capacity() ) {
            reallocate();
        }
    }
    std::pair<std::string*, std::string*> alloc_n_copy 
            (const std::string*, const std::string*);
    
    std::string *elements;   //指向数组首元素的指针
    std::string *first_free; //指向数组第一个空闲元素的指针
    std::string *cap;  // 指向数组尾后位置的指针
};

#endif