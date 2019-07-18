# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def isUnivalTree(self, root):
        # from leetcode
        # add them to the set and check if it has only 1 value
        # time O(n)
        # space O(n) because of the set
        # Runtime: 12 ms, faster than 96.32% of Python online submissions for Univalued Binary Tree.
        # Memory Usage: 11.7 MB, less than 90.63% of Python online submissions for Univalued Binary Tree.
        # actually it's not so bad
        # summary: no silly solution!!

        temp = []

        def dfs(root):
            if root:
                temp.append(root.val)
                dfs(root.left)
                dfs(root.right)
        dfs(root)
        return len(set(temp)) == 1

    def recursiveSol(self, root):
        # from leetcode
        # Time Complexity: O(N), where N is the number of nodes in the given tree.
        # Space Complexity: O(H), where H is the height of the given tree.
        # a node without children is also considered univalue
        left_correct = (not root.left or root.val == root.left.val and self.recursiveSol(root.left))
        right_correct = (not root.right or root.val == root.right.val and self.recursiveSol(root.right))
        return left_correct and right_correct



if __name__ == '__main__':
    t1 = TreeNode(1)
    t1.left = TreeNode(1)
    t1.right = TreeNode(1)
    t1.left.left = TreeNode(1)
    t1.left.right = TreeNode(1)
    t1.right.right = TreeNode(1)

    sol = Solution()
    print sol.isUnivalTree(t1)
