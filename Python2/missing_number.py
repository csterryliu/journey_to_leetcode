class Solution(object):
    def missingNumber(self, nums):
        s = set(nums)
        # because the array must miss one number
        expectedNumCount = len(nums) + 1
        # use the set to find the missing number
        for number in xrange(expectedNumCount):
            if number not in s:
                return number
        # time complexity overall: O(n) of set creation + O(n) of loop => O(n)
        # space complexity: O(n)
        # nums contains n−1 distinct elements, so it costs O(n) space to store a set containing all of them.
        # it's a brute force method
        return None


if __name__ == '__main__':
    sol = Solution()
    print sol.missingNumber([3, 0, 1])
