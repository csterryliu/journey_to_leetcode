# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def mergeTrees(self, t1, t2):
        """
        :type t1: TreeNode
        :type t2: TreeNode
        :rtype: TreeNode
        """
        
        if t1 is None and t2 is not None:
            return t2
        if t1 is not None and t2 is None:
            return t1

        # use level-order traversal
        import Queue
        q = Queue.Queue()
        q.put([t1, t2])
        while q.qsize() != 0:
            this_nodes = q.get()
            if this_nodes[0] is None and this_nodes[1] is None:
                continue
            if this_nodes[0] is not None:
                this_nodes[0].val += (this_nodes[1].val if this_nodes[1] is not None else 0)

            # left child
            next_left_child_2 = this_nodes[1].left if this_nodes[1] is not None else None
            if next_left_child_2 is not None and this_nodes[0].left is None:
                next_left_child_1 = TreeNode(0)
                this_nodes[0].left = next_left_child_1
            else:
                next_left_child_1 = this_nodes[0].left if this_nodes[0] is not None else None

            # right child
            next_right_child_2 = this_nodes[1].right if this_nodes[1] is not None else None
            if next_right_child_2 is not None and this_nodes[0].right is None:
                next_right_child_1 = TreeNode(0)
                this_nodes[0].right = next_right_child_1
            else:
                next_right_child_1 = this_nodes[0].right if this_nodes[0] is not None else None

            q.put([next_left_child_1, next_left_child_2])
            q.put([next_right_child_1, next_right_child_2])

        return t1


if __name__ == '__main__':
    t1 = TreeNode(1)
    t1.left = TreeNode(3)
    t1.right = TreeNode(2)
    t1.left.left = TreeNode(5)
    t2 = TreeNode(2)
    t2.left = TreeNode(1)
    t2.right = TreeNode(3)
    t2.left.right = TreeNode(4)
    t2.right.right = TreeNode(7)

    sol = Solution()
    print sol.mergeTrees(t1, t2)
