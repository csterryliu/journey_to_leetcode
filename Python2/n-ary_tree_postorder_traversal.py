class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children


class Solution(object):
    def postorder(self, root):
        if not root:
            return []
        output = []
        stack = [root]
        while stack:
            this_node = stack.pop()
            output.append(this_node.val)
            if this_node.children:
                stack.extend(this_node.children)
        return output[::-1]


if __name__ == '__main__':
    tree = \
        Node(1,
             [Node(3, [Node(5, []), Node(6, [])]), Node(2, []), Node(4, [])])
    sol = Solution()
    print sol.preorder(tree)
