class Solution(object):
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        import StringIO
        output = StringIO.StringIO()
        tail = -1

        while tail + len(s) >= 0:
            output.write(s[tail])
            tail -= 1

        return output.getvalue()


if __name__ == '__main__':
    s = 'hello'
    sol = Solution()
    print sol.reverseString(s)
