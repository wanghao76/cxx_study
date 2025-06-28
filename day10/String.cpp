#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stdio.h>
#include "String.h"

String::String(const char* c_str)
{
    if (c_str) {
        m_data = new char[std::strlen(c_str) + 1];
        std::strcpy(m_data, c_str);
    } else {
        m_data = new char[1];
        *m_data = '\0';
    }
}

String::~String()
{
    delete[] m_data;
}

String::String(const String& str)
{
    m_data = new char[std::strlen(str.m_data) + 1];
    std::strcpy(m_data, str.m_data);
}

String& String::operator=(const String& str)
{
    // self assignment check
    if (this == &str) {
        return *this;
    }

    delete[] m_data; // 赋值之前先释放原本指向的内存，防止memory leak
    m_data = new char[std::strlen(str.m_data) + 1];
    std::strcpy(m_data, str.m_data);
    return *this;
}