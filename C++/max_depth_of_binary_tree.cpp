#include "./max_depth_of_binary_tree.h"

#include <iostream>
#include <queue>

using namespace std;

int Solution::maxDepth(TreeNode* root, int dep=0) {
    // DFS
    if (root == NULL) return dep;
    //maxDepth(root->left, dep+1);
    //maxDepth(root->right, dep+1);
    //cout << root->val << " ";
    return max(maxDepth(root->left, dep+1), maxDepth(root->right, dep+1));
}


int main() {
    TreeNode t1(3);
    t1.left = new TreeNode(9);
    t1.right = new TreeNode(20);
    t1.right->left = new TreeNode(15);
    t1.right->right = new TreeNode(7);
    Utility::traverseTreeByLevelOrder(&t1);
    
    Solution* sol = new Solution();
    int output = sol->maxDepth(&t1);
    cout << output << "\n";
    return 0;
}