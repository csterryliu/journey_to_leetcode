# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def searchBST(self, root, val):
        """
        :type root: TreeNode
        :type val: int
        :rtype: TreeNode
        """
        if root is None:
            return None

        if root.val == val:
            return root

        if val < root.val:
            root = self.searchBST(root.left, val)
        else:
            root = self.searchBST(root.right, val)

        return root

