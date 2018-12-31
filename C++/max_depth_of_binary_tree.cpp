#include "./max_depth_of_binary_tree.h"

#include <iostream>
#include <queue>

using namespace std;

int Solution::maxDepth(TreeNode* root) {
    // DFS
    // time complexity: O(n)
    // space complexity: O(n) for worst case (unbalanced tree)
    //                   O(logn) for best case (balanced tree)
    if (root == NULL) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
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