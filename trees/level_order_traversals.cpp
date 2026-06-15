#include <iostream>
#include <vector>

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

std::vector<std::vector<int>> levelOrderTraversals(TreeNode *root) {
    std::vector<TreeNode*> queue = {root};

    std::vector<std::vector<int>> result;

    while (!queue.empty()) {
        int levelSize = static_cast<int>(queue.size());

        std::vector<int> level;
        for (int i = 0; i < levelSize; i++) {
            TreeNode *node = queue.front();
            queue.erase(queue.begin());
            level.push_back(node->val);
            if (node->left) {
                queue.push_back(node->left);
            }
            if (node->right) {
                queue.push_back(node->right);
            }
        }
        result.push_back(level);
    }
    return result;
}

int main() {
    /*
     *            4
     *           / \
     *          3   5
     *         / \ / \
     *        1  2 6  7
     *
     * Level Order: [4]
     *              [3 5]
     *              [1 2 6 7]
     */

    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    std::vector<std::vector<int>> result = levelOrderTraversals(root);
    for (const auto &level : result) {
        for (int val : level) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}
