#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <initializer_list>
#include <stdexcept>
#include <iterator>

#include "strBlob.h"

int main() {

    // shared_ptr 的使用
    // StrBlob s1;
    // std::cout << "s1 use count: " << s1.use_count() << std::endl;
    // std::cout << "s1 size: " << s1.size() << std::endl;

    // {
    //     StrBlob s2({"good", "morining", "guys"});
    //     s1 = s2;
    //     std::cout << "s2 use count: " << s2.use_count() << std::endl;
    //     std::cout << "s1 use count: " << s1.use_count() << std::endl;

    //     s2.push_back("hi");
    //     std::cout << "s2 size: " << s2.size() << std::endl;
    //     std::cout << "s1 size: " << s1.size() << std::endl;
    // }

    // std::cout << "s1 size: " << s1.size() << std::endl;
    // std::cout << "s1 use count: " << s1.use_count() << std::endl;


    StrBlob s;
    std::string tmp;
    while (std::cin >> tmp) {
        s.push_back(tmp);
    }

    StrBlobPtr sp(s, 0);

    while (true) {
        try {
            std::cout << sp.deref() << std::endl;
            sp.incr();
        } catch (std::runtime_error& e) {
            std::cerr << "Caught an runtime_error exception: " << e.what() << std::endl;
            break;
        } catch (std::out_of_range& e) {
            // 捕获特定的异常类型
            std::cerr << "Caught an out_of_range exception: " << e.what() << std::endl;
            break;
        } catch (...) {
            // 捕获所有其他类型的异常
            std::cerr << "Caught an unknown exception" << std::endl;
            break;
        }
    }
    return 0;
}