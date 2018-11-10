#include <iostream>
#include <queue>
#include "./utility.h"


using namespace std;

void Utility::printVector(vector<int>& v) {
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << " ";
    }
    cout << "\n";
}

void Utility::swapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void Utility::traverseTreeByLevelOrder(TreeNode* tree) {
    queue<TreeNode*> q;
    q.push(tree);
    while (q.size() > 0) {
        if (tree != NULL) {
            cout << tree->val << " ";
            q.push(tree->left);
            q.push(tree->right);
        } else {
            cout << "NULL ";
        }
        q.pop();
        tree = q.front();
    }
    cout << "\n";
}

void Utility::printSinglyLinkList(ListNode* head) {
    if (head == NULL) return;
    cout << head->val << " ";
    printSinglyLinkList(head->next);
}
