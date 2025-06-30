#include <iostream>
#include <string>

# include "HasPtr.h"
using namespace std;

int main() {

    HasPtr hp1 ("hello");
    HasPtr hp2 ("world");

    swap(hp1, hp2);
    cout << hp1.getPs() << endl;
    cout << hp2.getPs() << endl;

    hp1 = hp2;
    cout << hp1.getPs() << endl;
    cout << hp2.getPs() << endl;
    
    return 0;
}
// #include "CDocument.h"

// int main()
// {

//     // 调研composition + inheritance的构造和析构执行顺序
//     MyDoc md;
//     md.OnOpenFile();
    
//     // 构造顺序
//     // CDocument default constructor called
//     // Notify default constructor called
//     // MyDoc constructor called

//     // 析构顺序
//     // MyDoc destructor called
//     // Notify destructor called
//     // CDocument destructor called
//     return 0;
// }