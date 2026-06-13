#include <cstddef>
#include <iostream>

class TreeNode {
    public:
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int val) {
            this->val = val;
            this->left = nullptr;
            this->right = nullptr;
        }
};

void printInorderTraversal(TreeNode *root) {
    if (root) {
        printInorderTraversal(root->left);
        std::cout << root->val << " ";
        printInorderTraversal(root->right);
    }
}

void printPreorderTraversal(TreeNode *root) {
    if (root) {
        std::cout << root->val << " ";
        printPreorderTraversal(root->left);
        printPreorderTraversal(root->right);
    }
}

void printPostorderTraversal(TreeNode *root) {
    if (root) {
        printPostorderTraversal(root->left);
        printPostorderTraversal(root->right);
        std::cout << root->val << " ";
    }
}

int main() {
    /*
     *            4
     *           / \
     *          3   5
     *         / \ / \
     *        1  2 6  7
     *
     * Inorder: 1 3 2 4 6 5 7
     * Preorder: 4 3 1 2 5 6 7
     * Postorder: 1 2 3 6 7 5 4
     */

    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    printInorderTraversal(root);
    std::cout << std::endl;
    printPreorderTraversal(root);
    std::cout << std::endl;
    printPostorderTraversal(root);
}
