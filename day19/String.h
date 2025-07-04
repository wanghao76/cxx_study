#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <memory>
#include <algorithm>
#include <cstring>

class String {

friend std::ostream& operator<<(std::ostream& os, const String& s);

public:
    String() : begin(nullptr), end(nullptr) { std::cout << "default constructor" << std::endl; }
    String(const char *);
    String(const String&);
    String& operator=(const String&);
    ~String();

    const char* c_str() const { return begin; }
    std::size_t size() const { return end - begin; }
    std::size_t length() const { return end - begin - 1; }


private:
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    void range_initializer(const char*, const char*);
    void free();

private:
    static std::allocator<char> alloc;
    char* begin;
    char* end;
};

std::ostream& operator<<(std::ostream& os, const String& s);

#endif