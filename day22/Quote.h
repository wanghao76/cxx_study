#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>
#include <string>
#include <set>
#include <memory>


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

    // 模拟虚拷贝
    // const & 限定此函数只能被const&左值对象调用
    virtual Quote* clone() const & {
        return new Quote(*this);
    }

    // 右值
    virtual Quote* clone() && {
        return new Quote(std::move(*this));
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

    DiscQuote* clone() const & override {
        return new DiscQuote(*this);
    }

    DiscQuote* clone() && override {
        return new DiscQuote(std::move(*this));
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


class Basket {

public:

    // 但是这样其实是让用户自己负责处理动态内存，我们其实可以通过模拟虚拷贝的技术，来实现add_item自处理动态内存。
    void add_item(const std::shared_ptr<Quote>& sale) {
        items.insert(sale);
    }

    void add_item(const Quote& sale) {          // 拷贝给定对象
        items.insert(std::shared_ptr<Quote>(sale.clone()));
    }

    void add_item(Quote&& sale) {               // 移动给定对象
        items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
    }

    double total_receipt(std::ostream& os) const;

private:
    // 这里也只是需要访问智能指针中绑定的顺序，如果不加引用就会引发拷贝构造，增加引用计数，形成副本，消耗资源
    static bool compare(const std::shared_ptr<Quote>& lhs,
                        const std::shared_ptr<Quote>& rhs) {
        return lhs->isbn() < rhs->isbn();
    }
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
};


double print_total(std::ostream& os, 
                    const Quote& item, std::size_t n);

#endif // QUOTE_H