#include<iostream>
#include<vector>
#include<string>

int main() {
    // std::vector<std::string> vec{
    //     "hello world!",
    //     "C++ is great.",
    //     "I love programming.",
    //     "Let's learn C++ together!"
    // };

    // std::vector<std::string> vec2(vec);

    // std::vector<std::string> vec3(10, "null");

    // for (const auto &s : vec3) {
    //     std::cout << s << std::endl; // 输出每个字符串
    // }
    // // decltype(vec2.size()) n = 10;
    
    // std::vector<std::string>::size_type n = 10;

    // std::vector<std::string> vec3(n, "default string");

    // for (const auto &s : vec3) {
    //     std::cout << s << std::endl; // 输出每个字符串
    // }

    // std::vector<int> i_v;
    // int i;
    // while (std::cin >> i) {
    //     if (i == 0) {
    //         break; // 如果输入为0，则退出循环
    //     }
    //     i_v.push_back(i); // 将输入的整数添加到 vector 中
    // }

    // std::cout << "You entered: ";
    // for (const auto &num : i_v) {
    //     std::cout << num << " "; // 输出每个整数
    // }
    // std::cout << std::endl;

    // std::vector<std::string> s_v;
    // std::string s;
    // while(getline(std::cin, s)) {
    //     if (s.empty()) {
    //         break; // 如果输入为空行，则退出循环
    //     }
    //     s_v.push_back(s); // 将输入的字符串添加到 vector 中
    // }

    // std::cout << "You entered: " << std::endl;

    // for (const auto &str : s_v) {
    //     std::cout << str << std::endl; // 输出每个字符串
    // }

    // // 转换字符串中的小写字母为大写字母
    // std::vector<std::string> s_v;
    // std::string s;
    // while(getline(std::cin, s)) {
    //     if (s.empty()) {
    //         break; // 如果输入为空行，则退出循环
    //     }
    //     s_v.push_back(s); // 将输入的字符串添加到 vector 中
    // }

    // // std::cout << "You entered: " << std::endl;
    // for (auto &str : s_v) {
    //     for (auto &c : str) {
    //         if (std::islower(c)) { // 检查字符是否是小写字母
    //             c = std::toupper(c); // 如果是小写字母，将其转换为大写字母
    //         }
    //     }
    // }

    // std::cout << "Transformed strings: " << std::endl;
    // for (const auto &str : s_v) {
    //     std::cout << str << std::endl; // 输出转换后的字符串
    // }



    // std::vector<int> nums;
    // int n;
    // std::cout << "请输入一组整数，以非数字结束：" << std::endl;
    // while (std::cin >> n) {
    //     nums.push_back(n);
    // }

    // // 输出每对相邻整数的和
    // std::cout << "每对相邻整数的和：" << std::endl;
    // for (size_t i = 1; i < nums.size(); ++i) {
    //     std::cout << nums[i - 1] + nums[i] << " ";
    // }
    // std::cout << std::endl;

    // // 输出第1个和最后1个元素的和，第2个和倒数第2个元素的和，以此类推
    // std::cout << "首尾对应元素的和：" << std::endl;
    // size_t sz = nums.size();
    // for (size_t i = 0; i < sz / 2; ++i) {
    //     std::cout << nums[i] + nums[sz - 1 - i] << " ";
    // }
    // // 如果元素个数为奇数，中间那个元素单独输出
    // if (sz % 2 == 1) {
    //     std::cout << nums[sz / 2];
    // }
    // std::cout << std::endl;

    // std::string s1 = "hello world!";

    // for (std::string::iterator it = s1.begin(); it != s1.end() && !std::isspace(*it); ++it) {
    //     *it = std::toupper(*it); // 将每个字符转换为大写字母
    // } 

    // std::cout << "Transformed string: " << s1 << std::endl; // 输出转换后的字符串

    std::vector<int> nums = {10, 22, 32, 34, 45};

    std::vector<int>::iterator it = nums.begin();
    auto it2 = it + 2;

    auto num = it2 - it;
    
    std::cout << "The distance between the two iterators is: " << num << std::endl; // 输出迭代器之间的距离
    // std::cout << std::endl;

    auto j = it2 > it;
    std::cout << "Is it2 greater than it? " << (j ? "Yes" : "No") << std::endl; // 输出迭代器比较结果
    
    return 0;
}