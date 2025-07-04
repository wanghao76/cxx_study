#include <iostream>
#include <algorithm>

#include "String.h"

std::allocator<char> String::alloc;

std::pair<char*, char*> 
String::alloc_n_copy(const char* begin, const char* end)
{
    auto newdata = alloc.allocate(end - begin);
    return {newdata, std::uninitialized_copy(begin, end, newdata)};
}

void String::range_initializer(const char *first, const char *last)
{
    auto newstr = alloc_n_copy(first, last);
    begin = newstr.first;
    end = newstr.second;
}

String::String(const char* s)
{
    char* sl = const_cast<char*>(s);
    while (*sl) {
        ++sl;
    }
    range_initializer(s, ++sl);
    std::cout << "String(const char*) constructor" << std::endl;
    // 这里的++sl是为了将字符串末尾的'\0'也包含
    // 在内，确保end指向'\0'的下一个位置。
}

String::String(const String& s)
{
    range_initializer(s.begin, s.end);
    std::cout << "copy constructor" << std::endl;
}

void String::free()
{
    if (begin) {
        // 这里不懂的话，见文档。
        std::for_each(begin, end, [this](char &x) {
            alloc.destroy(&x);
        });
        alloc.deallocate(begin, end - begin);
    }
}

String::~String()
{
    free();
    std::cout << "destructor" << std::endl;
}

String& String::operator=(const String& s)
{
    auto newstr = alloc_n_copy(s.begin, s.end);
    free();
    begin = newstr.first;
    end = newstr.second;
    std::cout << "copy-assignment" << std::endl;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const String& s)
{
    os <<  "string value: " << s.begin << std::endl;
    return os;
}