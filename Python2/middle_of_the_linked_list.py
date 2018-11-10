class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def middleNode(self, head):
        middle = head
        count = 0
        while head is not None:
            if count % 2 != 0:
                middle = middle.next
            head = head.next
            count += 1
        return middle


if __name__ == '__main__':
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)

    sol = Solution()
    middle = sol.middleNode(head)
    while middle is not None:
        print str(middle.val) + ' '
        middle = middle.next
