# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        output = 0
        if root.left:
            if not root.left.left and not root.left.right:
                output = root.left.val
            else:
                output = self.sumOfLeftLeaves(root.left)
        if root.right:
            output = output + self.sumOfLeftLeaves(root.right)
        return output
        
        


if __name__ == '__main__':
    t1 = TreeNode(3)
    t1.left = TreeNode(9)
    t1.right = TreeNode(20)
    t1.right.left = TreeNode(15)
    t1.right.right = TreeNode(7)

    sol = Solution()
    print sol.sumOfLeftLeaves(t1)
