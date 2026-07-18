#include <iostream>
#include "tree_node.h"

void inorder(TreeNode *root) {
    if (root) {
        inorder(root->left);
        std::cout << root->val << " ";
        inorder(root->right);
    }
}

TreeNode *insertIntoBst(TreeNode *root, int val) {
    // Tree is empty, so this new node becomes new tree's root
    // and return it
    if (root == nullptr)
        return new TreeNode(val);

    TreeNode *node = root;
    while (true) {
        // Current node's val is > target val, means this new val should be left
        if (node->val > val) {
            if (node->left == nullptr) {
                node->left = new TreeNode(val);
                break;
            }
            node = node->left;
        } else { // Current node's val is < target val, means this new val should be right
            if (node->right == nullptr) {
                node->right = new TreeNode(val);
                break;
            }
            node = node->right;
        }
    }

    return root;
}

int main() {
    /*
     *              10
     *              / \
     *             7   12
     *            / \  / \
     *           5  9 11 14
     */
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(7);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);

    std::cout << "Tree before insertion:" << std::endl;
    inorder(root);

    TreeNode *newRoot = insertIntoBst(root, 13);
    std::cout << "\nTree after insertion:" << std::endl;
    inorder(newRoot);

    return 0;
}
