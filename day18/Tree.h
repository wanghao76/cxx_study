#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <string>

class TreeNode {

public:
    TreeNode() : 
        value(std::string()), count(0), left(nullptr), right(nullptr), use_count(new std::size_t(1)) {}
    
    TreeNode(const TreeNode& tn) : 
        value(tn.value), count(tn.count), left(tn.left), right(tn.right), use_count(tn.use_count)  { ++*use_count; }
    TreeNode& operator=(const TreeNode&);
    ~TreeNode();

private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;

    std::size_t *use_count;
};


class BinStrTree {

public:
    BinStrTree() : root(new TreeNode()) {}
    
    BinStrTree(const BinStrTree& bst) : root(new TreeNode(*bst.root)) {}
    BinStrTree& operator=(const BinStrTree& bst);
    ~BinStrTree() { delete root; };

private:
    TreeNode *root;
};

#endif