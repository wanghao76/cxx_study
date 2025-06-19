#include <iostream>
#include <string>


#include "Sales_data.h"

Sales_data::Sales_data(std::istream& is) {
    read(is, *this);
}

Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;  // 返回当前对象的引用
}


std::istream& read(std::istream& is, Sales_data& item) {
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;  // 计算收入
    return is;
}

std::ostream& print(std::ostream& os, const Sales_data& item) {
    os << "ISBN: " << item.bookNo << ", Units Sold: " << item.units_sold 
       << ", Revenue: " << item.revenue;
    return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

// 定义输入操作符 >>
std::istream& operator>>(std::istream& is, Sales_data& item) {
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    if (is)
        item.revenue = item.units_sold * price;
    else
        item = Sales_data();
    return is;
}

// 定义输出操作符 <<
std::ostream& operator<<(std::ostream& os, const Sales_data& item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " ";
    return os;
}