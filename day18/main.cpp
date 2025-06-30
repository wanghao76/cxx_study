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