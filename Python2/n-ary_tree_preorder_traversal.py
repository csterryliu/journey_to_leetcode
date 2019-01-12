class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children


class Solution(object):
    def preorder(self, root):
        if not root:
            return []
        stack, output = [root], []
        while stack:
            this_node = stack.pop()
            output.append(this_node.val)
            if this_node.children:
                stack.extend(this_node.children[::-1])
        # O(N). Because we append the child nodes for each visit
        return output


if __name__ == '__main__':
    tree = \
        Node(1,
             [Node(3, [Node(5, []), Node(6, [])]), Node(2, []), Node(4, [])])
    sol = Solution()
    print sol.preorder(tree)
