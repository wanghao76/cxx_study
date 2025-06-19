#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <numeric>
#include <iterator>
#include <functional>
#include <fstream>
#include <limits>  // 需要包含此头文件以使用 numeric_limits

std::ostream& print(std::ostream& os, const std::string& str, const char c);

int main() 
{
    // *1. 使用istream/ostream迭代器对象来输入输出
    // *1.1 实现cin输入
    // std::istream_iterator<int> in_iter(std::cin);
    // std::istream_iterator<int> eof;
    // std::vector<int> num_vec(in_iter, eof);
    // std::cout << "vector size : " << num_vec.size() << std::endl;
    // std::for_each(num_vec.begin(), num_vec.end(), 
    //             [] (int x) { std::cout << x << " "; });
    // std::cout << std::endl;

    // *1.2 实现文件流输入
    // std::vector<std::string> vec_str;
    // std::ifstream in("afile.txt");    
    // if (in.is_open()) {
    //     std::istream_iterator<std::string> in_iter(in);
         // 为什么默认构造可以作为尾后？
         // 因为遇到文件尾，或者IO错误，迭代器的值都会跟这个相等。
    //     std::istream_iterator<std::string> in_eof;

    //     while (in_iter != in_eof) {
    //         vec_str.push_back(*in_iter++);
    //     }

    //     std::cout << "vec size is " << vec_str.size() << std::endl;
    //     std::for_each(vec_str.begin(), vec_str.end(), 
    //                     [] (const std::string& x) { std::cout << x << " "; });
    //     std::cout << std::endl;
    // }

    // *2 实现cout输出的三种实现
    // ?注意ostream_iterator不允许是空的或者指向尾后位置
    // std::istream_iterator<int> in_iter(std::cin);
    // std::istream_iterator<int> in_eof;
    
    // 通过绑定cin的istream迭代器初始化
    // std::vector<int> vec_num(in_iter, in_eof);

    // 排序
    // std::stable_sort(vec_num.begin(), vec_num.end());

    // 重排， 非重复元素排前面
    // auto it = std::unique(vec_num.begin(), vec_num.end());

    // 清除出重复元素
    // vec_num.erase(it, vec_num.end());

    // ostream迭代器绑定cout, 并设定每个输出的后缀值
    // std::ostream_iterator<int> out_iter(std::cout, " ");

    // *2.1 for循环
    // for (auto &it : vec_num) {
    //     *out_iter++ = it; 
    // }

    // *2.2 for_each
    // std::for_each(vec_num.begin(), vec_num.end(), 
    //                 [&] (int x) { *out_iter++ = x; } );

    // *2.3 copy
    // std::copy(vec_num.begin(), vec_num.end(), out_iter);

    // std::cout << std::endl;

    // *3 iostream_iterator 迭代器实现输入输出文件
    // std::ifstream in_file("infile.txt");
    // if (!in_file.is_open()) {
    //     std::cerr << "Error: Cannot open input file!" << std::endl;
    //     return 1;
    // }

    // std::istream_iterator<int> in_iter(in_file), in_eof;

    // std::ofstream out_file1("outfile1.txt", std::ios::out | std::ios::trunc);
    // std::ofstream out_file2("outfile2.txt", std::ios::out | std::ios::trunc);

    // if (!out_file1 || !out_file2) {
    //     std::cout << "Error: Cannot open output files!" << std::endl;
    //     return 1;
    // }

    // std::ostream_iterator<int> out_iter_odd(out_file1, " ");
    // std::ostream_iterator<int> out_iter_even(out_file2, "\n");

    // while (in_iter != in_eof) {
    //     if (!in_file.fail()) {
    //         int num = *in_iter++;
    //         if (num % 2 == 0) *out_iter_even++ = num;
    //         else *out_iter_odd++ = num;
    //     }
    // }

    // 4. 反向迭代器实现逆序排序

    // std::ostream_iterator<int> output_iter(std::cout, " ");
    // std::vector<int> num_vec = {1, 0, 4, 2, 6, 2, 0, 10};
    // 顺序排序（由小到大）
    // std::sort(num_vec.begin(), num_vec.end());
    // 逆序排序（由大到小）
    // std::sort(num_vec.rbegin(), num_vec.rend());
    // std::copy(num_vec.begin(), num_vec.end(), output_iter);

    // for (auto it = num_vec.end() - 1; it >= num_vec.begin(); --it) {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;

    // auto it = std::find(num_vec.rbegin(), num_vec.rend(), 0);
    // std::cout << *it << std::endl;

    // base 会转为普通迭代器，迭代器运算必须要是普通-普通相同类型，或者反向-反向
    // 转为普通迭代器，会指向下一个位置（正常视角的下一个位置）
    // auto distance = (it.base() - 1) - num_vec.begin();
    // std::cout << distance << std::endl;


    // std::list <int> num_list = { 1, 2, 2, 4, 5, 3, 3 };
    // list的unique直接实现了，重排 + erase
    // 对于list, forward_list等有自己的算法的成员函数，应该优先使用这个，而不是使用通用的
    // 使用自己的效率更好，因为做了专门的优化
    // 如list不支持随机访问，通用的sort需要随机访问，因此支持度较低

    // 同时也得注意，这些成员函数，因为有了权限，是会改变元素的，比如erase. 
    // 而通用的则不会
    // num_list.unique();
    // for (auto & it : num_list) {
    //     std::cout << it << " ";
    // }
    // std::cout << std::endl;


    // ref库函数
    // 如果要在bind中传引用类型，必须用ref 或者 cref（const引用）
    std::vector<std::string> word_vec = {"book", "red", "hellos", "congradulations!", "skyscraper", "dog", "hi"};
    std::ostream& os = std::cout;
    std::for_each(word_vec.begin(), word_vec.end(), std::bind(print, ref(os), std::placeholders::_1, ' '));
    std::cout << std::endl;
    return 0;
}

std::ostream& print(std::ostream& os, const std::string& str, const char c) {
    return os << str << c;
}