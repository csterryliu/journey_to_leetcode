# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        if not head:
            return head
        prev = head
        current = head.next
        # O(n)
        while current:
            if current.val == prev.val:
                prev.next = current.next
                current = current.next
                continue
            prev = current
            current = current.next
        return head

    def deleteDuplicatesNoTwoPointer(self, head):
        if not head:
            return head
        # because the list is sorted, we can compare the current node to the next node
        current = head
        while current and current.next:
            if current.val == current.next.val:
                current.next = current.next.next
            else:
                current = current.next
        # time: O(n), space: O(1)
        return head


if __name__ == '__main__':
    head = ListNode(1)
    head.next = ListNode(1)
    head.next.next = ListNode(2)
    head.next.next.next = ListNode(3)
    head.next.next.next.next = ListNode(3)
    sol = Solution()
    output = sol.deleteDuplicates(head)
    while output:
        print output.val
        output = output.next
        
