class Solution(object):
    def arrayPairSum(self, nums):
        out = 0
        # O(nlogn)
        nums.sort()

        for i in range(0, len(nums), 2):
            out += min(nums[i], nums[i+1])

        return out


if __name__ == '__main__':
    input_val = [1, 1]
    sol = Solution()
    print sol.arrayPairSum(input_val)
