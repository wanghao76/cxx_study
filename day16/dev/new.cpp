#include <iostream>
#include <new>
#include <memory>
#include <vector>
#include <algorithm>
#include <iterator>

void get_value(std::vector<int>& num_vec);
void print(std::vector<int>& num_vec);

int main() {

    auto p = new (std::nothrow) std::vector<int>();

    if (p != nullptr) {
        get_value(*p);
        print(*p);

        delete p;
        p = nullptr;
    }
    return 0;
}

void get_value(std::vector<int>& num_vec)
{
    int x;
    while (std::cin >> x) {
        num_vec.push_back(x);
    }
} 

void print(std::vector<int>& num_vec)
{
    std::ostream_iterator<int> iter_num(std::cout, " ");
    std::copy(num_vec.begin(), num_vec.end(), iter_num);
    std::cout << std::endl;
}