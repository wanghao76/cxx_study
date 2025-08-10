#include <iostream>
#include <memory>
#include <vector>

#include "Quote.h"

double print_total(std::ostream& os, 
                    const Quote& item, std::size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n   
    << " total due: " << ret << std::endl;
    return ret;
}

void test1526()
{
    DiscQuote discq("978-7-121-15535-2", 100, 2, 0.2);    // 派生类对象
    std::cout << std::endl;

    std::cout << "------DiscQuote discq1 = discq------" << std::endl;
    DiscQuote discq1 = discq;
    std::cout << std::endl;

    std::cout << "------DiscQuote discq2 = discq------" << std::endl;
    DiscQuote discq2;
    discq2 = discq;
    std::cout << std::endl;

    std::cout << "------DiscQuote discq3 = std::move(discq)------" << std::endl;
    DiscQuote discq3 = std::move(discq);
    std::cout << std::endl;

    std::cout << "------Quote quote1 = discq------" << std::endl;
    Quote quote1 = discq;
    std::cout << std::endl;

    std::cout << "------Quote quote2 = std::move(discq)------" << std::endl;
    Quote quote2 = std::move(discq);
    std::cout << std::endl;
}

void test1528()
{
    // 存对象
    BulkQuote bulk1("1001", 100, 2, 0.2);
    BulkQuote bulk2("1002", 100, 5, 0.5);

    print_total(std::cout, bulk1, 4);
    print_total(std::cout, bulk2, 6);

    std::cout << "-------------------------------------------" << std::endl;

    std::vector<Quote> itemVec;
    itemVec.push_back(bulk1);
    itemVec.push_back(bulk2);

    print_total(std::cout, itemVec[0], 4);
    print_total(std::cout, itemVec[1], 6);
}

void test1529()
{
    // 存指针
    std::shared_ptr<BulkQuote> bulk1 = std::make_shared<BulkQuote>("1001", 100, 2, 0.2);
    std::shared_ptr<BulkQuote> bulk2 = std::make_shared<BulkQuote>("1002", 100, 5, 0.5);

    print_total(std::cout, *bulk1, 4);
    print_total(std::cout, *bulk2, 6);

    std::cout << "--------------------------------------------" << std::endl;

    std::vector<std::shared_ptr<Quote>> itemVec;
    itemVec.push_back(bulk1);
    itemVec.push_back(bulk2);

    print_total(std::cout, *itemVec[0], 4);
    print_total(std::cout, *itemVec[1], 6);

}

int main()
{
    // 动态绑定只有我们通过指针或者引用调用虚函数时才会发生

    // 如果虚函数net_price采用的默认实参，则无论基类指针或者引用绑定时基类对象还是派生类对象
    // 其调用的虚函数的默认实参都是基类的虚函数的默认实参
    // 所以子类和基类的虚函数的默认实参最好保持一致
    // Quote basic("1001", 10);
    // print_total(std::cout, basic, 20);

    // BulkQuote bulk("1002", 10, 5, 0);
    // print_total(std::cout, bulk, 30);

    // 抽象基类不允许被定义。
    // DiscQuote disc("1001", 20);

    test1529();
    return 0;
}