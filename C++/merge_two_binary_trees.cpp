#include "./merge_two_binary_trees.h"
#include <queue>
#include <iostream>

using namespace std;

TreeNode* Solution::mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 == NULL && t2 != NULL) return t2;
    if (t1 != NULL && t2 == NULL) return t1;
    // use level-order traversal
    queue<TreeNode*> q1;
    q1.push(t1);
    q1.push(t2);
    TreeNode* pt1 = NULL;
    TreeNode* pt2 = NULL;
    while (q1.size() > 0) {
        pt1 = q1.front();
        q1.pop();
        pt2 = q1.front();
        q1.pop();
        if (pt1 != NULL && pt2 != NULL) {
            pt1->val += pt2->val;
        }
        if (pt2 != NULL) {
            if (pt1->left == NULL && pt2->left != NULL) {
                pt1->left = new TreeNode(0);
            }
            if (pt1->right == NULL && pt2->right != NULL) {
                pt1->right = new TreeNode(0);
            }
        }
        
        if (pt1 != NULL || pt2 != NULL) {
            q1.push(pt1 != NULL ? pt1->left : NULL);
            q1.push(pt2 != NULL ? pt2->left : NULL);
            q1.push(pt1 != NULL ? pt1->right : NULL);
            q1.push(pt2 != NULL ? pt2->right : NULL);
        }
    }
    return t1;
}

// this method is better than leve-order: more straghtforword and simple
TreeNode* Solution::mergeTreesRecursive(TreeNode* t1, TreeNode* t2) {
    if (t1 && t2) {
        TreeNode* root = new TreeNode(t1->val+t2->val);
        root->left = mergeTreesRecursive(t1->left, t2->left);
        root->right = mergeTreesRecursive(t1->right, t2->right);
        return root;
    } else {
        return t1 ? t1 : t2;
    }
}


int main() {
    TreeNode t1(1);
    t1.left = new TreeNode(3);
    t1.right = new TreeNode(2);
    t1.left->left = new TreeNode(5);
    Utility::traverseTreeByLevelOrder(&t1);

    TreeNode t2(2);
    t2.left = new TreeNode(1);
    t2.right = new TreeNode(3);
    t2.left->right = new TreeNode(4);
    t2.right->right = new TreeNode(7);
    Utility::traverseTreeByLevelOrder(&t2);

    Solution* sol = new Solution();
    TreeNode* output = sol->mergeTreesRecursive(&t1, &t2);
    Utility::traverseTreeByLevelOrder(output);
    return 0;
}