#include <vector>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Node {
    public:
        int val;
        vector<Node*> children;
        Node() {}

        Node(int _val, vector<Node*> _children) {
            val = _val;
            children = _children;
        }
};

class Utility {
    public:
        Utility() {}
        static void printVector(vector<int>& v);
        static void swapValues(int& a, int& b);
        static void traverseTreeByLevelOrder(TreeNode* tree);
};