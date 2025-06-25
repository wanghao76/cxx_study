#include <iostream>
#include <new>
#include <memory>
#include <vector>
#include <algorithm>
#include <iterator>

void get_value(std::shared_ptr<std::vector<int>> p);
void print(std::shared_ptr<std::vector<int>> p);

int main() {

    // auto p = new (std::nothrow) std::vector<int>();
    auto p = std::make_shared<std::vector<int>>();

    get_value(p);
    print(p);

    return 0;
}

void get_value(std::shared_ptr<std::vector<int>> p)
{
    int x;
    while (std::cin >> x) {
        p->push_back(x);
    }
} 

void print(std::shared_ptr<std::vector<int>> p)
{
    std::ostream_iterator<int> iter_num(std::cout, " ");
    std::copy((*p).begin(), (*p).end(), iter_num);
    std::cout << std::endl;
}


