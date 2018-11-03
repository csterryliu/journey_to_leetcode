class Solution(object):
    def hammingDistance(self, x, y):
        def countSetBits(n):
            count = 0
            while n > 0:
                count += (n & 1)
                n = n >> 1
            return count

        xor_output = x ^ y
        return countSetBits(xor_output)


if __name__ == '__main__':
    sol = Solution()
    print sol.hammingDistance(1, 4)
