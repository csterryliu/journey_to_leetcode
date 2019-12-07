#include "merge_two_sorted_list.h"
#include <iostream>

using namespace std;

ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2) {
    // check first
    if (l1 == NULL && l2 == NULL) return NULL;
    if (l1 == NULL && l2 != NULL) return l2;
    if (l1 != NULL && l2 == NULL) return l1;
    ListNode* outputHead = new ListNode(0);
    ListNode* outputRear = outputHead;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val >= l2->val) {
            outputRear->next = new ListNode(l2->val);
            l2 = l2->next;
        } else {
            outputRear->next = new ListNode(l1->val);
            l1 = l1->next;
        }
        outputRear = outputRear->next;
    }
    if (l1 == NULL && l2 != NULL) {
        outputRear->next = l2;
    } else if (l1 != NULL && l2 == NULL) {
        outputRear->next = l1;
    }
    return outputHead->next;

    /* the following code is my wrong solution. keep in mind, don't make the same mistake!
    if (l1 == NULL && l2 == NULL) return NULL;
    if (l1 == NULL && l2 != NULL) return l2;
    if (l1 != NULL && l2 == NULL) return l1;
    ListNode* outputHead = new ListNode(0);
    ListNode* outputRear = outputHead;
    while (l1 != NULL && l2 != NULL) {
        cout << l1->val << endl;
        cout << l2->val << endl;
        int minVal = min(l1->val, l2->val);
        int maxVal = max(l1->val, l2->val);
        if (outputHead->next == NULL) {
            outputHead->val = minVal;
            outputRear->next = new ListNode(maxVal);
            outputRear = outputRear->next;
        } else {
            outputRear->next = new ListNode(minVal);
            outputRear->next->next = new ListNode(maxVal);
            outputRear = outputRear->next->next;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    if (l1 == NULL && l2 != NULL) {
        outputRear->next = l2;
    } else if (l1 != NULL && l2 == NULL) {
        outputRear->next = l1;
    }
    return outputHead;  */
}

int main() {
    ListNode l1(1);
    l1.next = new ListNode(2);
    l1.next->next = new ListNode(4);
    l1.next->next->next = new ListNode(7);
    l1.next->next->next->next = new ListNode(8);
    l1.next->next->next->next->next = new ListNode(10);
    l1.next->next->next->next->next->next = new ListNode(12);
    Utility::printSinglyLinkList(&l1);
    cout << endl;
    ListNode l2(1);
    l2.next = new ListNode(3);
    l2.next->next = new ListNode(4);
    l2.next->next->next = new ListNode(5);
    Utility::printSinglyLinkList(&l2);
    cout << endl;
    Solution* sol = new Solution();
    ListNode* output = sol->mergeTwoLists(&l1, &l2);
    Utility::printSinglyLinkList(output);
    cout << endl;
    ListNode* output2 = sol->mergeTwoLists(&l1, NULL);
    Utility::printSinglyLinkList(output2);
    cout << endl;
    return 0;
}