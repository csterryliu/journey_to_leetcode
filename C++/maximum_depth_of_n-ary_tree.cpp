#include "./maximum_depth_of_n-ary_tree.h"
#include <queue>
#include <iostream>

using namespace std;

int Solution::maxDepth(Node* root) {
    if (root == NULL) return 0;
    queue<Node*> q;
    q.push(root);
    int max_depth = 0;
    int nodes_this_level = 1;
    int nodes_next_level = 0;
    // BFS traversal
    while (!q.empty()) {
        Node* this_node = q.front();
        q.pop();
        nodes_this_level--;
        if (!this_node->children.empty()) {
            nodes_next_level += this_node->children.size();
            for (int i = 0; i < this_node->children.size(); ++i) {
                q.push(this_node->children[i]);
            }
        }
        if (nodes_this_level == 0) {
            nodes_this_level = nodes_next_level;
            nodes_next_level = 0;
            max_depth++;
        }
    }
    
    return max_depth;
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
    int output = sol->maxDepth(&tree);
    cout << output << "\n";
    return 0;
}