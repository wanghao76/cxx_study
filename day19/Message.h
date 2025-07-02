#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <set>

class Folder;

class Message
{
friend Folder;
friend void swap(Message& lhs, Message& rhs);

public:
    Message(const std::string &str = "") : contents(str) {}
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();

    void save(Folder&); 
    void remove(Folder&);

    void addFolder(Folder* f) {
        folders.insert(f);
    }
    void remFolder(Folder* f) {
        folders.erase(f);
    }

private:
    std::string contents;
    std::set<Folder*> folders;

    void add_to_folders(const Message&); // 向Folders中添加消息
    void remove_from_folders(); // 向Folders中删除消息
};

inline
void swap(Message& lhs, Message& rhs) {

    using std::swap;
    for (auto f : lhs.folders) {
        // f->remMsg(&lhs);
    }
    for (auto f : rhs.folders) {
        // f->remMsg(&rhs);
    }

    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);

    for (auto f : lhs.folders) {
        // f->addMsg(&lhs);
    }
    for (auto f : rhs.folders) {
        // f->addMsg(&rhs);
    }
}

class Folder
{
public:
    Folder();
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();

    void addMsg(Message* msg) {
        messages.insert(msg);
    }

    void remMsg(Message* msg) {
        messages.erase(msg);
    }

private:
    std::set<Message*> messages;
};


#endif // MESSAGE_H