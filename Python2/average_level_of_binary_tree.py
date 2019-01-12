class Node(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def averageOfLevels(self, root):
        # BFS
        # time: O(N). All nodes only are visited once
        output = []
        import Queue
        q = Queue.Queue()
        q.put(root)
        while not q.empty():
            avg = 0
            nodes_this_level = q.qsize()
            for _ in xrange(nodes_this_level):
                this_node = q.get(block=False)
                if this_node.left:
                    q.put(this_node.left)
                if this_node.right:
                    q.put(this_node.right)
                avg += this_node.val
            avg /= float(nodes_this_level)
            output.append(avg)

        return output


if __name__ == '__main__':
    tree = Node(3)
    tree.left = Node(9)
    tree.right = Node(20)
    tree.right.left = Node(15)
    tree.right.right = Node(7)
    sol = Solution()
    print sol.averageOfLevels(tree)
