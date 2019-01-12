class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children


class Solution(object):
    def levelOrder(self, root):
        if not root:
            return []
        output = []
        import Queue
        q = Queue.Queue()
        q.put(root)
        while not q.empty():
            row = []
            size_of_this_level = q.qsize()
            for _ in xrange(size_of_this_level):
                this_node = q.get(block=False)
                if this_node.children:
                    for child in this_node.children:
                        q.put(child)
                row.append(this_node.val)
            output.append(row)

        return output


if __name__ == '__main__':
    tree = \
        Node(1,
             [Node(3, [Node(5, []), Node(6, [])]), Node(2, []), Node(4, [])])
    sol = Solution()
    print sol.levelOrder(tree)
