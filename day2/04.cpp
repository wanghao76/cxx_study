#include<iostream>
#include<string>

using namespace std;

int main() {

    // string s1, s2;

    // cin >> s1 >> s2;

    // std::cout << "s1 is: " << s1 << std::endl;
    // std::cout << "s2 is: " << s2 << std::endl;

    // while (cin >> s1) {
    //     std::cout << "s1 is: " << s1 << std::endl;
    // }

    // while (getline(cin, s1)) {
    //     std::cout << "s1 is: " << s1 << std::endl;
    // }

    // 由于s1.size() 返回的是size_t类型, 而不是int类型, 因此不能直接与int类型进行比较
    // s1 = "hello";
    // int n = -2;
    
    // std::string::size_type len = s1.size();
    
    // bool is_upper = (s1.size() < n); 
    // std::cout << "s1.size() < n: " << std::boolalpha << is_upper << std::endl;

    // 这是因为 s1.size() 返回的是 size_type 类型，而 n 是 int 类型，size_type 是无符号类型，因此在比较时会将 n 转换为无符号类型，这可能导致比较结果不符合预期。甚至如果放到循环语句中,可能导致死循环!!!!

    /* 
    
    推荐使用cstdio, cctype, cstring, cstdlib 等 C 标准库头文件来处理字符串和字符相关的操作, 因为标准库的名字总能在命名空间std中找到. 例如, ctype.h 中的函数可以在 std:: 中找到, 如 std::isdigit, std::isalpha 等等.
    
    如果用stdio.h, ctype.h, string.h, stdlib.h 的区分哪些是c继承的,哪些是c++独有的

    */ 

    // string s = "Hello world !!!!!";

    // decltype(s.size()) punct_cnt = 0;

    // for (auto c : s) {
    //     if (ispunct(c)) { // 检查字符是否是标点符号
    //         ++punct_cnt; // 如果是标点符号，计数器加1
    //     }
    // }

    // cout << "Number of punctuation characters: " << punct_cnt << endl;

    // std::string s = "hello world!";

    // for (auto &c : s) {
    //     if (std::islower(c)) { // 检查字符是否是小写字母
    //         c = std::toupper(c); // 如果是小写字母，将其转换为大写字母
    //     }
    // }

    // std::cout << "Transformed string: " << s << std::endl; // 输出转换后的字符串

    // std::string s = "hello world!";

    // 如果要使用string中的下标,则一定要判空!
    // if (s.empty()) {
    //     std::cout << "The string is empty." << std::endl;
    //     return 0; // 如果字符串为空，直接返回
    // }

    // 注意这里使用了 decltype(s.size()) 来声明 i 的类型，这样可以确保 i 的类型与 s.size() 的返回类型一致
    // 这样可以避免在比较时出现类型不匹配的问题
    // 这里使用了 std::isspace 来检查字符是否是空格字符
    // 如果是空格字符或者是末尾，则停止转换
    // 注意 i < s.size() && !std::isspace(s[i]); 这里在c++中会先判断&&左侧的i值, 所以&&右侧中s[i]是安全的, 不会越界
    // for (decltype(s.size()) i = 0; 
    //      i < s.size() && !std::isspace(s[i]); ++i) {
    //     s[i] = std::toupper(s[i]); // 将小写字母转换为大写字母
    // }
    
    // std::cout << "Transformed string: " << s << std::endl; // 输出转换后的字符串
    
    std::string s = "hello world!";

    for (auto &c : s) {
        c = 'X';
    }

    std::cout << "Transformed string: " << s << std::endl; // 输出转换后的字符串


    for (char &c : s) {
        c = 'Y'; // 将每个字符都转换为 'Y'
    }   

    std::cout << "Transformed string: " << s << std::endl; // 输出转换后的字符串

    std::string s1;
    std::cout << "s1 first letter is " << s1[0] << std::endl; // 能够成功运行

    std::string s2 = "hello world!!!!!";

    std::string s3;
    for (auto &c : s2) {
        if (!std::ispunct(c)) {
            // 去除标点符号
            s3 += c;
        }
    }

    std::cout << "Transformed string: " << s3 << std::endl; // 输出转换后的字符串

    const string s4 = "Keep Calm and Carry On";

    for (auto &c : s4) {
        std::cout << c; // 输出每个字符
    }
    std::cout << std::endl;

    return 0;
}