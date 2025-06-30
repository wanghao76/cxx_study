#include <iostream>
#include <string>

#include "Tree.h"

TreeNode::~TreeNode() {
    if (--*use_count == 0) {
        delete left;
        delete right;
        delete use_count;
    }
}

TreeNode& TreeNode::operator=(const TreeNode& tn)
{
    if (this == &tn) {
        return *this;
    }

    ++*tn.use_count;

    if (--*use_count != 0) {
        delete left;
        delete right;
        delete use_count;
    }

    value = tn.value;
    count = tn.count;
    left = tn.left;
    right = tn.right;
    use_count = tn.use_count;

    return *this;
}


BinStrTree& BinStrTree::operator=(const BinStrTree& bst)
{
    if (this == &bst) {
        return *this;
    }

    TreeNode *temp = new TreeNode(*bst.root);
    delete root;
    root = temp;

    return *this;

}
