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

// Recusrive approach
bool isKeyExistsInBstRecursive(TreeNode *root, int key) {
    if (root == nullptr)
        return false;

    if (root->val == key)
        return true;

    if (root->val > key)
        return isKeyExistsInBstRecursive(root->left, key);

    return isKeyExistsInBstRecursive(root->right, key);
}


// Iterative approach
bool isKeyExistsInBst(TreeNode *root, int key) {
    if (root == nullptr)
        return false;

    TreeNode *node = root;

    bool found = false;
    while (node) {
        if (node->val == key) {
            found = true;
            break; // found the key, break and return
        }

        if (node->val > key) {
            // search in left sub-tree
            node = node->left;
        } else {
            // search in right sub-tree
            node = node->right;
        }
    }

    return found;
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

    std::cout << isKeyExistsInBst(root, 11) << "\n";
    std::cout << isKeyExistsInBst(root, 9) << "\n";
    std::cout << isKeyExistsInBst(root, 20) << "\n";

    std::cout << isKeyExistsInBstRecursive(root, 11) << "\n";
    std::cout << isKeyExistsInBstRecursive(root, 9) << "\n";
    std::cout << isKeyExistsInBstRecursive(root, 20) << "\n";

    return 0;
}
