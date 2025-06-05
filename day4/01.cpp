#include<iostream>
#include<string>
#include<vector>
#include<iterator>

using namespace std;

int main() {

    // // 声明和定义的过程中，如果有括号的，得从内往外看。如果没有则按照从右往左的顺序
    // int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // // 首先它是一个指针，再看右边，这个指针指向的是一个长度为10的数组，再看左边，这个指针的类型是int，所以它是一个指向长度为10的int数组的指针
    // int (*ptr)[10] = &arr; // 指向数组的指针

    // for (int i = 0; i < 10; ++i) {
    //     cout << (*ptr)[i] << " "; // 输出指针指向的数组的每个元素
    // }
    // cout << endl;

    // // 首先看右边，这是一个数组，再看左边，这是一个指针，所以它是一个指向int类型的指针的数组
    // // 也就是说，p是一个数组，数组的每个元素都是一个指针，指向int类型的数据
    // int *p[10]; // 指向指针的数组

    // for (int i = 0; i < 10; ++i) {
    //     p[i] = &arr[i]; // 将指针数组的每个元素指向arr数组的每个元素
    // }

    // for (int i = 0; i < 10; ++i) {
    //     cout << *p[i] << " "; // 输出指针数组的每个元素指向的值
    // }
    // cout << endl;

    // // int *(&array)[10] = p; // 引用指向数组的指针
    // // 如果想要引用p，可以这样写
    // int *(&array)[10] = p; // 引用指向数组的指针

    // for (int i = 0; i < 10; ++i) {
    //     cout << *array[i] << " "; // 输出指针数组的每个元素指向的值
    // }
    // cout << endl;

    // int arr[10];

    // for (size_t i = 0; i < 10; ++i) {
    //     arr[i] = i; // 初始化数组
    // }

    // cout << "arr: ";
    // for (size_t i = 0; i < 10; ++i) {
    //     cout << arr[i] << " "; // 输出数组的每个元素
    // }
    // cout << endl;   

    // int arr1[10];
    // for (size_t i = 0; i < 10; ++i) {
    //     arr1[i] = arr[i];
    // }

    // vector<int> vec(arr, arr + 10); // 使用数组初始化vector

    // vector<int> vec1;

    // for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
    //     vec1.push_back(*it); // 将vec中的元素添加到vec1中
    // }

    // std::cout << "vec1: ";
    // for (auto it : vec1) {
    //     cout << it << " "; // 输出vec1中的每个元素
    // }

    // int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // int *p = &array[0]; // 指向数组的第一个元素
    
    // // 注意尾后指针不能被解引用，和递增操作。
    // int *end = &array[10]; // 指向数组的最后一个元素的下一个位置
    // for (; p != end; ++p) {
    //     cout << *p << " "; // 输出数组的每个元素
    // }
    // cout << endl;

    // int *ptr = array; // 重新指向数组的第一个元素
    // for (int *ptr = array; ptr != end; ++ptr) {
    //     cout << *ptr << " "; // 使用指针遍历数组
    // }
    // cout << endl;

    // 但是上述使用尾后指针的方法极其不推荐，因为它会导致一些潜在的错误，比如解引用尾后指针会导致未定义行为。
    // 可以用begin end 迭代器的方式：（但是需要引入iterator头文件）
    // int *pbegin =  std::begin(array); // 指向数组的第一个元素
    // int *pend = std::end(array); // 指向数组的最后一个元素的下一个位置

    // while (pbegin != pend && *pbegin > 0) {
    //     cout << *pbegin << " "; // 输出数组的每个元素
    //     ++pbegin; // 移动到下一个元素
    // }
    // cout << endl;

    // ptrdiff_t size = std::end(array) - std::begin(array); // 计算数组的大小
    // cout << "Size of the array: " << size << endl;

    // 指针运算

    int arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p2 = arr2; // 指向数组的第一个元素

    for (size_t i = 0; i < 10; i++) {
        *(p2 + i) = 0;
    }

    std::cout << "arr2 after pointer arithmetic: ";
    for (size_t i = 0; i < 10; i++) {
        std::cout << arr2[i] << " "; // 输出数组的每个元素
    }
    std::cout << std::endl;

    for (size_t i = 0; i < 10; i++) {
        p2[i] = i + 1; // 使用指针运算给数组赋值
    }
    std::cout << "arr2 recover: ";
    for (size_t i = 0; i < 10; i++) {
        std::cout << arr2[i] << " "; // 输出数组的每个元素
    }
    return 0;
}