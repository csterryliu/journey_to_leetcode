#include "./trim_a_binary_search_tree.h"

#include <iostream>

using namespace std;

TreeNode* Solution::trimBST(TreeNode* root, int l, int r) {
    // inorder traversal
    if (root == NULL) return NULL;
    trimBST(root->left, l, r);
    cout << root->val << " ";
    if (root->val > r || root->val < l) {
        cout << "delete " << root->val << "\n"; 
    }
    trimBST(root->right, l, r);
    return NULL;
}

TreeNode* Solution::findSuccessor(TreeNode* root) {
    TreeNode* temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
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