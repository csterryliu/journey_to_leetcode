class Solution(object):
    def twoSum(self, nums, target):
        # O(n^2)
        for i in xrange(len(nums)):
            for j in xrange(i+1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]
        return []

    def twoSumTwoPassHash(self, nums, target):
        dic = {}
        # O(n)
        for idx in xrange(len(nums)):
            dic[nums[idx]] = idx
        # O(n)
        for idx in xrange(len(nums)):
            complement = target - nums[idx]
            if complement in dic and dic[complement] != idx:
                return [idx, dic[complement]]
        # O(2n) => O(n)
        return []

    def twoSumOnePassHash(self, nums, target):
        dic = {}
        for idx in xrange(len(nums)):
            complement = target - nums[idx]
            if complement in dic and dic[complement] != idx:
                # Because we "look back" the hash table,
                # the value in the table must be smaller than current index
                return [dic[complement], idx]
            else:
                dic[nums[idx]] = idx
        # O(n)
        return []


if __name__ == '__main__':
    sol = Solution()
    print sol.twoSumTwoPassHash([2, 5, 5, 11], 10)
