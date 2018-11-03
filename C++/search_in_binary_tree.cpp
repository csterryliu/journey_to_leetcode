#include "./search_in_binary_tree.h"

#include <iostream>

using namespace std;

TreeNode* Solution::searchBST(TreeNode* root, int val) {
    if (root == NULL) return NULL;
    if (root->val == val) return root;
    return searchBST(root->val > val ? root->left : root->right, val);
}


int main() {
    TreeNode t1(4);
    t1.left = new TreeNode(2);
    t1.right = new TreeNode(7);
    t1.left->left = new TreeNode(1);
    t1.left->right = new TreeNode(3);
    Utility::traverseTreeByLevelOrder(&t1);
    Solution* sol = new Solution();
    TreeNode* output = sol->searchBST(&t1, 2);
    Utility::traverseTreeByLevelOrder(output);
    return 0;
}