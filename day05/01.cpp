#include<iostream>
#include<string>
#include<vector>
#include<iterator>

using namespace std;

int main()
{
    // vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 初始化一个vector
    // vector<int>::const_iterator it = vec1.begin(); 

    // 这样遍历更加简洁，高效，不宜与发生错误
    // 先进行 it++, 讲it指向下一个元素，然后生成一个原来的副本返回，然后再进行解引用操作。
    // 但是在一般的for循环，或者可以用++it的方式来进行遍历的情况下，推荐使用++it的方式，因为不会生成副本，效率更高。

    // 但是这种方式 类似于 *it = toupper(*it++) 的方式，会导致未定义的行为，因为等号两侧都it，且右侧还改变了it的值，因此可能会有两种情况，从而导致编译器无法处理：
    // *it = toupper(*it)
    // *(it + 1) = toupper(*it)
    // 这种情况下，编译器无法确定是哪个操作先执行，因此会导致未定义的行为。


    // while (it != vec1.end()) {
    //     cout << *it++ << " ";   // 输出vector中的每个元素  
    // }

    // vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 初始化一个vector

    // for (auto it = vec2.begin(); it != vec2.end(); ++it) {
    //     *it = ((*it % 2 == 0) ? *it : (*it) * 2);
    // }

    // for (const auto& val : vec2) {
    //     cout << val << " "; // 输出vector中的每个元素
    // }
    // cout << endl;

    // 嵌套条件运算符
    // string final_core;
    // int grade;
    // while (cin >> grade) {
    //     final_core = (grade > 90) ? "A" :
    //                  (grade > 80) ? "B" :
    //                  (grade > 70) ? "C" :
    //                  (grade > 60) ? "D" : "E";
    //     cout << "Grade: " << grade << ", Final Core: " << final_core << endl;
    // }

    // std::string s1 = "Hello, World!";
    // std::string s2 = "Hello, Wsdasdmaasasd.as.da!";

    // std::cout << sizeof(s1) << std::endl; // 输出字符串s1的长度
    // std::cout << sizeof(s2) << std::endl; // 输出字符串s2的长度

    // std::cout << s1.size() << std::endl; // 输出字符串s1的长度
    // std::cout << s2.size() << std::endl; // 输出字符串s2的长度

    // 因此sizeof(s1) 和 s1.size() 的结果是不同的。
    // sizeof(s1) 返回的是字符串对象的大小，而 s1.size() 返回的是字符串的长度（字符数）。
    // 这两者的区别在于，sizeof(s1) 返回的是字符串对象的大小（包括内部数据结构的开销），而 s1.size() 返回的是字符串中实际存储的字符数。

    // int arr[10];
    // for (size_t i = 0; i < 5; ++i) {
    //     arr[i] = i; // 初始化数组
    // }

    // std::cout << sizeof(arr) << std::endl; // 输出数组的大小（字节数）
    // std::cout << sizeof(arr[0]) << std::endl; // 输出数组中每个元素的大小（字节数）
    // std::cout << sizeof(arr) / sizeof(*arr) << std::endl; // 输出数组的长度（元素个数）

    // vector<int> vec = {1, 2, 3};


    // std::cout << "vec.size(): " << vec.size() << std::endl; // 输出vector的大小
    // std::cout << "vec.capacity(): " << vec.capacity() << std::endl; // 输出vector的容量
    // std::cout << "vec.max_size(): " << vec.max_size() << std::endl; // 输出vector的最大大小
    
    // int x[10]; int *p = x; // p是一个指向int类型的指针，指向数组x的第一个元素
    // cout << "sizeof(x) / sizeof(*x): " << sizeof(x) / sizeof(*x) << endl; // 输出数组x的长度
    // cout << "sizeof(p) / sizeof(*p): " << sizeof(p) / sizeof(*p) << endl; // 输出指针p的长度
    // cout << "sizeof(x): " << sizeof(x) << endl; // 输出数组x的大小（字节数）
    // cout << "sizeof(p): " << sizeof(p) << endl; // 输出指针p的大小（字节数）
    // cout << "sizeof(*x): " << sizeof(*x) << endl; // 输出数组x中每个元素的大小（字节数）
    // cout << "sizeof(*p): " << sizeof(*p) << endl; // 输出指针p指向的元素的大小（字节数）

    // int a = 5;
    // double b = 3.14;
    // a *= static_cast<int>(b); // 将double类型的b转换为int类型，然后与a相乘
    // std::cout << "a after multiplication: " << a << std::endl; // 输出a的值

    // const string* ps; void* pv;
    // string *pt = const_cast<string*>(ps); // 将const string*转换为string*
    // pv = reinterpret_cast<void*>(pt); //  将string*转换为void*

    int j = 5, i = 3;

    double result = static_cast<double>(j / i); 
    std::cout << "Result of division: " << result << std::endl; // 输出结果

    double result2 = static_cast<double>(j) / i;
    std::cout << "Result of division with static_cast: " << result2 << std::endl; // 输出结果

    return 0;
}