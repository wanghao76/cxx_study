#include <iostream>
#include <list>
#include <deque>
#include <string>
#include <vector>

int get_x(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int x) {

    while (begin != end) {
        if (*begin == x) {
            return *begin;
        }
        begin++;
    }

    return -1;
}


int main() {


    // int x;
    // std::cout << "Enter a number to search for: ";
    // std::cin >> x;

    // if (std::cin.fail()) {
    //     std::cerr << "Invalid input. Please enter a valid integer." << std::endl;
    //     return 1; // Exit with an error code
    // }

    // std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // std::vector<int>::const_iterator begin = vec.cbegin();
    // std::vector<int>::const_iterator end = vec.cend();

    // int found_value = get_x(begin, end, x);

    // if (found_value != -1) {
    //     std::cout << "Found " << x << " in the vector." << std::endl;
    //     std::cout << "The value is: " << found_value << std::endl;
    // } else {
    //     std::cout << "Did not find " << x << " in the vector." << std::endl;
    // }


    // 可以使用迭代器进行隐式转换，以及给另一种类型赋值（只要元素间符合类型，或者能够隐式转化即可）
    // std::list<int> lst = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // std::vector<double> d_vec(lst.begin(), lst.end());

    // for (const auto& num : d_vec) {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;

    // std::vector<int> i_vec(lst.begin(), lst.end());

    // for (const auto& num : i_vec) {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;


    // std::vector<std::string> str_vec = {"Hello", "World", "C++", "Programming"};
    // std::vector<std::string> str_vec2 = {"hi", "good", "bye"};

    // std::swap(str_vec, str_vec2);

    // std::cout << "After swap:" << std::endl;
    // std::cout << "str_vec: ";
    // for (const auto& str : str_vec) {
    //     std::cout << str << " ";
    // }
    // std::cout << std::endl;

    // std::cout << "str_vec2: ";
    // for (const auto& str : str_vec2) {
    //     std::cout << str << " ";
    // }
    // std::cout << std::endl;
    // std::cout << "Swapping completed." << std::endl;

    // std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // std::list<int> lst(vec.begin(), vec.end());

    // if ((*(++vec.begin())) == (*(++lst.begin()))) {
    //     std::cout << "The vector and list second elements are equal." << std::endl;
    // }

    std::string str;
    
    // vec不支持从头插入，但是可以用insert实现，只不过很慢

    // vector 和 list：
    // vector 支持随机访问使用， 但只能尾部快速插入
    // List 支持快速插入和删除， 不支持随机访问
    
    // deque 即支持随机，也能从头尾插入，但是除头尾之外的任意位置插入也一样效率低下
    std::vector<std::string> vec;
    vec.insert(vec.begin(), 10, "Ana");

    for (const auto& s : vec) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
    // 容器元素是拷贝哦，不是传入的变量，因此改变容器中的值，不会对传入的对象造成影响
    return 0;
}