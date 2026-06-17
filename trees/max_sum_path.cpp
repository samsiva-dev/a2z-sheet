#include <iostream>
#include <climits>

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

/*
 * Key Idea: Recursively calculate the maximum sum path for each subtree,
 * and update the maximum sum found so far (maxSum i.e leftSum + rightSum + root->val)
 * Return the maximum of the two plus the root's (current) value.
 */
int maxSumPath(TreeNode *root, int &maxSum) {
    if (root == nullptr) {
        return 0;
    }

    int leftSum = maxSumPath(root->left, maxSum);
    int rightSum = maxSumPath(root->right, maxSum);

    maxSum = std::max(maxSum, root->val + leftSum + rightSum);

    return std::max(leftSum, rightSum) + root->val;
}

int main() {
    /*
     *
     * Constructing the following tree:
     *
     *       1
     *      / \
     *     2   3
     *    / \ / \
     *   4  5 6  7
     *
     * The maximum sum path is 1 + 3 + 7 = 11.
     */
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int maxSum = INT_MIN;
    maxSumPath(root, maxSum);
    std::cout << maxSum << std::endl;
    return 0;
}
