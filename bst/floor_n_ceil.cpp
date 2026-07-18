#include <iostream>
#include <vector>
#include "tree_node.h"

std::vector<int> getFloorNCeilFromBst(TreeNode *root, int value) {
    int ceil = -1;
    int floor = -1;

    TreeNode *node = root;
    while (node) {
        if (node->val == value) {
            ceil = value;
            floor = value;
            break; // Same Value can be floor & ceil, so break it
        }
        else if (node->val < value) {
            // This node->val has potential to be the floor value for the given "value",
            // so save it and move right
            floor = node->val;
            node = node->right;
        }
        else {
            // This node->val has potential to be the ceil value for the given "value",
            // so save it and move left
            ceil = node->val;
            node = node->left;
        }
    }

    return {floor, ceil};
}

int main() {
    /*
     *                8
     *              /  \
     *             4    12
     *            / \   / \
     *           2   6 10 14
     */
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(4);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);

    for(int val: getFloorNCeilFromBst(root, 11)) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    for(int val: getFloorNCeilFromBst(root, 15)) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
