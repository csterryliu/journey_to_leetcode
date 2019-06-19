# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def reverseListRecursive(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        return head

    def reverseListInterative(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # how does python do assignment?
        prev = None
        head_node = head
        while head_node:
            temp = head_node.next
            head_node.next = prev
            prev = head_node
            head_node = temp
        return prev


if __name__ == '__main__':
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)
    sol = Solution()
    output = sol.reverseListInterative(head)
    while output:
        print output.val
        output = output.next
        
