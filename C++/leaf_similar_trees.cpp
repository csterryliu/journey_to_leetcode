#include "./leaf_similar_trees.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool Solution::leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> leaf_value_sequence;
    stack<TreeNode*> stack;
    // DFS: preorder traversal
    // O(T1 + T2) where T1 is the length of root1 and length is the size of root2
    stack.push(root1);
    while (stack.size()) {
        TreeNode* this_node = stack.top();
        stack.pop();
        if (this_node->left == NULL && this_node->right == NULL) {
            leaf_value_sequence.push_back(this_node->val); // leaf
        }
        if (this_node->right != NULL) {
            stack.push(this_node->right);
        }
        if (this_node->left != NULL) {
            stack.push(this_node->left);
        }
    }

    stack.push(root2);
    vector<int>::const_iterator iter = leaf_value_sequence.cbegin();
    while (stack.size()) {
        TreeNode* this_node = stack.top();
        stack.pop();
        if (this_node->left == NULL && this_node->right == NULL) {
            if ((*iter) == this_node->val) {
                ++iter;
            } else {
                return false;
            }
        }
        if (this_node->right != NULL) {
            stack.push(this_node->right);
        }
        if (this_node->left != NULL) {
            stack.push(this_node->left);
        }
    }

    return true;
}


bool Solution::leafSimilarRecursive(TreeNode* root1, TreeNode* root2) {
    // from leetcode
    vector<int> leaves1;
    vector<int> leaves2;
    dfs(root1, leaves1);
    dfs(root2, leaves2);

    return leaves1 == leaves2;
}

// top->button, left->right: preorder
void Solution::dfs(TreeNode* node, vector<int>& leaves) {
    if (node == NULL) return;
    if (node->left == NULL && node->right == NULL)
        leaves.push_back(node->val);
    dfs(node->left, leaves);
    dfs(node->right, leaves);
}


int main() {
    TreeNode t1(3);
    t1.left = new TreeNode(5);
    t1.right = new TreeNode(1);
    t1.left->left = new TreeNode(6);
    t1.left->right = new TreeNode(2);
    t1.left->right->left = new TreeNode(7);
    t1.left->right->right = new TreeNode(4);
    t1.right->left = new TreeNode(9);
    t1.right->right = new TreeNode(8);
    Utility::traverseTreeByLevelOrder(&t1);
    TreeNode t2(3);
    t2.left = new TreeNode(5);
    t2.right = new TreeNode(1);
    t2.left->left = new TreeNode(6);
    t2.left->right = new TreeNode(7);
    t2.right->left = new TreeNode(4);
    t2.right->right = new TreeNode(2);
    t2.right->right->left = new TreeNode(9);
    t2.right->right->right = new TreeNode(8);
    Utility::traverseTreeByLevelOrder(&t2);

    Solution* sol = new Solution();
    bool output = sol->leafSimilar(&t1, &t2);
    cout << output << "\n";
    output = sol->leafSimilarRecursive(&t1, &t2);
    cout << output << "\n";
    delete sol;
    return 0;
}