#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <functional>
#include <map>

#include "PrintString.h"
#include "IsEqual.h"

using namespace std;
using namespace std::placeholders;
// using std::placeholders;   // error: namespace 'std::placeholders' not allowed in using-declaration
void test1442()
{
    //统计大于1024有几个
    vector<int> ivec = {1, 11, 112, 1122, 11122};
    size_t count = std::count_if(ivec.begin(), ivec.end(), bind(greater<int>(), _1, 1024));
    cout << count << endl;

    // 找出第一个不等于"pooch"的值
    vector<string> svec = {"pooch", "apple", "banana", "pooch"};
    auto word = find_if (svec.cbegin(), svec.cend(), bind(not_equal_to<string>(), _1, "pooch"));
    cout << *word << endl;

    // 所有值都*2
    transform(ivec.begin(), ivec.end(), ivec.begin(), bind(multiplies<int>(), _1, 2));
    for (auto i : ivec) {
        cout << i << " ";
    }
    cout << endl;
}

void test1443(int num)
{
    vector<int> ivec = {2, 4, 6, 8};
    std::modulus<int> mod;
    auto is_divisible = std::any_of(ivec.begin(), ivec.end(), 
                                            [&mod, &num](int i)->bool { return 0 == mod(num, i); }
                            );
    cout << (is_divisible ? "Yes!" : "No!") << endl;
}

int add(int i, int j) { return i + j; }

struct divide {
    int operator()(int x, int y) { return x / y; }
};

void test1444() {
    auto mod = [] (int i, int j) {
        return i % j;
    };
    std::map<std::string, function<int (int, int)>> binops = {
        {"+", add},
        {"-", std::minus<int>()},
        {"*", [](int i, int j) { return i * j; }},
        {"/", divide()},
        {"%", mod}
    };


    std::cout << binops["+"](1, 2) << std::endl;
    std::cout << binops["-"](1, 2) << std::endl;
    std::cout << binops["*"](1, 2) << std::endl;
    std::cout << binops["/"](1, 2) << std::endl;
    std::cout << binops["%"](1, 2) << std::endl;

}


int main() 
{
    // PrintString ps(std::cin);
    // std::cout << ps;

    // 想不到吧，这里不仅可以用lambda, 也可以用类中operator()重载，还可以用函数指针。三种方法了，牛不牛比
    // 所以我感觉灵活度最高的还是定义一个类，然后用其中的operator()重载。
    // std::vector<int> ivec = {1, 3, 5, 9, 2, 4, 2, 10};
    // std::replace_if(ivec.begin(), ivec.end(), IsEqual(2), 10);

    // for (const auto& i : ivec) {
    //     std::cout << i << " ";
    // }
    // std::cout << std::endl;

    // std::vector<int> ivec = {1, 3, 5, 9, 2, 4, 2, 10};
    // std::sort(ivec.begin(), ivec.end());

    // std::ostream_iterator<int> os_iter(std::cout, " ");
    // std::copy(ivec.begin(), ivec.end(), os_iter);
    // std::cout << std::endl;

    // std::sort(ivec.begin(), ivec.end(), std::greater<int>());
    // std::copy(ivec.begin(), ivec.end(), os_iter);
    // std::cout << std::endl;

    // test1442();
    // std::cout << 2 % 8 << std::endl;
    // test1443(8);

    // auto mod = [] (int i, int j) {
    //     return i % j;
    // };

    // std::function<int(int, int)> f1 = add;
    // std::function<int(int, int)> f2 = divide();
    // std::function<int(int, int)> f3 = mod;

    // std::cout << f1(1, 2) << std::endl;
    // std::cout << f2(1, 2) << std::endl;
    // std::cout << f3(1, 2) << std::endl;


    test1444();



    return 0;
}


