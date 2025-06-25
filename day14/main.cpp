#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <unordered_set>


class Sales_data {

public:
    Sales_data() = default;
    Sales_data(std::string bn) : bookNo(bn) {}
    const std::string isbn() const { return bookNo; }
    friend bool compareIsbn(const Sales_data &lhs, const Sales_data& rhs);

private:
    std::string bookNo = "1001"; 

};

bool eqOp(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() == rhs.isbn();
}

// 这是一个简单的函数，通过isbn的值来判断两个Sales_data对象是否相等
// std::hash<std::string>() 创建了一个哈希函数对象，你可以像调用函数一样用它来对字符串求哈希
// 用标准库的字符串哈希算法，对 sd.isbn() 返回的字符串（即 ISBN 编号）计算哈希值。
// 结果是一个 size_t 类型的整数，这个整数就是哈希值。
size_t hasher(const Sales_data &sd) {
    return std::hash<std::string>()(sd.isbn());
}

// 4. 为什么要这样写？
// 当你把自定义类型（如 Sales_data）放进 std::unordered_set、std::unordered_map 等无序容器时，容器需要知道如何为你的类型生成哈希值。
// 你只要告诉容器：“我的哈希值就是用 ISBN 字符串的哈希值”，这样就能用标准库的高效哈希算法来管理你的对象。

// ? 那是不是以后如果需要特定的规则来存储元素，就可以用无序容器呢？

// 注意：如果Sales_data类中有其他成员变量需要参与比较，也可以这样实现
// size_t hasher(const Sales_data &sd) {
//     size_t h1 = std::hash<std::string>()(sd.isbn());
//     size_t h2 = std::hash<int>()(sd.units_sold);
//     size_t h3 = std::hash<double>()(sd.revenue);
//     return h1 ^ (h2 << 1) ^ (h3 << 2); // 简单合并
// }


