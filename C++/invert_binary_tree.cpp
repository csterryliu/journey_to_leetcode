#include "./invert_binary_tree.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

TreeNode* Solution::invertTree(TreeNode* root) {
    // O(n)
    dfsPreOrder(root);
    return root;
}

void Solution::dfsPreOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    if (root->left != NULL || root->right != NULL) {
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    dfsPreOrder(root->left);
    dfsPreOrder(root->right);
}

int main() {
    // TreeNode t1(4);
    // t1.left = new TreeNode(2);
    // t1.right = new TreeNode(7);
    // t1.left->left = new TreeNode(1);
    // t1.left->right = new TreeNode(3);
    // t1.right->left = new TreeNode(6);
    // t1.right->right = new TreeNode(9);
    TreeNode t1(1);
    t1.left = new TreeNode(2);
    Utility::traverseTreeByLevelOrder(&t1);
    

    Solution* sol = new Solution();
    TreeNode* output = sol->invertTree(&t1);
    Utility::traverseTreeByLevelOrder(output);
    delete sol;
    return 0;
}