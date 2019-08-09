# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    # O(len(l1) + len(l2))
    def mergeTwoLists(self, l1, l2):
        if not l1 and l2:
            return l2
        if l1 and not l2:
            return l1
        if not l1 and not l2:
            return None
        output = ListNode(0)
        output_ptr = output

        while l1 and l2:
            if l1.val >= l2.val:
                output_ptr.next = ListNode(l2.val)
                l2 = l2.next
            else:
                output_ptr.next = ListNode(l1.val)
                l1 = l1.next
            output_ptr = output_ptr.next

        if l1:
            output_ptr.next = l1
        if l2:
            output_ptr.next = l2

        return output.next


if __name__ == '__main__':
    l1 = ListNode(1)
    l1.next = ListNode(2)
    l1.next.next = ListNode(4)
    l2 = ListNode(1)
    l2.next = ListNode(3)
    l2.next.next = ListNode(4)
    l2.next.next.next = ListNode(5)

    sol = Solution()
    output = sol.mergeTwoLists(l1, l2)
    while output:
        print output.val
        output = output.next
