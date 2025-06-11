#ifndef SALES_DATA_H
#define SALES_DATA_H
// 这里ifndef和define的作用是防止头文件被多次包含
// 如果头文件被多次包含，编译器会报错，因为同一个结构体或类不能被定义多次

#include <iostream>
#include <string>


/* 使用struct 和 class 的区别：
 * 1. 默认访问权限：struct的成员默认是public的，而class的成员默认是private的。
 * 2. 继承方式：struct的继承默认是public的，而class的继承默认是private的。
 * 3. 用途：struct通常用于简单的数据结构，而class通常用于更复杂的对象。
 * 
 * 在C++中，struct和class几乎没有区别，主要是语义上的差异。
 */

class Sales_data {

/* 友元函数的作用：
 * 1. 友元函数可以访问类的私有成员和保护成员。
 * 2. 友元函数不是类的成员函数，但可以访问类的私有数据。
 * 4. 友元函数只能在类的定义中声明，不能在类的外部定义。
 * 5. 友元函数不受类的访问控制级别约束。
 * 6. 友元函数一般在类的开始或者结束前集中声明。
 * 
 * 注意：友元函数不是类的成员函数，因此不能直接访问类的成员变量，需要通过对象来访问。
 */

friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::ostream& print(std::ostream&, const Sales_data&);
friend std::istream& read(std::istream&, Sales_data&);
friend std::istream& read_str(std::istream&, Sales_data&);

public:

    Sales_data() = default; // 默认构造函数


    //  带参数的构造函数，提供了初始值
    Sales_data (const std::string& s, unsigned n, double p) 
        : bookNo(s), units_sold(n), revenue(p * n) { 
            std::cout << "---------------------------------------------------" << std::endl;
            std::cout << "Constructor with three parameters called." << std::endl;
        }
    
    // Sales_data (const std::string& s) : bookNo(s) {}
    /*
        * 带参数的构造函数，如果没有为其他成员提供初始值，则会进行隐式初始化。
        * 隐式初始化规则：
        *   1. 优先使用类内的初始值；
        *   2. 如果没有初始值，则成员变量将被默认初始化。
        * 因此，使用隐式初始化是一个好的选择，因为不会对已定义的初始值造成不必要的更改。
    */
    
    // 默认构造函数的另一种写法，使用默认值初始化成员变量
    // Sales_data (std::string s = "") : bookNo(s) { std::cout << "Default11 constructor called." << std::endl; }




    // Sales_data() : Sales_data("1001", 1, 10.0) { 
    //     std::cout << "---------------------------------------------------" << std::endl;

    //     std::cout << "Default constructor called." << std::endl; 
    //     std::cout << "bookNo: " << bookNo << ", units_sold: " << units_sold 
    //               << ", revenue: " << revenue << std::endl;
    // }


    // * 禁止隐式转换
    // explicit Sales_data(std::string s) : Sales_data(s, 2, 3.0) { 

    explicit Sales_data(std::string s) : Sales_data(s, 2, 3.0) { 
        std::cout << "---------------------------------------------------" << std::endl;

        std::cout << "Constructor with string parameter called." << std::endl;
        std::cout << "bookNo: " << bookNo << ", units_sold: " << units_sold 
                  << ", revenue: " << revenue << std::endl;
    }

    // *这里其实会执行两次构造
    // *1. 默认构造，默认构造执行带三参数的构造
    // *2. 执行带istream参数的构造 （因此成员数据会被改写两次，最终的值是istream输入的值，因为是最后被执行）

    // Sales_data(std::istream &is) : Sales_data() { 
        
    //     read(is, *this); // 通过输入流读取数据

    //     std::cout << "---------------------------------------------------" << std::endl;

    //     std::cout << "Constructor with istream called." << std::endl;
    //     std::cout << "bookNo: " << bookNo << ", units_sold: " << units_sold 
    //               << ", revenue: " << revenue << std::endl;
    // }


    // 通过输入流读取数据的构造函数
    Sales_data (std::istream& is);

    // 成员函数
    // 获取ISBN号 ( 对于bookNo 存在一个隐式的 this 指针指向当前对象)
    inline std::string isbn() const {   return bookNo;  }

    // 合并销售数据
    Sales_data& combine (const Sales_data& rhs);

private:
 
    inline double avg_price() const 
        { return units_sold ? revenue / units_sold : 0; }
    // 数据成员
    std::string bookNo = "1001";  // ISBN号
    unsigned units_sold = 0; // 销售数量
    double revenue = 0.0; // 销售收入
    
    mutable std::string log; // 可变成员变量，允许在const成员函数中修改
};

// 非成员接口函数
Sales_data add(const Sales_data&, const Sales_data&);

// 由于传入的是std::cout, 无法被拷贝，所以是引用类型；同时注意这里的第二个参数是const。
std::ostream& print(std::ostream&, const Sales_data&);

// 同理
std::istream& read(std::istream&, Sales_data&);

std::istream& read_str(std::istream&, Sales_data&);


#endif