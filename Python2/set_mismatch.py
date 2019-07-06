class Solution(object):
    # time complexity: O(n)
    # I think this method is called "two-passes"
    def findErrorNums(self, nums):
        nums.sort()  # first pass
        expected = 1
        missing = None
        dup = None
        s = set([])
        # second pass
        for num in nums:
            if num in s:
                dup = num
            else:
                s.add(num)
            if num != expected and not expected in s:
                missing = expected
            expected = expected + 1
        return [dup, missing]

if __name__ == '__main__':
    sol = Solution()
    print sol.findErrorNums([1,5,3,2,2,7,6,4,8,9])
