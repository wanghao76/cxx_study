#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <numeric>
#include <iterator>
#include <functional>

using namespace std;

class Sales_data {

public:
    Sales_data() = default;
    Sales_data(std::string bn) : bookNo(bn) {}
    const std::string isbn() const { return bookNo; }

private:
    std::string bookNo = "1001"; 

};


bool elimDup(std::vector<std::string>& vec_str);
bool isShorter(const std::string& s1, const std::string& s2);
bool isLower(const Sales_data& s1, const Sales_data& s2);
bool overFive(const std::string& word);
void biggies(std::vector<std::string>& word_vec, 
             const std::vector<std::string>::size_type sz);
void print(std::vector<std::string>& vec);
bool check_size(const std::string& s, std::string::size_type sz);
bool check_size2(const std::string& s, std::string::size_type sz);

int main() {

    // *1. find使用以及边界问题
    // std::vector<int> vec = {1, 2, 3, 3, 5};
    // 注意这里有个边界问题，如果第二参数设置为vec.end()-1的话，就算没找到，也会返回第二个参数。
    // 因此如果要找的值刚好就是第二个参数指向的值的话， 就会有二义性。
    // 最好第二个参数是你这个边界的下一位。
    // auto it = std::find(vec.begin(), vec.end(), 5);

    // if (it != vec.end()) {
    //     std::cout << "find success!" << std::endl;
    //     std::cout << *it << std::endl;
    // } else {
    //     std::cout << "find error!" << std::endl;
    // }

    // *2. 这个结果可以证明count是左闭右开的
    // auto count = std::count(vec.begin(), vec.end() - 2, 3);
    // std::cout << "time of 3 is :" << count << std::endl;

    // std::list<std::string> l_str = {"hi", "hi", "good"};
    // auto c = std::count(l_str.begin(), l_str.end(), "hi");
    // std::cout << "time of hi is :" << c << std::endl;

    // std::vector<int> num_vec = {1, 2, 3, 4, 5};

    // *3. accumulate 使用
    // std::vector<double> num_vec = {1.2, 1.3, 1.4};
    // double sum = std::accumulate(num_vec.cbegin(), num_vec.cend(), 0.0);
    // std::cout << "sum of num_vec is " << sum << std::endl;

    // *4. fill_n + back_inserter
    // std::vector<int> vec;

    // std::fill_n(vec, 11, 5); 错误，因为vec是空向量，这会导致未定义错误，可以用插入迭代器来实现：
    // auto itf = std::fill_n(std::back_inserter(vec), 11, 5);

    // std::cout << "vec size is " << vec.size() << std::endl;

    // for (auto & it : vec) {
    //     std::cout << it << std::endl;
    // }

    // *5. replace & replace copy
    // std::vector<int> vec = {1, 2, 3, 5};
    // std::vector<int> vec1;
    // std::vector<int> temp;

    // std::replace(vec.begin(), vec.end(), 2, 4);

    // std::replace_copy(vec.begin(), vec.end(), std::back_inserter(temp), 5, 10);

    // for (auto& it : vec) {
    //     std::cout << it << " ";
    // }
    // std::cout << std::endl;


    // for (auto& itt : temp) {
    //     std::cout << itt << " ";
    // }
    // std::cout << std::endl;

    // *6. 使用sort, unique, erase去除数组中的重复元素

    // std::vector<std::string> vec_str = {"hi", "nihao", "goo", "lalala", "hi", "the", "red", "nihao", "changcheng"};
    
    // elimDup(vec_str);

    // for (auto& it : vec_str) {
    //     std::cout << it << " "; 
    // }

    // std::cout << std::endl;

    // *7. 使用谓词进行定制排序（默认是按照字典顺序）
    // std::vector<std::string> vec_str2 = {"hhhhhhhh", "aa", "hh", "hhhh", "bb","hhh", "h"};

    // std::sort(vec_str2.begin(), vec_str2.end(), isShorter);

    // std::stable_sort(vec_str2.begin(), vec_str2.end(), isShorter);

    // for (auto& it : vec_str2) {
    //     std::cout << it << " ";
    // }

    // std::cout << std::endl;

    // *8. 类元素当然也是可以用谓词来排序的
    // 谓词分为一元谓词和二元谓词，最多传1/2个参数
    // std::vector<Sales_data> sales_vec = { Sales_data("1003"), Sales_data("1001"), Sales_data("1005") };

    // std::sort(sales_vec.begin(), sales_vec.end(), isLower);

    // *8.1 也可以用lambda表达式
    // std::sort(sales_vec.begin(), sales_vec.end(),
    //          [] (const Sales_data& s1, const Sales_data& s2)
    //             { return s1.isbn() < s2.isbn(); }
    //          );


    // for (auto it : sales_vec) {
    //     std::cout << it.isbn() << " "; 
    // }
    // std::cout << std::endl;

    // *9 谓词 + partition划分 （true放在前半部分，false放在后半部分，返回指向最后一个true的元素的下一个位置） 
    // std::vector<std::string> word_vec = {"book", "red", "hellos", "congradulations!", "skyscraper", "dog", "hi"};

    // auto it = std::partition(word_vec.begin(), word_vec.end(), overFive);
    // *9.1 也可以传lambda表达式
    // auto it = std::partition(word_vec.begin(), word_vec.end(), 
    //                                 [] (const std::string& s)
    //                                 { return s.size() > 5; }
    //                         );

    // std::cout << *it << std::endl;

    // std::cout << "-----------------------------" << std::endl;
    // for (auto it : word_vec) {
    //     std::cout << it << " "; 
    // }
    // std::cout << std::endl;
    // skyscraper congradulations! hello red book dog hi

    // *10 lambda表达式简单调用
    // lambda其实可以看作一个未命名的内联函数
    // auto f = [] (int a, int b) { return a + b; };
    // int sum = f(3, 4);
    // std::cout << sum << std::endl;

    // *11 biggies函数调用
    // std::vector<std::string> word_vec = {"book", "red", "hellos", "congradulations!", "skyscraper", "dog", "hi"};
    // biggies(word_vec, 4);

    // *12. lambda表达式的值传递，mutale
    // 捕获采用值传递，则默认无法改变其值
    // 要想改变可以使用 mutable 关键字
    // int a = 4;
    // auto f = [a] () mutable { return ++a; };
    // int sum = f();
    // std::cout << sum << std::endl;

    // *12.1 而引用传递则没这个限制, 但是也取决于这个引用的变量是否是const
    // auto f1 = [&a] () { return ++a; };
    // int sum1 = f1();
    // std::cout << sum1 << std::endl;

    // *13 若lambda函数体包含除开return的其他语句，则默认返回类型是void, 不会自动推导
    // 只有return语句才会自动推导
    // 例如，如下将实现将数组的元素全部转为其绝对值的两种方法
    // std::vector<int> num_vec = { 1, -2, 4, -5, 9, -10 };

    // std::transform(num_vec.begin(), num_vec.end(), num_vec.begin(), 
    //                 [] (int num) { return num > 0 ? num : -num; } );
    
    // 注意这里一定要制定return类型，不然会编译报错。
    // std::transform(num_vec.begin(), num_vec.end(), num_vec.begin(), 
    //                 [] (int num) -> int {
    //                     if (num > 0) { return num; } 
    //                     else { return -num; }
    //                 });
    
    // for (auto& it : num_vec) {
    //     std::cout << it << " ";
    // }
    // std::cout << std::endl;

    // *14 count_if使用（计数谓词返回true的个数，并返回计数值）
    // std::vector<std::string> word_vec = {"book", "red", "hellos", "congradulations!", "skyscraper", "dog", "hi"};
    // decltype(word_vec.size()) sz = 6;
    // auto count = std::count_if(word_vec.begin(), word_vec.end(),
    //                           [=] (const std::string& s) 
    //                           { return s.size() > sz; });
    // std::cout << count << std::endl;

    // *15 也可以使用bind重排参数顺序
    // std::vector<std::string> vec_str2 = {"hhhhhhhh", "aa", "hh", "hhhh", "bb","hhh", "h"};
    // 由短至长排序
    // std::sort(vec_str2.begin(), vec_str2.end(), isShorter);
    // print(vec_str2);
    // 由长至短排序
    // std::sort(vec_str2.begin(), vec_str2.end(), std::bind(isShorter, std::placeholders::_2, std::placeholders::_1));
    // print(vec_str2);

    // *16 bind实现统计小于等于6 的单词数量
    // std::vector<std::string> word_vec = {"book", "red", "hellos", "congradulations!", "skyscraper", "dog", "hi"};
    // decltype(word_vec.size()) sz = 6;
    // auto count = std::count_if(word_vec.begin(), word_vec.end(), std::bind(check_size, std::placeholders::_1, sz));
    // std::cout << "count is " << count << " " << std::endl;

    // *17 bind实现查找数组中第一个大于单词长度的值
    // std::string s = "congradulations";
    // std::vector<int> len_vec = {3, 4, 6, 2, 1, 20};
    // auto it = std::find_if(len_vec.begin(), len_vec.end(),
    //                      [&] (const int x) { return x > s.size(); } );
    // auto it = std::find_if(len_vec.begin(), len_vec.end(), std::bind(check_size2, s, std::placeholders::_1));
    // std::cout << *it << std::endl;

    // *18 比较 front_inserter inserter back_inserter

    std::list<int> lst = {1, 2, 3, 4};
    std::list<int> lst1 = {0, 0};
    std::list<int> lst2 = {0, 0};
    std::list<int> lst3 = {0, 0};

    // front_inserter 总是在list的第一个位置插入，因此只需要指定容器即可
    std::copy(lst.begin(), lst.end(), std::front_inserter(lst1));
    std::for_each(lst1.begin(), lst1.end(), 
                [] (int x) { std::cout << x << " "; });
    std::cout << std::endl;

    // inserter 总是在他所指向的迭代器之前插入，因此需要指定容器和他要绑定的迭代器
    auto it =  lst2.begin();
    it ++;
    std::copy(lst.begin(), lst.end(), std::inserter(lst2, it));
    std::for_each(lst2.begin(), lst2.end(), 
                [] (int x) { std::cout << x << " "; });
    std::cout << std::endl;

    // back_inserter 只能从尾部插入, 因此也只需要指定容器即可
    std::copy(lst.begin(), lst.end(), std::back_inserter(lst3));
    std::for_each(lst3.begin(), lst3.end(), 
                [] (int x) { std::cout << x << " "; });
    std::cout << std::endl;

    return 0;
}

