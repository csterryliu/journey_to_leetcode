#include "./n-ary_tree_preorder_traversal.h"
#include <stack>
#include <iostream>

using namespace std;

vector<int> Solution::preorder(Node* root) {
    stack<Node*> temp;
    vector<int> output;
    temp.push(root);
    while (temp.size() > 0) {
        Node* this_node = temp.top();
        temp.pop();
        if (this_node->children.size() > 0) {
            for (vector<Node*>::iterator iter = (this_node->children.end())-1; iter != this_node->children.begin(); --iter) {
                cout << iter->val << "\n";
                temp.push(*iter);
            }
        }
        output.push_back(this_node->val);
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
    vector<int> output = sol->preorder(&tree);
    Utility::printVector(output);
    return 0;
}