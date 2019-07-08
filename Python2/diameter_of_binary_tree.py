# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # time: O(n)
        # space: O(n) because it is recursion

        longest_diameter = [0]

        def dfs(root):
            if not root:
                return 0
            # find the longest single-direction path of left subtree
            longest_path_left = 1 + dfs(root.left) if root.left else 0
            # find the longest single-direction path of right subtree
            lognest_path_right = 1 + dfs(root.right) if root.right else 0
            # the diameter must be across the root. so we remember the current longest value we've found in this subtree
            longest_diameter[0] = max(longest_diameter[0], longest_path_left + lognest_path_right)
            # return the longest single-direction path of this subtree
            return max(longest_path_left, lognest_path_right)
        dfs(root)
        return longest_diameter[0]



if __name__ == '__main__':
    t1 = TreeNode(1)
    t1.left = TreeNode(2)
    t1.right = TreeNode(3)
    t1.left.left = TreeNode(4);
    t1.left.right = TreeNode(5);

    sol = Solution()
    print sol.diameterOfBinaryTree(t1)
