#include<iostream>
#include<string>
#include<stdexcept>

int main()
{
    int val = 0;
    int sum = 0;

    // while (val <= 10) {
    //     sum += val; // 累加val的值
    //     val++; // val自增1
    // }

    // while (val <= 10) sum += val, val++; // 使用逗号运算符将两条语句合并为一条
    // std::cout << "Sum of numbers from 0 to 10: " << sum << std::endl; // 输出结果

    // int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // int count = 0;
    // int i;
    // for (i = 0; i < 10; ++i) {
    //     ++ count;
    //     if (count == 5) {
    //         break; // 当count等于5时，终止循环
    //     }
    // }

    // std::cout << "Loop terminated at index: " << i << std::endl; // 输出循环终止的索引
    // std::cout << "Count: " << count << std::endl; // 输出count的值

    // 说明for循环，一开始先进行初始化，在条件判断，然后执行循环体，最后进行自增操作， 然后重复后两步，直到条件不满足时，终止循环。
    // 自增操作是最后进行的！！！

    // // goto语句的使用示例
    // int i = 10;

    // // goto语句可以跳转到代码中的某个标签位置，通常用于跳出多层循环或条件语句。
    // // 但是在现代C++中，推荐使用更清晰的控制结构，如循环和函数来实现相同的功能。
    // // 下面的代码是一个示例，演示了如何使用goto语句来实现一个简单的循环。
    // // 注意：使用goto语句可能会导致代码难以理解和维护，因此在实际开发中应尽量避免使用。
    // begin:
    // if (i < 12) { 
    //     i += 1;
    //     goto begin;
    // }

    // std::cout << "Final value of i: " << i << std::endl; // 输出最终的i值

    // case的值必须是整型常量表达式，不能是变量或函数调用的结果。
    // switch语句的使用示例
    // switch (val) {
    //     case 0:
    //         std::cout << "Value is zero." << std::endl;
    //         break;
    //     case 1:
    //         std::cout << "Value is one." << std::endl;
    //         break;
    //     case 2:
    //         std::cout << "Value is two." << std::endl;
    //         break;
    //     default:
    //         std::cout << "Value is greater than two." << std::endl;
    //         break;
    // }

    // 异常示例
    try {
        // 这里可以放置可能抛出异常的代码
        throw std::runtime_error("This is a runtime error");
        // throw std::logic_error("This is a logic error");
        // throw std::out_of_range("This is an out_of_range error");
        // throw std::exception(); // 抛出一个通用异常
    } catch (const std::runtime_error& e) {
        // 捕获运行时错误异常并处理
        std::cout << "Caught a runtime_error exception: " << e.what() << std::endl;
    } catch (const std::logic_error& e) {
        // 捕获逻辑错误异常并处理
        std::cout << "Caught a logic_error exception: " << e.what() << std::endl;    
    } catch (const std::exception& e) {
        // 捕获通用异常并处理
    } catch (std::out_of_range& e) {
        // 捕获特定的异常类型
        std::cout << "Caught an out_of_range exception: " << e.what() << std::endl;
    } catch (...) {
        // 捕获所有其他类型的异常
        std::cout << "Caught an unknown exception" << std::endl;
    }
    // return 0;
}