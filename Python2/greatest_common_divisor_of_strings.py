class Solution(object):
    # result:
    # Time: faster than 18.74%/60%/32% of Python online submissions for Greatest Common Divisor of Strings.
    # Memory Usage: 11.8 MB, less than 100.00% of Python online submissions for Greatest Common Divisor of Strings.
    def gcdOfStrings(self, str1, str2):
        """
        :type str1: str
        :type str2: str
        :rtype: str
        """
        def check(dividend, test, right_boundary):
            start_idx = 0
            end_idx = right_boundary
            while start_idx < len(dividend):
                if dividend[start_idx:end_idx] != test:
                    return False
                    break
                start_idx = start_idx + len(test)
                end_idx = end_idx + len(test)
            return True

        # use the smallest one as the divisor
        if len(str1) > len(str2):
            divisor = str2
            dividend = str1
        else:
            divisor = str1
            dividend = str2
        
        for right_boundary in xrange(len(divisor), 0, -1):
            test = divisor[0:right_boundary]
            start_idx = 0
            end_idx = right_boundary
            if check(dividend, test, right_boundary) and check(divisor, test, right_boundary):
                return test
        # the time complexity may be very bad.
        # it may be similar to o(n^2), because there are so may loop inside a loop
        return ''


if __name__ == '__main__':
    sol = Solution()
    print sol.gcdOfStrings('ABCABC', 'ABC')
