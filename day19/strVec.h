#ifndef STRVEC_H
#define STRVEC_H

#include <iostream>
#include <memory>
#include <string>
#include<initializer_list>

class strVec
{
    strVec() : 
        elements(nullptr), first_free(nullptr), cap(nullptr) {  };
    strVec(std::initializer_list<std::string>& sl);

    strVec(const strVec&);
    strVec& operator=(const strVec&);
    ~strVec();

    strVec(strVec&& s) noexcept;
    strVec& operator=(strVec&& s) noexcept;

    void push_back(const std::string&);

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

    void alloc_n_move(std::size_t capacity);
    void reserve(std::size_t n);
    
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