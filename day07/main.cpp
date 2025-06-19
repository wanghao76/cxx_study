#include <iostream>
#include <iterator>
#include "Sales_data.h"

int main() {
    // Sales_data book1{"12345", 10, 100.0};
    // Sales_data book2{"12345", 5, 50.0};

    // Sales_data book1; // 默认构造函数
    // 1. 使用成员函数isbn()
    // std::cout << "Book No: " << book1.isbn() << std::endl;

    // 2. 使用成员函数combine()
    // book1.combine(book2);
    // std::cout << "After combining, units sold: " << book1.units_sold 
    //           << ", revenue: " << book1.revenue << std::endl;

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

    std::istream_iterator<Sales_data> in_iter(std::cin);
    std::istream_iterator<Sales_data> in_eof;

    std::ostream_iterator<Sales_data> out_iter(std::cout, " ");
    
    Sales_data total = *in_iter++;

    while (in_iter != in_eof) {
        Sales_data trans = *in_iter++;
        if (total.isbn() == trans.isbn()) {
            total.combine(trans);
        } else {
            out_iter = total;
            // std::cout << std::endl;
            total = trans; // 重置总计为当前交易
        }
    }
    out_iter = total;
    std::cout << std::endl;

    

    // 4. read函数的连续调用：读取两条销售数据
    // Sales_data data1, data2;

    // if (read(read(std::cin, data1), data2)) {
    //     Sales_data total = add(data1, data2);
    //     print(std::cout, total) << std::endl; // 输出总计
    // } else {
    //     std::cerr << "No data?!" << std::endl; // 如果没有输入数据，输出错误信息
    //     return 1; // 返回1表示错误
    // }

    // 5. 默认构造函数
    // 合成的默认构造函数是编译器自动生成的，通常不需要手动定义。
    // 只有当类没有声名任何构造函数时，编译器才会自动生成一个默认构造函数。
    // 如果类中定义了其他构造函数（如带参数的构造函数），编译器将不会生成默认构造函数。

    // 默认构造函数首先 用 类内的初始值来初始化成员变量。
    // 如果类内没有初始值，则成员变量将被默认初始化（对于基本类型，未定义；对于类类型，调用默认构造函数）。
    // 但是以下几种情况需要手动定义默认构造函数：
    // 1. 对于指针和引用被默认初始化，其值是未定义的。
    // 2. 内置类型成员如果没有初始值，则需要手动定义默认构造函数来初始化这些成员。
    // 2. 其他类的类类型成员如果没有默认构造函数，则需要手动定义默认构造函数来初始化这些成员。

    // 使用默认构造函数
    // Sales_data book3;
    // std::cout << "Default Book No: " << book3.isbn()
    //           << ", Units Sold: " << book3.units_sold 
    //           << ", Revenue: " << book3.revenue << std::endl;   

    // 使用带参数，但不完整的构造函数
    // Sales_data book4("67890"); 
    // std::cout << "Book No: " << book4.isbn()
    //           << ", Units Sold: " << book4.units_sold 
    //           << ", Revenue: " << book4.revenue << std::endl;
    
    // 使用带参数的完整构造函数
    // Sales_data book5("67890", 20, 200.0);
    // std::cout << "Book No: " << book5.isbn()
    //           << ", Units Sold: " << book5.units_sold 
    //           << ", Revenue: " << book5.revenue << std::endl;

    // 使用istream流构造函数
    // Sales_data book6(std::cin);
    // std::cout << "Book No: " << book6.isbn()
    //           << ", Units Sold: " << book6.units_sold 
    //           << ", Revenue: " << book6.revenue << std::endl;

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


    return 0;
}