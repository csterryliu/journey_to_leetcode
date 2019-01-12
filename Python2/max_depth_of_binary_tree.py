class Node(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def maxDepth(self, root):
        # DFS
        # time complexity: O(n)
        # space complexity: O(n) for worst case (unbalanced tree)
        #                   O(logn) for best case (balanced tree)
        if not root:
            return 0
        return 1 + max([self.maxDepth(root.left), self.maxDepth(root.right)])


if __name__ == '__main__':
    tree = Node(3)
    tree.left = Node(9)
    tree.right = Node(20)
    tree.right.left = Node(15)
    tree.right.right = Node(7)
    sol = Solution()
    print sol.maxDepth(tree)
