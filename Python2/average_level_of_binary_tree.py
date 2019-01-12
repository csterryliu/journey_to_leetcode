class Node(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def averageOfLevels(self, root):
        # BFS
        # time: O(N). All nodes only are visited once
        # we don't have to use Queue all the time! List can do the similar thing sometimes
        output = []
        nodes_next_level = [root]
        while nodes_next_level:
            temp_sum, temp_counts = 0, 0
            nodes_this_level = nodes_next_level
            nodes_next_level = []
            for node in nodes_this_level:
                temp_sum += node.val
                temp_counts += 1
                if node.left:
                    nodes_next_level.append(node.left)
                if node.right:
                    nodes_next_level.append(node.right)
            output.append(temp_sum/float(temp_counts))

        return output


if __name__ == '__main__':
    tree = Node(3)
    tree.left = Node(9)
    tree.right = Node(20)
    tree.right.left = Node(15)
    tree.right.right = Node(7)
    sol = Solution()
    print sol.averageOfLevels(tree)
