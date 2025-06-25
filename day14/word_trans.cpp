#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <fstream>
#include <sstream>
#include <stdexcept>

const std::unordered_map<std::string, std::string> build_map(std::ifstream& file);
const std::string& word_trans(const std::string& word, const std::unordered_map<std::string, std::string>& word_rules);
void content_trans(std::ifstream& word_file, std::ifstream& input);


int main() 
{
    // 单词转换程序
    std::ifstream in("content.txt");
    std::ifstream rule("rule.txt");
    content_trans(rule, in);

    return 0;
}

const std::unordered_map<std::string, std::string> build_map(std::ifstream& file) {
    std::string word;
    std::string content;
    std::unordered_map<std::string, std::string> trans_map;
    while (file >> word && getline(file, content)) {
        if (content.size() > 1) {
            trans_map[word] = content.substr(1); // 下标运算符保留最后一次添加的结果
            // trans_map.insert({word, content.substr(1)}); // 使用insert保留的是第一次添加的结果。根据使用场景进行选择。
        } else {
            throw std::runtime_error("no rule for " + word);
        }
    }
    return trans_map;
}

const std::string& word_trans(const std::string& word, 
    const std::unordered_map<std::string, std::string>& word_rules) {
    
    auto it = word_rules.find(word);
    word_rules.bucket_count();
    // std::cout << "bucket count: " << word_rules.bucket_count() << std::endl;
    // auto it = word_rules[word]; // 不能这么写，因为word_rules是map类型，不能直接用[]运算符来查找，如果没有找到会插入一个新元素。

    if (it != word_rules.cend()) {
        return it->second;
    } 

    return word;
}

void content_trans(std::ifstream& word_file, std::ifstream& input) {
    auto word_rules = build_map(word_file);

    std::string text;
    while (getline(input, text)) { 
        std::istringstream input_record(text);
        std::string word;
        
        bool is_first_word = true;

        while (input_record >> word) {
            if (is_first_word) {
                is_first_word = false;
            } else {
                std::cout << " ";
            }

            std::cout << word_trans(word, word_rules);
        }
        std::cout << std::endl;
    }

}