#ifndef FOO_H
#define FOO_H

#include <iostream>
#include <vector>
#include <initializer_list>

class Foo {

public:
    Foo() = default;
    Foo(const std::vector<int>& ivec) : data(ivec) {}
    Foo(const std::initializer_list<int> il) : data(il) { std::cout << "initializer_list" << std::endl; }

    Foo sort() const &;
    Foo sort() &&;

    std::vector<int>& get_data() {
        return data;
    }

private:
    std::vector<int> data;
};


#endif