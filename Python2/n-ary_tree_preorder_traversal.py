class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children


class Solution(object):
    def preorder(self, root):
        output = []
        if not root:
            return output
        stack = [root]
        while stack:
            this_node = stack.pop()
            output.append(this_node.val)
            if not this_node.children:
                continue
            # [::-1] will give you the array in reverse order
            for c in this_node.children[::-1]:
                stack.append(c)
        return output


if __name__ == '__main__':
    tree = \
        Node(1,
             [Node(3, [Node(5, []), Node(6, [])]), Node(2, []), Node(4, [])])
    sol = Solution()
    print sol.preorder(tree)
