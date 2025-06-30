#include <iostream>

#include "CDocument.h"

void CDocument::OnOpenFile() {
    std::cout << "dialog..." << std::endl;
    std::cout << "check file status..." << std::endl;
    std::cout << "open file..." << std::endl;
    // 这里调的是子类复写的Serialize方法
    Serialize();
    std::cout << "read file..." << std::endl;
    // 这里也是调的是子类复写的printContent方法
    printContent();
    std::cout << "update file..." << std::endl;
    std::cout << "save file..." << std::endl;
    std::cout << "close file ..." << std::endl;
    std::cout << "update all views" << std::endl;
}

void CDocument::printContent() const {
    std::cout << "call CDocument::printContent()" << std::endl;

}

void MyDoc::Serialize() const {
    std::cout << "call MyDoc::Serialize()" << std::endl;
}

void MyDoc::printContent() const {
    std::cout << "call MyDoc::printContent()" << std::endl;
    std::cout << "Notify news: " << notify.getNews() << std::endl;
}