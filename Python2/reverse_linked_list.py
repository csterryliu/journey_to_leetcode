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
        # reference: https://www.educative.io/collection/page/5642554087309312/5679846214598656/70003?affiliate_id=5082902844932096&utm_source=google&utm_medium=cpc&utm_campaign=platform2&utm_content=ad-1-dynamic&gclid=CjwKCAjw3azoBRAXEiwA-_64OuVKbgpOkzZ4vHFHwGWH7rA1GBrIwu2NSvdwE9yNwjJn2dbvBEzDfxoC1wcQAvD_BwE
        if not head or head.next is None:
            return head
        reversed_node_list = self.reverseListRecursive(head.next)
        head.next.next = head
        head.next = None
        return reversed_node_list

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
    output = sol.reverseListRecursive(head)
    while output:
        print output.val
        output = output.next
        
