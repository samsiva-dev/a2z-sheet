#include <iostream>
#include <vector>
#include "tree_node.h"

void inorderTraversal(TreeNode *root, std::vector<int> &result) {
    if (root) {
        inorderTraversal(root->left, result);
        result.push_back(root->val);
        inorderTraversal(root->right, result);
    }
}

// Constraint: Key always exists
std::vector<int> inorderSuccessorNPredecessor(TreeNode *root, int key) {

    std::vector<int> inorder;
    inorderTraversal(root, inorder);

    int n = inorder.size();
    int left = 0, right = n-1;
    int position = -1;
    while (left <= right) {
        int mid = left + (right - left)/2;

        if (inorder[mid] == key) {
            position = mid;
            break;
        }
        else if (inorder[mid] > key) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return {
        position == 0 ? -1: inorder[position-1],
        position == n-1 ? -1: inorder[position+1]
    };
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