// std::vector<std::string> word_vec = {"book", "red", "hellos", "congradulations!", "skyscraper", "dog", "hi"};

// 使用lambda表达式作为谓词，实现元素排序，查找，并输出。
void biggies(std::vector<std::string>& word_vec, 
             const std::vector<std::string>::size_type sz) 
{
    // 按照字典顺序排序，并去除重复元素
    if (!elimDup(word_vec)) {
        return;
    }

    // 按照长度排序
    std::stable_sort(word_vec.begin(), word_vec.end(),
                    [] (const std::string& s1, const std::string& s2) 
                    { return s1.size() < s2.size(); }
                    );

    // *1. 找出第一个长度大于sz的元素，并返回其迭代器
    // auto it = std::find_if(word_vec.begin(), word_vec.end(), 
    //                       [sz] (const std::string& s1) { return s1.size() > sz; }
    //                       );

    // *1.1 隐式捕获，=: 值传递，&: 引用传递。其实就是让编译器自动推断
    // auto it = std::find_if(word_vec.begin(), word_vec.end(), 
    //                       [=] (const std::string& s1) { return s1.size() > sz; }
    //                       );

    // *1.2 对了，其实也可以用partition来实现hh, 不过就是true放左边，false放右边嘛~
    // auto it = std::partition(word_vec.begin(), word_vec.end(),
    //                         [sz] (const std::string& s) { return s.size() <= sz; });

    // *1.3 也有跟sort一样，稳定版本的partition：stable_partition
    // auto it = std::stable_partition(word_vec.begin(), word_vec.end(),
    //                         [sz] (const std::string& s) { return s.size() <= sz; });

    // *1.3 同样的也可以用函数
    // 但是注意啊，find_if值接受一元谓词，因为参数不能大于1
    // 那我们确实是需要两个参数啊，怎么办呢，用bind！
    // 占位符，std::placeholders::_1，表示check_size的第一个参数：const std::string& s
    auto it = std::find_if(word_vec.begin(), word_vec.end(), 
                            std::bind(check_size, std::placeholders::_1, sz));


    // 由于之前排好序了，所以直接用尾部减去当前就能算出一共有多少个超出sz的
    auto count = word_vec.end() - it;

    std::cout << "There are " << count << " words, which longer than " << sz << std::endl;

    // 迭代器的谓词定制输出。
    std::for_each(it, word_vec.end(), 
                 [] (const std::string& s) { std::cout << s << " "; }
                );
    std::cout << std::endl;
    return;
}

// 去除数组中的重复元素
bool elimDup(std::vector<std::string>& vec_str) 
{
    if (vec_str.empty()) {
        return true;
    }

    // 按字典顺序排序，方便后续把重复元素排在后面
    std::sort(vec_str.begin(), vec_str.end());

    // 重拍，非重复元素放前面，重复元素集中放后面
    // 返回最后一个非重复元素的下一个位置
    auto it = std::unique(vec_str.begin(), vec_str.end());

    // 放心即使it就是end()迭代器，也没事
    vec_str.erase(it, vec_str.end());

    return true;
}

bool isShorter(const std::string& s1, const std::string& s2)
{
    return s1.size() < s2.size();
}

bool isLower(const Sales_data& s1, const Sales_data& s2)
{
    return s1.isbn() < s2.isbn();
}

bool overFive(const std::string& word) 
{
    return word.size() > 5;
}

void print(std::vector<std::string>& vec) { 
    for (auto& it : vec) {
            std::cout << it << " ";
    }

    std::cout << std::endl;
}

bool check_size(const std::string& s, std::string::size_type sz) {
    return s.size() > sz;
}

bool check_size2(const std::string& s, std::string::size_type sz) {
    return s.size() < sz;
}