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

    def useXOR(self, nums):
        # concept: a ^ b ^ b = a
        # xor all (element^index) of the array should be 0 in the end
        # and because we miss a number, so we can use that concept to find the missing number
        # (because if that missing number exists, we should get 0 in the end!!! but we lack a number!)
        missing = len(nums)  # start from n
        for i, num in enumerate(nums):
            missing ^= (i^num)
        # O(n)
        return missing

    def useGaussian(self, nums):
        # just calcualate the sum which it should have been, then use it to minus the actual sum
        # after that, we'll get the missing number...!
        expected_sum = (len(nums)*(1+len(nums))) / 2  # O(1)
        actual_sum = sum(nums)  # O(n)
        return expected_sum - actual_sum  # O(1)


if __name__ == '__main__':
    sol = Solution()
    print sol.missingNumber([3, 0, 1])
