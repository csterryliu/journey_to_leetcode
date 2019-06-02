class Solution(object):
    def arrangeCoins(self, n):
        import math
        # Use equal difference series and quadratic formula to get the answer
        # We ignore the negative root. Because it's not the one we want here
        # int is simply to floor the floating point so we get the largest integer smaller than the expression
        return int((math.sqrt(8*n+1)-1) / 2)


if __name__ == '__main__':
    sol = Solution()
    print sol.arrangeCoins(8)
