#include <iostream>
#include <vector>

#include "String.h"
#include "strVec.h"

// Test reference to http://coolshell.cn/articles/10478.html

void foo(String x)   // copy constructor
{
    std::cout << x.c_str() << std::endl;    
    
} // destructor

void bar(const String& x)
{
    std::cout << x.c_str() << std::endl;
}

String baz()
{
    String ret("world");  // String(const char*) constructor
    return ret; // copy constructor
    
}

int main()
{
    // char text[] = "world";

    // String s0;   // default constructor
    // String s1("hello");  // String(const char*) constructor
    // String s2(s0);   // copy constructor
    // String s3 = s1;  // copy constructor
    // String s4(text);    // String(const char*) constructor
    // s2 = s1;   // copy-assignment

    // foo(s1);
    // bar(s1);
    // foo("temporary");   // String(const char*) constructor
    // bar("temporary");    // String(const char*) constructor
    // String s5 = baz();    // copy constructor

    // std::vector<String> svec;
    // svec.reserve(1);
    // svec.push_back(s0);
    // std::cout << svec.capacity() << std::endl;
    // std::cout << "--------------------------" << std::endl;
    // svec.push_back(s1);
    // std::cout << svec.capacity() << std::endl;
    // std::cout << "--------------------------" << std::endl;

    // svec.push_back(s2);
    // std::cout << svec.capacity() << std::endl;
    // std::cout << "--------------------------" << std::endl;

    // svec.push_back(s3);
    // std::cout << svec.capacity() << std::endl;
    // std::cout << "--------------------------" << std::endl;

    // svec.push_back(s4);
    // std::cout << svec.capacity() << std::endl;
    // std::cout << "--------------------------" << std::endl;

    // svec.push_back(s5);
    // std::cout << svec.capacity() << std::endl;
    // std::cout << "--------------------------" << std::endl;

    // svec.push_back(baz());
    // std::cout << svec.capacity() << std::endl;
    // std::cout << "--------------------------" << std::endl;

    // svec.push_back("good job");
    // std::cout << svec.capacity() << std::endl;
    // std::cout << "--------------------------" << std::endl;


    // 每次push_back都会调用一次拷贝构造。
    // 而且空间不足的时候,把原来元素拷贝到新空间中去, 也会再一次调用拷贝构造
    // 当然现在编译器也会做优化,这些考量都是没有优化的结果,

    // for (const auto &s : svec) {
    //     std::cout << s.c_str() << std::endl;
    // }

    // strVec vec;
    // std::string s = "something or other";
    // vec.push_back(s);
    // vec.push_back("done");

    String s1("hello"); 
    std::cout << s1;

    return 0;
}