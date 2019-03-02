class Solution(object):
    def hasAlternatingBits(self, n):
        expected_bit = 0 if (n & 1) == 1 else 1
        while n:
            n >>= 1
            this_bit = n & 1
            if (n & 1) != expected_bit:
                return False
            expected_bit = 0 if this_bit == 1 else 1
        return True


if __name__ == '__main__':
    sol = Solution()
    print sol.hasAlternatingBits(10)
