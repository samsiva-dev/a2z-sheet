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

int maxDepth(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + std::max(leftDepth, rightDepth);
}

int main() {
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    std::cout << "Maximum depth: " << maxDepth(root) << std::endl;

    return 0;
}
