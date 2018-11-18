#include "utility.h"

using namespace std;

class Solution {
public:
    Solution() {}
    bool leafSimilar(TreeNode* root1, TreeNode* root2);
    bool leafSimilarRecursive(TreeNode* root1, TreeNode* root2);
    void dfs(TreeNode* node, vector<int>& leaves);
};