int main () {
    // std::map<std::string, std::size_t> word_count;
    // std::string word;

    // while (std::cin >> word) {
    //     ++word_count[word];
    // }

    // for (const auto &it : word_count) {
    //     std::cout << "name: " << it.first << " " << "times: "
    //     << it.second << " time." << std::endl;
    // }

    // std::map<std::string, std::vector<std::string>> familes = {
    //     { "wang",  { "xiangyang  ", "weiyang", "weiping", "hao", "heng" } },
    //     { "zhu", { "shihao", "yifan", "zeji" } }
    // };

    // std::ostream_iterator<std::string> out_iter(std::cout, " ");
    // for (const auto &f : familes) {
    //     std::cout << "famliy: " << f.first << std::endl;
    //     std::copy(f.second.begin(), f.second.end(), out_iter);
    //     std::cout << std::endl;
    //     std::cout << "--------------------------------" << std::endl;
    // }
    // std::cout << familes["wanghao"] << std::endl;

    // set ： 有序 + 无重复关键字
    // std::set<int> s_int = {2, 3, 1, 6, 6,  0};
    // for (auto &it : s_int) {
    //     std::cout << it << " ";
    // }
    // std::cout << std::endl;
    // 0 1 2 3 6 

    // std::map<int, std::string> menu = {
    //     { 4, "aa"},
    //     { 2, "aa"},
    //     { 2, "aa"},
    //     { 1, "bb" },
    //     {3, "cc"}
    // };

    // map: 有序 + 无重复关键字 （按关键字来排序， 按关键字来决定是否重复）
    // for (auto &it : menu) {
    //     std::cout << "key: " << it.first << " | " << "value: " << it.second << std::endl;
    // }
    // key: 1 | value: bb
    // key: 2 | value: aa
    // key: 3 | value: cc
    // key: 4 | value: aa

    // 如果要把类放进去，则需要自定义比较 "<"
    // std::multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);

    // pair的简单使用
    // std::vector<std::pair<std::string, int>> res;
    // std::string x;
    // int y;
    // while (std::cin >> x) {
    //     if (!std::cin.fail()) {
    //         std::cin >> y;
    //     }
    //     // 创建pair的三种方法
    //     // res.push_back(std::make_pair(x,y));
    //     res.push_back(std::pair<std::string, int>(x,y));
    //     // res.push_back({x,y});
    // }

    // for (auto &it : res) {
    //     std::cout << "first: " << it.first << " | second: " << it.second << std::endl;
    // }

    // std::map<int, std::string> s;
    // int counter = 0;
    // std::string x;
    // while (std::cin >> x) {
    //     if (x == "exit") {
    //         break;
    //     }
    //     s[counter++] = x;  // 或者 s.insert({counter++, x});
    // }
    // std::cout << "aaaaaa"<< std::endl;
    // auto iter = s.begin();
    // iter->second = "good";

    // for (auto& it : s) {
    //     std::cout << it.first << " | " << it.second << std::endl;
    // }

    // insert返回值
    // insert返回的是一个pair，first是指向给定关键字的元素，second插入是否成功（无重复true, 有重复false）
    // std::map<std::string, std::size_t> word_count;
    // std::string word;
    // while (std::cin >> word) {
    //     auto res = word_count.insert(std::make_pair(word, 1));
    //     if (!res.second) {
    //         res.first->second++;
    //     }
    // }

    // for (auto& it : word_count) {
    //     std::cout << it.first << " | " << it.second << std::endl;
    // }

    // std::multimap<std::string, std::string> authors = {
    //     {"john", "spirit"},
    //     {"jack", "ssss"},
    //     {"mary", "happiness"},
    //     {"john", "goods"},
    //     {"aspirin", "apple"},
    //     {"john", "soldier"}
    // };

    // 删除元素
    // std::size_t cnt = authors.erase("john");
    // std::cout << cnt << std::endl;

    // 删除元素的另一种实现方法
    // auto it = authors.find("john");
    // auto cnt = authors.count("john");
    // while (cnt) {
    //     if (it == authors.end()) {
    //         break;
    //     }
         // 动态更新迭代器，因为erase后旧迭代器会失效。
    //     it = authors.erase(it);
    //     cnt--;
    // }

    // for (auto& it : authors) {
    //     std::cout << it.first << " | " << it.second << std::endl;
    // }

    // multimap打印key值对应的所有元素的三个方法：
    // 方法一：因为都是有序的，所以key值相等的元素肯定相邻排列：
    // std::size_t cnt = authors.count("john");
    // auto it = authors.find("john");
    // while (cnt != 0) {
    //     std::cout << "name: " << it->first  << " | book: " << it->second << std::endl;
    //     --cnt;
    //     ++it;
    // }

    // 方法二：使用lower_bound （返回第一个<=key的元素迭代器） 和 upper_bound （返回第一个>key的元素迭代器）
    // 当元素存在时：即其范围；不存在时：两者相等，且指向按照排列顺序的最佳插入位置。
    // for (auto begin = authors.lower_bound("john"), end = authors.upper_bound("john"); 
    //         begin != end; ++begin) {
    //     std::cout << "name: " << begin->first  << " | book: " << begin->second << std::endl;
    // }

    // 方法三：使用equal_range, 返回一个pair，first等价于lower_bound, second等价于upper_bound
    // 若元素不存在，first和second都指向最佳插入位置。
    // for (auto pos = authors.equal_range("john"); pos.first != pos.second; ++pos.first) {
    //     std::cout << "name: " << pos.first->first  << " | book: " << pos.first->second << std::endl;
    // }

    // 无序容器自定义类型需要重载=运算符和hash函数
    using SD_multi_set = std::unordered_multiset<Sales_data,
        decltype(hasher)*, decltype(eqOp)*>;
    // 10 是桶的数量
    // 通过哈希函数映射到bucket, 然后顺序查找需要的值
    // 桶的数量和容量以及hash函数的质量决定了这个无序容器的性能。
    SD_multi_set bookstore(10, hasher, eqOp);

    return 0;
}


bool compareIsbn(const Sales_data &lhs, const Sales_data& rhs) {
    return lhs.isbn() < rhs.isbn();
}
