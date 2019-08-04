# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def mergeTwoLists(self, l1, l2):
        if not l1 and not l2:
            return None
        if not l1 and l2:
            return l2
        if l1 and not l2:
            return l1
        output = None
        if l1.val >= l2.val:
            output = ListNode(l1.val)
            l1 = l1.next
        else:
            output = ListNode(l2.val)
            l2 = l2.next
        head = output
        while l1 and l2:
            if l1.val >= l2.val:
                head.next = ListNode(l1.val)
                l1 = l1.next
            else:
                head.next = ListNode(l2.val)
                l2 = l2.next
            head = head.next
        if l1:
            head.next = l1
        if l2:
            head.next = l2
        return output


if __name__ == '__main__':
    l1 = ListNode(1)
    l1.next = ListNode(2)
    l1.next.next = ListNode(4)
    l2 = ListNode(1)
    l2.next = ListNode(3)
    l2.next.next = ListNode(4)

    sol = Solution()
    output = sol.mergeTwoLists(l1, l2)
    while output:
        print output.val

