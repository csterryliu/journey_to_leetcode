#include <iostream>
#include "middle_of_the_linked_list.h"


using namespace std;


ListNode* Solution::middleNode(ListNode* head) {
    ListNode* middle = head;
    int counter = 0;
    while (head != NULL) {
        if (counter % 2 != 0) {
            middle = middle->next;
        }
        head = head->next;
        counter++;
    }
    return middle;
}


int main() {
    ListNode head(1);
    head.next = new ListNode(2);
    head.next->next = new ListNode(3);
    head.next->next->next = new ListNode(4);
    head.next->next->next->next = new ListNode(5);
    Utility::printSinglyLinkList(&head);
    cout << "\n";
    Solution* sol = new Solution();
    ListNode* output = sol->middleNode(&head);
    Utility::printSinglyLinkList(output);
    delete sol;
}