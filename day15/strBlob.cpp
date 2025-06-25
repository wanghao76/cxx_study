#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include<initializer_list>


#include "strBlob.h"

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>> ()) { }

StrBlob::StrBlob(std::initializer_list<std::string> sl) : 
                    data(std::make_shared<std::vector<std::string>> (sl)) { }

std::string& StrBlob::front() {
    check(0, "front on empty strBlob");
    return data->front();
}

std::string& StrBlob::back() {
    check(0, "back on empty strBlob");
    return data->back();
}

void StrBlob::pop_back() {
    check(0, "pop back on empty strBlob");
    data->pop_back();
}

void StrBlob::check(size_type t, const std::string& msg) const
{
    if (t >= data->size()) {
        throw std::out_of_range(msg);
    }
}

std::shared_ptr<std::vector<std::string>> 
StrBlobPtr::check(std::size_t i, const std::string& msg) const
{
    auto ret = wptr.lock();

    if (!ret) {
        throw std::runtime_error("unbound strBlobPtr!");
    }

    if (i >= ret->size()) {
        throw std::out_of_range(msg);
    }


    return ret;
}   

std::string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return p->at(curr);
}

StrBlobPtr& StrBlobPtr::incr() 
{
    auto p = check(curr, "increment past the end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
}

