#include <iostream>
#include <memory>
#include <string>
#include <cstring>

#include <stdio.h>
#include <string.h>
int main() {

    // std::unique_ptr<std::string> p(new std::string("hhhh"));
    // std::unique_ptr<std::string> q(new std::string("hello world!"));
    // q.reset(p.release());
    // std::cout << *q << std::endl;
    // q.reset(nullptr);


    // 错误示例
    // int ix = 43;
    // int* p = &ix;
    // std::unique_ptr<int> q(p);  // 不能这样，因为保存的是栈地址，delete会报错，应该用new
    // std::cout << *q << std::endl;

    return 0;
}