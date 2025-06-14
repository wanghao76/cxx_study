#include <iostream>
#include "Sales_data.h"

#include "Screen.h"

int main() {
    // 3. 交易处理程序实现
    // Sales_data total;
    // if (read(std::cin, total)) {
    //     Sales_data trans;
    //     while (read(std::cin, trans)) {
    //         if (total.isbn() == trans.isbn()) {
    //             total.combine(trans);
    //         } else {
    //             print(std::cout, total) << std::endl; // 输出当前总计
    //             total = trans; // 重置总计为当前交易
    //         }
    //     }

    //     print(std::cout, total) << std::endl; // 输出最后一个总计
    // } else {
    //     std::cerr << "No data?!" << std::endl; // 如果没有输入数据，输出错误信息
    //     return 1; // 返回1表示错误
    // }

    // 使用istream流构造函数改写之前的交易程序
    // Sales_data total(std::cin);
    // if (!total.isbn().empty()) {
    //     Sales_data trans;
    //     while (read(std::cin, trans)) {
    //         if (total.isbn() == trans.isbn()) {
    //             total.combine(trans);
    //         } else {
    //             print(std::cout, total) << std::endl; // 输出当前总计
    //             total = trans; // 重置总计为当前交易
    //         }
    //     }
    // } else {
    //     std::cerr << "No data?!" << std::endl; // 如果没有输入数据，输出错误信息
    //     return 1; // 返回1表示错误
    // }

    // Screen myScreen(5, 10);
    // const Screen blank(5, 3);
    // myScreen.set('#').display(std::cout);
    // blank.display(std::cout);

    // Screen myScreen(5, 5, 'X');

    // 注意这个move操作要是不返回当前对象的引用的话，则返回的是创建的一个临时对象，因此这里的set改变的是临时对象，而不是myScreen对象本身。
    // myScreen.move(4, 0).set('#').display(std::cout);

    // std::cout << '\n';

    // myScreen.display(std::cout);

    // std::cout << '\n';


    // 这里使用委托构造函数的话，顺序如下
    /**
     * 1. 首先执行委托构造函数初始化
     * 2. 然后执行被委托构造函数初始化
     * 3. 执行被委托构造函数中的函数体
     * 4. 最后执行委托构造函数中的函数体
     */
    // Sales_data next;

    // Sales_data first("9-999-99999-9");

    // Sales_data input(std::cin); // 使用输入流构造函数
    // Sales_data last("9-999-99999-9");

    // 隐式转换构造函数 (可以在对应的构造函数前面加上explicit关键字来禁止隐式转换)

    Sales_data item(std::cin);
    std::string isbn = "9-999-99999-9";

    // 这里其实就算把isbn作为实参传入combine中的形参里的Sales_data类型的参数，会自动创建一个Sales_data的临时对象。
    // item.combine(isbn); // 使用隐式转换构造函数
    // * or
    // item.combine(std::string("9-999-99999-9"));
    // * or
    // item.combine(Sales_data("9-999-99999-9"));

    // * 或者还可以用cin
    // item.combine(std::cin);

    // * 如果使用了explicit 也可以用如下方式：
    // item.combine(Sales_data("9-999-99999-9"));
    // item.combine(static_cast<Sales_data>(std::cin));



    std::cout << "After combine: " << std::endl;
    print(std::cout, item) << std::endl;


    return 0;
}