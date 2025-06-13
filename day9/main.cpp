#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

bool valid(const std::string &phone) {
    return phone.size() == 11; 
}

bool process(std::string& line);

int main() {

    // 刷新缓冲区，endl 换行，flush不加任何额外字符，ends加入一个空字符后刷新
    // std::cout << "Hello, World!" << std::endl;
    // std::cout << "hello, World!" << std::flush;
    // std::cout << "Hello, World!" << std::ends;

    // 设置流为无缓冲模式，此后输出都是立即刷新。
    // std::cout << std::unitbuf;
    // 回到正常缓冲模式
    // std::cout << std::nounitbuf;

    // 如果程序崩溃，输出缓冲区不会刷新。

    
    // std::cin.tie(nullptr); // 解除 cin 和 cout 的绑定

    // 读取cin 刷新cout
    // std::cin.tie(&std::cout); // 重新绑定 cin 和 cout

    // 读书cin，刷新cerr
    // std::cin.tie(&std::cerr); // 绑定 cin 和 cerr

    // 读取单个文件
    // std::string file = "file.txt";
    // std::ifstream input(file);
    // std::vector<std::string> lines;

    // if (input.is_open()) {
    //     std::string line; 
    //     while (std::getline(input, line)) {
    //         lines.push_back(line);
    //     }
    //     input.close();

    //     for (auto &l : lines) {
    //         std::cout << l << std::endl; // 输出每一行
    //     }

    // } else {
    //     std::cerr << "Error opening file: " << file << std::endl;
    // }

    // lines.clear(); // 清空之前的内容

    // 读取多个文件

    // std::vector<std::string> lines; // 用于存储读取的行
    // std::vector<std::string> files = {"file.txt", "file1.txt"};
    // std::ifstream input_file;
    // for (const auto &f : files) {
    //     input_file.open(f);
    //     if (input_file.is_open()) {
    //         std::string line;
    //         while (std::getline(input_file, line)) {
    //             lines.push_back(line);
    //         }
    //         input_file.close();
    //     } else {
    //         std::cerr << "Error opening file: " << f << std::endl;
    //     }
    // }

    // for (const auto &l : lines) {
    //     std::cout << l << std::endl; // 输出每一行
    // }

    // std::string o_file = "output.txt";
    // std::fstream output(o_file, std::ios::out | std::ios::app); // 以写模式打开，不存在会自动创建

    // if (output.is_open()) {
    //     output << "Hello, World!" << std::endl;
    //     output << "This is a test." << std::endl;
    //     output.close();
    // } else {
    //     std::cerr << "Error opening file for writing: " << o_file << std::endl;
    // }

    // 使用 std::istringstream 格式化读入流
    // *其实 istringstream, ostringstream不仅可以跟iostrean(cin,cout)配合，还可以跟iofstream配合使用。
    // struct PersonInfo {
    //     std::string name;
    //     std::vector<std::string> phone_vec;
    // };

    // std::vector<PersonInfo> people_vec;
    // std::string line, phone;

    // std::istringstream record;

    // while(getline(std::cin, line)) {
    //     if (line == "q" || line == "Q") {
    //         break; // 如果输入是 q 或 Q，则退出循环
    //     }

    //     if (line.empty()) {
    //         continue; // 跳过空行
    //     }
        
         // 也可以直接这样：std::istringstream record(line);
    //     record.clear(); // 清除之前的状态
    //     record.str(line); // 将当前行的内容放入 record 中

         // 用 record >> 变量 逐个提取单词（以空格分隔），就像从 cin 读取一样。
    //     PersonInfo info;
    //     record >> info.name;
        
    //     while (record >> phone) {
    //         info.phone_vec.push_back(phone);
    //     }

         // 检查是否有电话号码和姓名
    //     if (info.phone_vec.empty() || info.name.empty()) {
    //         std::cerr << "No data?!" << std::endl;
    //         continue; 
    //     }

         // 将读取到的姓名和电话号码信息存储到 people_vec 中
    //     people_vec.push_back(info);
    // }

    // for (const auto &person : people_vec) {
    //     std::cout << person.name << " ";
    //     for (const auto &phone_num : person.phone_vec) {
    //         std::cout << phone_num << " ";
    //     }
    //     std::cout << std::endl; // 换行输出每个人的信息
    // }

    // std::cout << "------------------------------------------" << std::endl;

     // 使用ostringstream验证电话号码
    // for (const auto &person : people_vec) {
    //     std::ostringstream formatted, invalid;
    //     for (const auto &phone : person.phone_vec) {
    //         if (!valid(phone)) {
    //             invalid << " " << phone;
    //         } else {
    //             formatted << " " << phone;
    //         }
    //     }

    //     if (invalid.str().empty()) {
    //         std::cout << person.name << " " << formatted.str() << std::endl;
    //     } else {
    //         std::cerr << "Invalid phone number(s) for " << person.name 
    //                   << ": " << invalid.str() << std::endl;
    //     }
     
    // }

    return 0;
}