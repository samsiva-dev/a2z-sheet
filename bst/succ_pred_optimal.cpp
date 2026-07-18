#include <iostream>
#include <vector>
#include "tree_node.h"

// Constraint: Key always exists
std::vector<int> inorderSuccessorNPredecessor(TreeNode *root, int key) {
    int predecessor = -1, successor = -1;
    TreeNode *node = root;

    // Phase 1: walk down to the key, tracking candidates as we go.
    // Moving right past a node means that node is < key -> predecessor candidate.
    // Moving left past a node means that node is > key -> successor candidate.
    while (node->val != key) {
        if (node->val < key) {
            predecessor = node->val;
            node = node->right;
        } else {
            successor = node->val;
            node = node->left;
        }
    }

    // Phase 2: node now sits exactly on the key.
    // True predecessor = rightmost node of key's left subtree (if it exists).
    if (node->left) {
        TreeNode *temp = node->left;
        while (temp->right) temp = temp->right;
        predecessor = temp->val;
    }

    // True successor = leftmost node of key's right subtree (if it exists).
    if (node->right) {
        TreeNode *temp = node->right;
        while (temp->left) temp = temp->left;
        successor = temp->val;
    }

    return {predecessor, successor};
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

    std::vector<int> result = inorderSuccessorNPredecessor(root, 12);
    std::cout << "#1" << std::endl;
    std::cout << "Predecessor: " << result[0] << std::endl;
    std::cout << "Successor: " << result[1] << std::endl;

    result = inorderSuccessorNPredecessor(root, 14);
    std::cout << "#2" << std::endl;
    std::cout << "Predecessor: " << result[0] << std::endl;
    std::cout << "Successor: " << result[1] << std::endl;
    return 0;
}
