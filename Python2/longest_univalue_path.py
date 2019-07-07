# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# solution from leetcode:

# 1. Longest-Univalue-Path of a tree is among those Longest-Univalue-Path-Across at each node;
# 2. Longest-Univalue-Path-Across a node is sum of { Longest-Univalue-Path-Start-At each child with same value } + 1
# 3. Let an dfs to return Longest-Univalue-Path-Start-At each node, the Longest-Univalue-Path-Across node can be calculated by combine the Longest-Univalue-Path-Start-At of its 2 child; and we can use an global variable res to hold the max value and compare with each intermediate result.


class Solution(object):
    
    def longestUnivaluePath(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        longest_univalue_path_across = [0]

        def dfs(root):
            if not root:
                return 0
            # Find the longest univalue path of each child
            longest_output_single_dir_left = dfs(root.left)
            longest_output_single_dir_right = dfs(root.right)
            # Check if the root has the same value of each child. If it does, let the number of path plus 1; Otherwise, we get 0.
            longest_output_single_dir_left_from_root = longest_output_single_dir_left + 1 if root.left and root.left.val == root.val else 0
            longest_output_single_dir_right_from_root = longest_output_single_dir_right + 1 if root.right and root.right.val == root.val else 0
            # remember the maximum value of longest univalue path across we have found
            longest_univalue_path_across[0] = max(longest_univalue_path_across[0], longest_output_single_dir_left_from_root + longest_output_single_dir_right_from_root)
            # this is for returning the longest path of a single direction
            return max(longest_output_single_dir_left_from_root, longest_output_single_dir_right_from_root)

        dfs(root)
        return longest_univalue_path_across[0]

        
    def myFirstWrongAns(self, root):
        if not root:
            return 0
        left_output = 0
        right_output = 0
        if root.left:
            if root.left.val == root.val:
                left_output = left_output + 1
            left_output = left_output + self.longestUnivaluePath(root.left)
        if root.right:
            if root.right.val == root.val:
                right_output = right_output + 1
            right_output = right_output + self.longestUnivaluePath(root.right)
        if (root.left and root.val == root.left.val) and (root.right and root.val == root.right.val):
            return left_output + right_output
        return max(left_output, right_output);


if __name__ == '__main__':
    t1 = TreeNode(5)
    t1.left = TreeNode(4)
    t1.right = TreeNode(5)
    t1.left.left = TreeNode(1);
    t1.left.right = TreeNode(1);
    t1.right.right = TreeNode(5)

    sol = Solution()
    print sol.longestUnivaluePath(t1)
