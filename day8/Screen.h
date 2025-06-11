#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
#include <vector>

#define BLANK ' '


class Screen {

    friend class Window_mgr; // 声明Window_mgr为友元类，允许其访问私有成员

public:
    typedef std::string::size_type pos; 

    // 定义一个类型别名，便于使用   
    // 默认构造函数
    Screen() = default;

    // 带参数的构造函数
    Screen(pos h, pos w) : height(h), width(w), contents(h * w, BLANK) {}
    Screen(pos h, pos w, const char str) : height(h), width(w), contents(h * w, str) {}

    // 获取光标位置
    inline char get() const { return contents[cursor]; } 

    // 获取指定位置的字符
    inline char get(pos r, pos c) const { return contents[r * width + c]; } 

    // 设置光标位置
    Screen & move(pos r, pos c);

    // 设置光标位置并返回当前对象的引用
    Screen & set(char c); 

    // 设置指定位置的字符
    Screen & set(pos r, pos c, char ch);

    // 根据对象是否是const, 重载了display函数
    Screen & display(std::ostream & os) {
        std::cout << "Non-const display called." << std::endl;
        do_display(os); 
        os << std::endl;
        return *this;
    }

    const Screen & display(std::ostream & os) const {
        std::cout << "Const display called." << std::endl;
        do_display(os); 
        os << std::endl;
        return *this;
    }
     
private:
    pos cursor = 0; // 光标位置
    pos width = 0, height = 0; // 屏幕宽高
    std::string contents;     // 屏幕内容

    void do_display(std::ostream & os) const { os << contents; }

};



class Window_mgr {

public:

    using ScreenIndex = std::vector<Screen>::size_type;

    void clear(ScreenIndex i);


private:
    // 默认屏幕大小为24行80列，内容为空格
    std::vector<Screen> screens = { Screen(24, 80, ' ') };

};

// class Y {
//     X* p_x; // 指向X的指针
// };

// class X {
//     Y* p_y; // 指向Y的指针;
// };



#endif