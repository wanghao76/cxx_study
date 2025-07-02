#include <string>
#include <set>

#include "Message.h"

void Message::save(Folder& f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder& f)
{
    folders.erase(&f);
    f.remMsg(this);
}

// 将本msg添加到给定msg的folders中
void Message::add_to_folders(const Message& msg)
{
    for (auto f : msg.folders) {
        f->addMsg(this);
    }
}

void Message::remove_from_folders()
{
    for (auto f : folders) {
        f->remMsg(this);
    }
}



Message::Message(const Message& msg) : contents(msg.contents), folders(msg.folders)
{
    add_to_folders(msg);
}

// 先确保folders集合中保存的folder对象中，完全删除了msg
// 自动析构string的contents, 以及自动调用set的析构函数来清理集合中成员使用的内存。
Message::~Message()
{
    remove_from_folders();
}

// 为什么不用copy and swap? 因为不涉及动态分配。用哪个效果都一样
Message& Message::operator=(const Message &msg)
{
    if (this == &msg) {
        return *this;
    }

    remove_from_folders();
    contents = msg.contents;
    folders = msg.folders;
    add_to_folders(msg);

    return *this;
}