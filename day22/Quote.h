#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>
#include <string>


class Quote {

public:
    Quote() = default;

    Quote(const std::string& book, double sales_price) : 
        bookNo(book), price(sales_price) {  }
    
    Quote(const Quote& q) : bookNo(q.bookNo), price(q.price) {
        std::cout << "Quote copy constructor..." << std::endl;
    }

    Quote& operator=(const Quote& rhs) {
        bookNo = rhs.bookNo;
        price = rhs.price;
        std::cout << "Quote assignment constructor..." << std::endl;

        return *this;
    }

    Quote(Quote&& q) noexcept : bookNo(std::move(q.bookNo)), price(std::move(q.price))
    {
        std::cout << "Quote move construtor..." << std::endl;
    }

    Quote& operator=(Quote&& rhs) noexcept {
        std::cout << "Quote move assignment..." << std::endl;

        bookNo = std::move(rhs.bookNo);
        price = std::move(rhs.price);

        return *this;
    }

    std::string isbn() const { return bookNo; }

    virtual double net_price(std::size_t n = 20) const {
        return n * price;
    }

    virtual ~Quote() {   // 对析构函数进行动态绑定
        std::cout << "Quote Destructor" << std::endl; 
    }
private:
    std::string bookNo;

protected:
    double price = 0.0;
};


// 此类是抽象基类，通过定义纯虚函数来用于实现不同的折扣策略
class DiscQuote : public Quote {

public:
    DiscQuote() = default;

    DiscQuote(const std::string& book, double sales_price, std::size_t qty, double disc) :
        Quote(book, sales_price), quantity(qty), discount(disc) {
            std::cout << "DiscQuote Constructor..." << std::endl;
        }

    DiscQuote(const DiscQuote& d) : Quote(d), quantity(d.quantity), discount(d.discount)
    {
        std::cout << "DiscQuote copy constructor..." << std::endl;
    }

    DiscQuote& operator=(const DiscQuote& d)
    {
        Quote::operator=(d);
        quantity = d.quantity;
        discount = d.discount;

        std::cout << "DiscQuote assignment constructor..." << std::endl;
        return *this;
    }

    // 这里很容易混淆，虽然d的类型是右值引用，但是其本身是左值
    // "如果它有名字，那么它就是左值，即使它的类型是右值引用"
    // 所以这里基类其实执行的是拷贝构造，如果希望执行移动构造，则可以这样：Quote(std::move(d))
    DiscQuote(DiscQuote&& d) noexcept : 
                Quote(d), quantity(std::move(d.quantity)), discount(std::move(d.discount)) 
    {
        std::cout << "DiscQuote move constructor..." << std::endl;
    }

    DiscQuote& operator=(DiscQuote&& rhs) noexcept
    {
        Quote::operator=(rhs);
        quantity = std::move(rhs.quantity);
        discount = std::move(rhs.discount);

        std::cout << "DiscQuote move assignment..." << std::endl;
        return *this;
    }
    
    // double net_price(std::size_t) const = 0; 抽象类
    double net_price(std::size_t cnt) const override {
        if (cnt >= quantity) {
            return cnt * (1 - discount) * price;
        } else {
            return cnt * price;
        }
    }

    virtual ~DiscQuote() {
        std::cout << "DiscQuote destructor..." << std::endl;
    }


protected:
    std::size_t quantity;
    double discount = 0.0;
};

class BulkQuote : public DiscQuote {
public:

    // 注意使用using只是继承了构造函数，默认，拷贝，移动构造函数不会被继承，而是走正常的编译器合成
    // 继承的构造函数不会作为用户自定义的构造函数，因此也会有一个默认的合成构造函数
    using DiscQuote::DiscQuote;
    // 覆盖基类中的函数版本以实现一种新的折扣策略
    double net_price(std::size_t) const override;
};


// class BulkQuote : public DiscQuote {

// public:
//     BulkQuote() = default;

//     BulkQuote(const std::string& book, double sales_price, std::size_t qty, double disc) :
//     DiscQuote(book, sales_price, qty, disc) {}

//     double net_price(std::size_t) const override;
// };

// class BulkQuote : public Quote {

// public:
//     BulkQuote() = default;

//     // 首先初始化基类部分，然后按照声明的顺序依次初始化派生类成员。
//     BulkQuote(const std::string& book, double sales_price, std::size_t qty, double disc) :
//         Quote(book, sales_price), min_qty(qty), discount(disc) { }

//     double net_price(std::size_t n = 30) const override;

// private:
//     std::size_t min_qty = 0;
//     double discount = 0.0;
// };

#endif // QUOTE_H