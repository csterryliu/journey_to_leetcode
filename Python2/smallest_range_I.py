class Solution(object):
    def smallestRangeI(self, A, K):
        """
        from leetcode solution:
        
        Let A be the original array, and B be the array after all our modifications. Towards trying to minimize max(B) - min(B), let's try to minimize max(B) and maximize min(B) separately.

        The smallest possible value of max(B) is max(A) - K, as the value max(A) cannot go lower. Similarly, the largest possible value of min(B) is min(A) + K. So the quantity max(B) - min(B) is at least ans = (max(A) - K) - (min(A) + K).
        
        If ans < 0, the best answer we could have is ans = 0, also using the same modification.
        """

        # in general: in order to get the smallest difference, we have to let the maximum value as "smaller" as possible
        # and the minimum value as "larger" as possible
        
        return max(0, max(A) - min(A) - 2*K)


if __name__ == '__main__':
    sol = Solution()
    print sol.smallestRangeI([1], 0)
