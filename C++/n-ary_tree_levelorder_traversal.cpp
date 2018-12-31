#include "./n-ary_tree_levelorder_traversal.h"
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<int> > Solution::levelOrder(Node* root) {
    vector<vector<int> > output;
    if (root == NULL) return output;

    queue<Node*> q;
    q.push(root);

    // maybe it is O(n)?
    while (!q.empty()) {
        vector<int> row;
        int size_of_this_level = q.size();
        for (int i = 0; i < size_of_this_level; ++i) {  // consider the current queue size as the number of nodes in current level
            Node* this_node = q.front();
            if (!this_node->children.empty()) {
                vector<Node*>::const_iterator iter;
                for (iter = this_node->children.cbegin(); iter != this_node->children.cend(); ++iter) {
                    q.push(*iter);
                }
            }
            row.push_back(this_node->val);
            q.pop();
        }
        output.push_back(row);
    }
    return output;
}


int main() {
    Node tree;
    tree.val = 1;
    tree.children.push_back(new Node());
    tree.children.back()->val = 3;
    tree.children.back()->children.push_back(new Node());
    tree.children.back()->children.back()->val = 5;
    tree.children.back()->children.push_back(new Node());
    tree.children.back()->children.back()->val = 6;
    tree.children.push_back(new Node());
    tree.children.back()->val = 2;
    tree.children.push_back(new Node());
    tree.children.back()->val = 4;

    Solution* sol = new Solution();
    vector<vector<int> > output = sol->levelOrder(&tree);
    Utility::printVector(output[0]);
    Utility::printVector(output[1]);
    Utility::printVector(output[2]);
    return 0;
}