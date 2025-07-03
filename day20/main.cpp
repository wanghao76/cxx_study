#include <iostream>
#include <vector>

#include "Foo.h"

int main()
{
    std::vector<int> ivec = {1, 2, 5, 4, 7};
    Foo f1(ivec);
    Foo f2 = f1.sort();  // left value sorted
    // Foo f2 = Foo(ivec).sort(); // right value sorted
    // Foo f2 = Foo({1, 2, 5, 4, 7}).sort(); // right value sorted

    for (auto i : f2.get_data()) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}