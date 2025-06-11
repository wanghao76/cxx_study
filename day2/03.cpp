#include <iostream>
#include <string>

#include "Sales_data.h"

using namespace std;

// struct Foo {  };

int main() {
    // Sales_data data1, data2;

    // data1.bookNo = "12345";
    // data1.units_sold = 10;
    // data1.revenue = 100.0;
    
    // data2.bookNo = "67890";
    // data2.units_sold = 5;
    // data2.revenue = 50.0;

    // cout << "Data1 - Book No: " << data1.bookNo 
    //      << ", Units Sold: " << data1.units_sold 
    //      << ", Revenue: " << data1.revenue << endl;

    // cout << "Data2 - Book No: " << data2.bookNo
    //         << ", Units Sold: " << data2.units_sold 
    //         << ", Revenue: " << data2.revenue << endl;
    // // 这里可以添加更多的操作，比如比较两个 Sales_data 对象等
    // if (data1.bookNo == data2.bookNo) {
    //     cout << "Both Sales_data objects have the same book number." << endl;
    // } else {
    //     cout << "Sales_data objects have different book numbers." << endl;
    // }

    // // 这里可以添加更多的操作，比如比较两个 Sales_data 对象等  
    // if (data1.units_sold > data2.units_sold) {
    //     cout << "Data1 has more units sold than Data2." << endl;
    // } else if (data1.units_sold < data2.units_sold) {
    //     cout << "Data2 has more units sold than Data1." << endl;
    // } else {
    //     cout << "Both Data1 and Data2 have the same units sold." << endl;
    // }

    // if (data1.revenue > data2.revenue) {
    //     cout << "Data1 has more revenue than Data2." << endl;
    // } else if (data1.revenue < data2.revenue) {
    //     cout << "Data2 has more revenue than Data1." << endl;
    // } else {
    //     cout << "Both Data1 and Data2 have the same revenue." << endl;
    // }

    // // 这里可以添加更多的操作，比如比较两个 Sales_data 对象等
    // if (data1.units_sold + data2.units_sold > 0) {
    //     cout << "Total units sold: " << (data1.units_sold + data2.units_sold) << endl;
    // } else {
    //     cout << "No units sold." << endl;
    // }

    Sales_data item = {"100000-ssd", 35, 15.99};
    cout << "ISBN: " << item.bookNo
         << ", Units Sold: " << item.units_sold 
         << ", Revenue: " << item.revenue << endl;
    return 0;
}
