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

bool checkBoundaries(TreeNode *node, int *low_limit, int *high_limit) {
    if (node == nullptr)
        return true;

    if ((low_limit != nullptr && node->val <= *low_limit)
        || (high_limit != nullptr && node->val >= *high_limit)) {
        return false;
    }

    return (
        checkBoundaries(node->left, low_limit, &node->val) &&
        checkBoundaries(node->right, &node->val, high_limit)
    );
}


bool isValidBST(TreeNode *root) {
    return checkBoundaries(root, nullptr, nullptr);
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

    std::cout << isValidBST(root) << std::endl;

    return 0;
}
