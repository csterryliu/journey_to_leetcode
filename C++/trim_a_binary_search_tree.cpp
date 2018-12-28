#include "./trim_a_binary_search_tree.h"

#include <iostream>

using namespace std;

TreeNode* Solution::trimBST(TreeNode* root, int l, int r) {
    // preorder traversal
    // time complexity: O(n), n is the total number of nodes in the given tree
    // space complexity: O(n)
    // Even though we don't explicitly use any additional memory, the call stack of our recursion could be as large as the number of nodes in the worst case.
    if (root == NULL) return root;
    if (root->val > r) return trimBST(root->left, l, r);  // since the value is greater than r, the whole right subtree is also greater than r. So the right subtree can be discarded.
    if (root->val < l) return trimBST(root->right, l, r);
    TreeNode* newSubTree = trimBST(root->left, l, r);
    if (root->left != newSubTree) {
        // delete the node
        delete root->left;
    }
    root->left = newSubTree;
    newSubTree = trimBST(root->right, l, r);
    if (root->right != newSubTree) {
        // delete the node
        delete root->right;
    }
    root->right = trimBST(root->right, l, r);

    return root;
}


int main() {
    TreeNode t1(1);
    t1.left = new TreeNode(0);
    t1.right = new TreeNode(2);
    Utility::traverseTreeByLevelOrder(&t1);
    // TreeNode t1(3);
    // t1.left = new TreeNode(0);
    // t1.right = new TreeNode(4);
    // t1.left->right = new TreeNode(2);
    // t1.left->right->left = new TreeNode(1);
    // TreeNode t1(45);
    // t1.left = new TreeNode(25);
    // t1.right = new TreeNode(75);
    // t1.left->right = new TreeNode(35);
    // t1.left->left = new TreeNode(15);
    //Utility::traverseTreeByLevelOrder(&t1);
    //Solution* sol = new Solution();
    //TreeNode* output = sol->trimBST(&t1, 1, 2);
    //TreeNode* test = sol->findSuccessor(&t1);
    //cout << test->val << "\n";
    //Utility::traverseTreeByLevelOrder(output);
    return 0;
}