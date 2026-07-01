#include <iostream>
#include <algorithm>

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

int diameter;

int diameterOfTheTree(TreeNode *root) {
    if (root == nullptr)
        return 0;

    int left_height = diameterOfTheTree(root->left);
    int right_height = diameterOfTheTree(root->right);

    diameter = std::max(diameter, left_height + right_height);

    return 1 + std::max(left_height, right_height);
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    diameter = 0;
    (void) diameterOfTheTree(root);
    std::cout << diameter << std::endl;

    return 0;
}
