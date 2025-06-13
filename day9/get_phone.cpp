#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

// 检查电话号码是否有效
bool valid(const std::string& phone) {
    // 增加数字格式验证
    return phone.size() == 11 && 
           std::all_of(phone.begin(), phone.end(), ::isdigit);
}

// 定义一个结构体来存储个人信息
struct PersonInfo {
    std::string name;
    std::vector<std::string> phone_vec;
};

int main() {

    std::vector<PersonInfo> person_vec;

    std::vector<std::string> files = {"file.txt", "file1.txt"};
    std::ifstream input_file;
    std::string line;
    std::string name, phone;

    // 使用 std::istringstream 来处理每一行的输入
    std::istringstream input_record;
    std::ostringstream formatted, valided;

    for (const auto& file : files) {
        input_file.open(file);

        if (!input_file) {
            std::cerr << "Error opening file: " << file << std::endl;
            continue; // 如果文件打开失败，跳过当前文件
        } else {
            std::cout << "Successfully opened file: " << file << std::endl;
        }

        while (getline(input_file, line)) {

            PersonInfo person;

            // 清空 input_record 和 formatted, valided 的内容
            input_record.clear();
            input_record.str(line); 
            formatted.str("");
            valided.str("");
            
            input_record >> person.name;

            std::cout << "Processing record for: " << person.name << std::endl;

            while (input_record >> phone) {
                if (valid(phone)) {
                    formatted << phone << " ";
                    person.phone_vec.push_back(phone);
                } else {
                    valided << phone << " ";
                }
            }
            
            if (!formatted.str().empty()) {
                std::cout << formatted.str() << "load success!" << std::endl;
            }

            if (!valided.str().empty()) {
                std::cout << valided.str() << "invalid phone numbers" << std::endl;
            } else {
                std::cout << "No invalid phone numbers found." << std::endl;
            }

            if (person.phone_vec.empty()) {
                std::cout << person.name << "'s phone list is empty!!!" << std::endl;
            } else {
                person_vec.push_back(std::move(person)); // 将 person 移动到 vector 中以避免不必要的复制
            }
            
            std::cout << "------------------------------------------" << std::endl;

        }

        input_file.close();
    }

    std::cout << "******************************************" << std::endl;

    // 输出所有人的信息
    std::cout << "All persons' information:" << std::endl;
    for (const auto & person : person_vec) {
        std::cout << "Name: " << person.name << " Phones: ";
        for (const auto &phone : person.phone_vec) {
            std::cout << phone << " ";
        }
        std::cout << std::endl; // 换行输出每个人的信息
    }

    return 0;
}