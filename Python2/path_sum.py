# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def __init__(self):
        self.s = set([])

    def bestSolution(self, root, sumN):
        if not root:
            return False
        # we found it!
        if not root.left and not root.right and sumN - root.val == 0:
            return True
        # keep searching
        return self.bestSolution(root.left, sumN - root.val) or self.bestSolution(root.right, sumN - root.val)

    def hasPathSum(self, root, sumN):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        stack = []
        s = set([])

        def dfs(root):
            # empty tree
            if not root:
                return
            stack.append(root.val)
            dfs(root.left)
            dfs(root.right)
            #  leaf node
            if not root.left and not root.right:
                s.add(sum(stack))
            stack.pop()

        dfs(root)
        if sumN in s:
            return True
        return False



if __name__ == '__main__':
    t1 = TreeNode(5)
    t1.left = TreeNode(4)
    t1.right = TreeNode(8)
    t1.left.left = TreeNode(11);
    t1.left.left.left = TreeNode(7)
    t1.left.left.right = TreeNode(2)
    t1.right.left = TreeNode(13)
    t1.right.right = TreeNode(4)
    t1.right.right.right = TreeNode(1)

    sol = Solution()
    print sol.hasPathSum(t1, 21)
