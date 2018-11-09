#include "./n-ary_tree_preorder_traversal.h"
#include <stack>
#include <iostream>

using namespace std;

vector<int> Solution::preorder(Node* root) {
    vector<int> output;
    if (root == NULL) {
        return output;
    }
    stack<Node*> temp;
    temp.push(root);
    vector<Node*>::iterator iter;
    // we visit each node exactly once, and for each visit, the complexity of the operation (i.e. appending the child nodes) is proportional to the number of child nodes n (n-ary tree). 
    // so the time complexity may be close to O(N). 
    // Where N is the number of nodes, i.e. the size of tree.
    while (temp.size() > 0) {
        Node* this_node = temp.top();
        temp.pop();
        if (this_node->children.size() > 0) {
            for (iter = --(this_node->children.end()); iter >= this_node->children.begin(); --iter) {
                temp.push((*iter));
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
    //Utility::printVector(output);
    return 0;
}