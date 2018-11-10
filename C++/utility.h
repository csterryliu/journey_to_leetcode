#include <vector>

using namespace std;

// Definition for a binary tree
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

// Definition for an n-ary tree
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

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Utility {
    public:
        Utility() {}
        static void printVector(vector<int>& v);
        static void printSinglyLinkList(ListNode* head);
        static void swapValues(int& a, int& b);
        static void traverseTreeByLevelOrder(TreeNode* tree);
};