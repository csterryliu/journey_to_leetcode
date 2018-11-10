// This problem taught me: no silly solution
// Pursuing the best solution blindly is not practical

#include "./n-ary_tree_postorder_traversal.h"
#include <stack>
#include <iostream>

using namespace std;

vector<int> Solution::postorder(Node* root) {
    vector<int> output;
    if (root == NULL) {
        return output;
    }
    stack<Node*> temp;
    vector<Node*>::const_iterator iter;
    temp.push(root);
    // Depth-Fisrt Search postorder
    while (!temp.empty()) {
        Node* this_node = temp.top();
        output.push_back(this_node->val);
        temp.pop();
        for (iter = this_node->children.cbegin(); iter != this_node->children.cend(); ++iter) {
            temp.push((*iter));
        }
    }
    // Just reverse it!
    // Linear in half the distance between first and last: Swaps elements.
    // O(n/2)
    reverse(output.begin(), output.end());
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
    vector<int> output = sol->postorder(&tree);
    //Utility::printVector(output);
    return 0;
}