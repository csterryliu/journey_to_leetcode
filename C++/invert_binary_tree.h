#include "utility.h"

using namespace std;

class Solution {
public:
    Solution() {}
    TreeNode* invertTree(TreeNode* root);
    void dfsPreOrder(TreeNode* root);
};