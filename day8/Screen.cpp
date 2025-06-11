#include <iostream>

#include "Screen.h"

// 这里的inline关键字表示该函数是内联函数，编译器会尝试将其展开到调用处，以提高性能
// 但是，编译器并不一定会遵循这个建议，具体取决于编译器的优化策略和函数的复杂性。

Screen & Screen::move(pos r, pos c) {

    
    pos row = r * width; // 计算行偏移

    if ((row + c) >= contents.size()) { // 检查是否越界
        std::cerr << "Error: Move out of bounds!" << std::endl; // 输出错误信息
        return *this; // 返回当前对象的引用
    }

    cursor = row + c; // 更新光标位置
    
    return *this; // 返回当前对象的引用
}

Screen & Screen::set(char c) {
    contents[cursor] = c; // 设置光标位置的字符
    return *this; // 返回当前对象的引用
}

Screen & Screen::set(pos r, pos c, char ch) {
    pos index = r * width + c; // 计算指定位置的索引
    if (index < contents.size()) { // 检查索引是否在内容范围内
        contents[index] = ch; // 设置指定位置的字符
    } else {
        std::cerr << "Error: Set out of bounds!" << std::endl; // 输出错误信息
    }

    return *this; // 返回当前对象的引用
}

void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i]; // 获取指定屏幕

    s.contents = std::string(s.height* s.width, BLANK); // 清空屏幕内容
}