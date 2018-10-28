class Solution(object):
    def toLowerCase(self, str):
        """
        :type str: str
        :rtype: str
        """
        import StringIO
        output = StringIO.StringIO()
        Z = ord('Z')
        A = ord('A')
        for ch in str:
            ascii_code = ord(ch)
            if ascii_code <= Z and ascii_code >= A:
                ch = chr(ascii_code+32)
            output.write(ch)
        return output.getvalue()


if __name__ == '__main__':
    s = 'Hello'
    sol = Solution()
    print sol.toLowerCase(s)
