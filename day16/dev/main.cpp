#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <vector>

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

    // 可以利用allocate将构造和分配内存空间分开，以防止不必要的浪费。
    // std::allocator<std::string> alloc;
    // std::size_t n = 10;

    // // 分配内存空间
    // auto const p = alloc.allocate(n);

    // // 构造所有string对象
    // std::size_t i = 0;
    // while (i < n) {
    //     alloc.construct(p + i, 10, 'c');
    //     ++i;
    // }

    // // 输出所有string对象
    // std::size_t tmp = i;
    // while (tmp > 0) {
    //     std::cout << p[--tmp] << std::endl;
    // }

    // // 销毁所有string对象
    // while (i > 0) {
    //     --i;
    //     alloc.destroy(p + i);
    // }
    // alloc.deallocate(p, n);


    std::vector<std::string> vec = {"hello", "world", "this", "is", "a", "test"};
    std::allocator<std::string> alloc;
    auto p = alloc.allocate(vec.size() * 2);

    auto q = p;
    try {
        q = std::uninitialized_copy(vec.begin(), vec.end(), p);  // 可能抛出异常
        std::uninitialized_fill_n(q, vec.size(), "default");    // 可能抛出异常
    } catch (...) {
        // 异常时销毁已构造的对象
        while (q != p) {
            alloc.destroy(--q);
        }
        alloc.deallocate(p, vec.size() * 2);
        throw;  // 重新抛出异常
    }

    // 正常流程
    for (auto it = p; it != q + vec.size(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 销毁和释放
    for (auto it = p; it != q + vec.size(); ++it) {
        alloc.destroy(it);
    }
    alloc.deallocate(p, vec.size() * 2);
    return 0;
}