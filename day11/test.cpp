#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <forward_list>
#include <string>

bool insert_flist(std::forward_list<std::string>& f_list, const std::string& str1, const std::string& str2);

int main() {

    // std::vector<int> numbers = {1, 2, 3, 4, 5};


    // numbers.erase(numbers.end());

    // std::cout << "After erase: ";
    // for (const auto& num : numbers) {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;

    // 一定要检查大小，这种下标运算！！
    // auto val1 = numbers.begin();
    // auto val2 = numbers.end();
    // auto val3 = numbers.front();
    // auto val4 = numbers.at(0);

    // std::cout << "val1: " << *val1 << std::endl;
    // std::cout << "val2: " << *(val2 - 1) << std::endl;
    // std::cout << "val3: " << val3 << std::endl;
    // std::cout << "val4: " << val4 << std::endl;

    // erase 使用


    // 传入相等的迭代器，啥也不会删除
    // auto elem1 = numbers.begin() + 2;
    // numbers.erase(elem1, elem1);

    // std::cout << "After erase: ";
    // for (const auto& num : numbers) {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;
    // After erase: 1 2 3 4 5

    // 传入尾后迭代器，会把elem1以及其之后的所有元素删除
    // auto elem1 = numbers.begin() + 2;

    // auto elem2 = numbers.end();
    // numbers.erase(elem1, elem2);

    // std::cout << "After erase: ";
    // for (const auto& num : numbers) {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;
    // After erase: 1 2

    // 传入两个尾后迭代器，也是啥也不会删除
    // auto elem2 = numbers.end();
    // numbers.erase(elem2, elem2);

    // std::cout << "After erase: ";
    // for (const auto& num : numbers) {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;


    // erase 实践
    // int a[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    // std::array<int, 11> a = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };


    // std::vector<int> num_vec;
    // std::list<int> num_list;

    // 将数组元素添加到vector中
    // for (int i = 0; i < sizeof(a) / sizeof(int); ++i) {
    //     num_vec.push_back(a[i]);
    // }

    /**
     * * sizeof(a) / sizeof(int)
     * 使用这种的方式来获取数组 a 的元素个数，这种方式有以下几个问题：
     * 1. 类型依赖性强：如果 a 的类型从 int 改为 long 或其他类型，必须手动修改 sizeof(int)，否则会出错。
     * 2. 容易误用：如果 a 退化为指针（例如传递给函数），sizeof(a) 会返回指针大小，而不是数组大小，导致错误。
     * 3. 可读性较差：对于不熟悉 sizeof 用法的开发者来说, 这段代码可能不够直观。 
     */

    // for (decltype(a.size()) i = 0; i < a.size(); ++i) {
    //     num_vec.push_back(a[i]);
    // }

    // std::cout << "Vector elements: ";
    // for (const auto& n : num_vec) {
    //     std::cout << n << " ";
    // }
    // std::cout << std::endl;

    // 使用迭代器将vector中的元素添加到list中
    // for (std::vector<int>::const_iterator it = num_vec.cbegin(); it != num_vec.cend(); ++it) {
    //     num_list.push_back(*it);
    // }

    // std::cout << "List elements: ";
    // for (const auto& n : num_list) {
    //     std::cout << n << " ";
    // }
    // std::cout << std::endl;

    // 使用迭代器删除list奇数元素
    // auto it_list = num_list.begin();
    // while (it_list != num_list.end()) {
    //     if (*it_list % 2) {
    //         it_list = num_list.erase(it_list); // 删除奇数元素
    //     } else {
    //         ++it_list;
    //     }
    // }

    // std::cout << "List after removing odd elements: ";
    // for (const auto& n : num_list) {
    //     std::cout << n << " ";
    // }
    // std::cout << std::endl;

    // 使用迭代器删除vec偶数元素
    // auto it_vec = num_vec.begin();
    // while (it_vec != num_vec.end()) {
    //     if (*it_vec % 2 == 0) {
    //         it_vec = num_vec.erase(it_vec); // 删除偶数元素
    //     } else {
    //         ++it_vec;
    //     }
    // }

    // std::cout << "Vector after removing even elements: ";
    // for (const auto& n : num_vec) {
    //     std::cout << n << " ";
    // }
    // std::cout << std::endl;


    // forward 实践
    // 其实forward就是一个单向链表，你需要有个前驱，才能删除你要制定的元素，不然你无法改变你的前驱的指向
    // std::forward_list<int> f_list = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // auto it_prev = f_list.before_begin();
    // auto it_curr = f_list.begin(); 

    // while (it_curr != f_list.end()) {
    //     if (*it_curr % 2 == 0) {
    //         it_curr = f_list.erase_after(it_prev);
    //     } else {
    //         it_prev = it_curr;
    //         ++it_curr;
    //     }
    // }

    // std::cout << "forward list after erase: ";

    // for (auto& it : f_list) {
    //     std::cout << it << " ";
    // }
    // std::cout << std::endl;

    // std::forward_list<std::string> f_list = { "hi", "hello", "good", "morning" };
    // if (insert_flist(f_list, "hio", "nihao")) {
    //     std::cout << "insert success!!" << std::endl;
    // } else {
    //      std::cout << "insert error!" << std::endl;
    // }
    
    // std::cout << "after insert f_list is :" << std::endl;
    // for (auto& it : f_list) {
    //     std::cout << it << std::endl;
    // }
    // std::cout << std::endl;

    // 一定要注意迭代器失效的情况：
    // std::vector<int> num = {1, 2, 3, 4, 5, 6};

    // auto begin = num.begin();

    // 同样的这里要用num.end()，动态获取，而不是用外部变量缓存，因为insert等操作也会导致end()迭代器失效
    // while (begin != num.end()) {
    //     *begin = (*begin) * 2;
    //     ++begin;
    //     begin = num.insert(begin, 111);   // !注意这里必须要更新迭代器。不然会导致未定义的的行为，因为erase和insert都会导致原来的迭代器失效
    //     ++begin;
    // }

    // for (auto &it : num) {
    //     std::cout << it << " ";
    // }
    // std::cout << std::endl;


    // 探索vec扩容
    // std::vector<int> num_vec = {1, 2, 3, 4, 5};

    // std::cout << "vec size: " << num_vec.size() << "| vec capacity: " << num_vec.capacity() << std::endl;
    // vec size: 5| vec capacity: 5
    // num_vec.reserve(10);

    // std::cout << "vec size: " << num_vec.size() << "| vec capacity: " << num_vec.capacity() << std::endl;
    // vec size: 5| vec capacity: 10

    // while (num_vec.size() != num_vec.capacity()) {
    //     num_vec.push_back(1);
    // }

    // std::cout << "vec size: " << num_vec.size() << "| vec capacity: " << num_vec.capacity() << std::endl;
    // vec size: 10| vec capacity: 10

    // num_vec.push_back(1);
    // or num_vec.insert(num_vec.end(), 1);
    // std::cout << "vec size: " << num_vec.size() << "| vec capacity: " << num_vec.capacity() << std::endl;
    // vec size: 11| vec capacity: 20 看来在本机器，vec的容量也是翻倍扩张的

    // 记住insert操作时在传入的元素之前插入一个，并返回插入的元素的迭代器。，
    // insert_after才是在当前元素之后

    // std::vector<char> char_vec = {'h', 'e', 'l', 'l', 'o'};

    // std::string s(char_vec.begin(), char_vec.end());
    
    // std::cout << s << std::endl;
    // std::cout << s.size() << std::endl;
    // std::cout << s.capacity() << std::endl;

    // s.reserve(100);

    // std::cout << s << std::endl;
    // std::cout << s.size() << std::endl;
    // std::cout << s.capacity() << std::endl;


    // std::string 额外方法综合使用
    std::string s2 = "pi = 3.14lllll";
    double num = std::stod(s2.substr(s2.find_first_of("+-.0123456789")));
    std::cout << num << std::endl;

    return 0;
}


bool insert_flist(std::forward_list<std::string>& f_list, const std::string& str1, const std::string& str2)
{
    if (f_list.empty()) {
        f_list.push_front(str2);
        return false;
    }

    auto it_prev = f_list.before_begin();
    auto it_curr = f_list.begin();

    while (it_curr != f_list.end()) {
        if (*it_curr == str1) {
            f_list.insert_after(it_curr, str2);
            return true;    
        }
        it_prev = it_curr;
        ++it_curr;
    }

    f_list.insert_after(it_prev, str2);

    return true;
}
// using namespace std;

// class TwoDoubles {
//     double a;
//     double b;
// };

// int main() {
//     cout << "Size of double: " << sizeof(double) << endl;          // 通常是 8
//     cout << "Size of TwoDoubles: " << sizeof(TwoDoubles) << endl; // 通常是 16
//     return 0;
// }
