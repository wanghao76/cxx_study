#include <iostream>
#include <string>
#include <initializer_list>

#include "chapter6.h"

void error_msg(ErrCode e, std::initializer_list<std::string> il) {
    switch (e) {
        case ErrCode::OK:
            std::cout << "No errors." << std::endl;
            break;
        case ErrCode::INVALID:
            std::cerr << "Invalid input: ";
            for (const auto& msg : il) {
                std::cerr << msg << " ";
            }
            std::cerr << std::endl;
            break;
        case ErrCode::NULLPTR:
            std::cerr << "Error: Null pointer encountered." << std::endl;
            break;
        case ErrCode::UNKNOWN:
            std::cerr << "Unknown error occurred." << std::endl;
            break;
        default:
            std::cerr << "Unhandled error code." << std::endl;
            break;
    }
}