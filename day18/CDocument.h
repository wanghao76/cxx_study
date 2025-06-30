#ifndef CDOCUMENT_H
#define CDOCUMENT_H

#include <iostream>
class MyDoc;

class Notify
{  
public:
    Notify() {
        std::cout << "Notify default constructor called" << std::endl; 
    }

    Notify(const std::string& info) : news(info) { 
        std::cout << "Notify constructor called with info: " << news << std::endl;
    }
    
    const std::string& getNews() const { 
        return news; 
    }

    ~Notify() { 
        std::cout << "Notify destructor called" << std::endl; 
    }

private:
    std::string news = "default news";
};


class CDocument {
public:
    CDocument() {
        std::cout << "CDocument default constructor called" << std::endl;
    }
    void OnOpenFile();
    virtual void Serialize() const = 0;
    virtual void printContent() const;


    // CDocument 作为基类包含虚函数，但析构函数未声明为 virtual。
    // 当通过基类指针删除派生类对象时，会导致未定义行为（派生类析构函数不会被调用）, 从而可能导致内存泄漏：
    // 例如：
    // CDocument* doc = new MyDoc();
    // delete doc; // 仅调用 ~CDocument()，不会调用 ~MyDoc()

    virtual ~CDocument() {
        std::cout << "CDocument destructor called" << std::endl;
    }
};

class MyDoc : public CDocument
{    
public:
    MyDoc() {
        std::cout << "MyDoc constructor called" << std::endl;
    }
    void Serialize() const override;
    void printContent() const override;


    // 在您的代码中，子类 MyDoc 的析构函数不需要显式添加 virtual 关键字，原因如下：
    // ?虚析构函数的继承机制：
    // 当基类 CDocument 的析构函数声明为 virtual 时（这是必须修复的关键点）
    // 所有派生类（如 MyDoc）的析构函数自动成为虚函数
    // 即使派生类析构函数没有显式写 virtual，它仍然是虚函数
    ~MyDoc() {   // 自动成为虚析构函数
        std::cout << "MyDoc destructor called" << std::endl;
    }

private:
    Notify notify; // MyDoc类的成员变量
};


// ?最佳实践建议：
// 基类规则：
//    1. 任何作为基类的类型（即使只有纯虚函数）
//    2. 析构函数必须声明为 virtual
// 派生类规则：
//    1. 永远不要在派生类析构函数重复 virtual
//    2. 可添加 override 关键字（C++11 起）增强可读性：

#endif
