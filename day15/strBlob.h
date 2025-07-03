#ifndef STRBLOB_H
#define STRBLOB_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <initializer_list>
#include <stdexcept>

class StrBlobPtr;

class StrBlob {

public:
    typedef std::vector<std::string>::size_type size_type;

    StrBlob();
    StrBlob(std::initializer_list<std::string> sl);


    StrBlobPtr begin();
	StrBlobPtr end();

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    size_type use_count() const { return data.use_count(); }


    // add & delete
    void push_back(const std::string& x) { data->push_back(x); }
    void push_back(std::string&& x) { data->push_back(std::move(x)); }
    void pop_back();

    // visit
    std::string& front();
    std::string& back();
    
    // 伴随类
    friend StrBlobPtr;
private:
    // 动态内存
    std::shared_ptr<std::vector<std::string>> data; 
    void check(size_type t, const std::string& msg) const;
};

// 伴随类
class StrBlobPtr {

public:
    StrBlobPtr() : curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    std::string& deref() const;
    StrBlobPtr& incr();

private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

#endif