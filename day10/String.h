#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <algorithm>

class String
{
public:
    String(const char* c_str = nullptr);

    // 类中有指针一定要有拷贝构造和拷贝赋值，以及对应的析构（简称Big Three）
    // 因为不这样做，用编译器默认拷贝动作的话，只是会浅拷贝，导致被赋值的那个对象原来指向的那片内存未被释放，进而引发memory leak.
    String(const String& str);
    String& operator=(const String& str);    
    ~String();

    char* get_c_str() const { return m_data; }

private:
    char* m_data;
};

inline
std::ostream& operator<<(std::ostream& os, const String& str)
{
    // std::cout 本就解释一个字符串指针，打印出对应的字符串
    return os << str.get_c_str();
}

#endif