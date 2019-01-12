class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children


class Solution(object):
    def maxDepthBFS(self, root):
        if not root:
            return 0
        import Queue
        q = Queue.Queue()
        q.put(root)
        max_depth = 0
        nodes_this_level = 1
        nodes_next_level = 0
        while not q.empty():
            this_node = q.get(block=False)
            nodes_this_level -= 1
            if this_node.children:
                nodes_next_level += len(this_node.children)
                for child in this_node.children:
                    q.put(child)
            if nodes_this_level == 0:
                nodes_this_level = nodes_next_level
                nodes_next_level = 0
                max_depth += 1

        return max_depth

    def maxDepthDFS(self, root):
        # DFS
        # time complexity: O(n)
        # space complexity: O(n) for worst case (unbalanced tree)
        #                   O(logn) for best case (balanced tree)
        if not root:
            return 0
        return (1 + max([self.maxDepthDFS(child_node) for child_node in root.children])) if root.children else 1


if __name__ == '__main__':
    tree = \
        Node(1,
             [Node(3, [Node(5, []), Node(6, [])]), Node(2, []), Node(4, [])])
    sol = Solution()
    print sol.maxDepthDFS(tree)
