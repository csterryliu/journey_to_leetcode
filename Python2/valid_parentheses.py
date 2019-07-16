class Solution(object):
    def isValid(self, s):
        stack = []
        # O(n)
        for p in s:
            if p == '(' or p == '[' or p == '{':
                stack.append(p)
            else:
                if len(stack) == 0:
                    return False
                top = stack.pop()
                if (p == ')' and top != '(') or (p == ']' and top != '[') or (p == '}' and top != '{'):
                    return False
        return True if len(stack) == 0 else False

if __name__ == '__main__':
    sol = Solution()
    print sol.isValid('()[]{}')
    print sol.isValid('[(({})}]')
    print sol.isValid('([]')
