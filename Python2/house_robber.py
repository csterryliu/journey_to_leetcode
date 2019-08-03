class Solution(object):
    def rob(self, nums):
        dp_table = [-1] * len(nums)
        dp_table2 = [-1] * (len(nums) + 1)

        # the robber has 2 options to rob along the street:
        # 1. Rob this house (index: i). So he can't rob house i-1. But he can rob house i-2.
        # 2. Do not rob this house. So he can rob house i-1
        # If he choose option 1, the money he can have is the money of current house + the money he has stolen from house i-2 and any buiildings before that.
        # if he choose option 2, the money he can have is the money he has stolen from house i-1 any buiildings before that.
        # So, find the more profitable option.
        # And then we can have the recursive formula:
        # rob(i) = Math.max( rob(i - 2) + currentHouseValue, rob(i - 1) )
        
        # O(2^n)
        def recursive(nums, houseIdx):
            if houseIdx < 0:
                return 0
            return max(recursive(nums, houseIdx - 2) + nums[houseIdx], recursive(nums, houseIdx - 1))

        # top-down O(n)
        def memoization(nums, houseIdx):
            if houseIdx < 0:
                return 0
            if dp_table[houseIdx] >= 0:
                return dp_table[houseIdx]
            dp_table[houseIdx] = max(memoization(nums, houseIdx - 2) + nums[houseIdx], memoization(nums, houseIdx - 1))
            return dp_table[houseIdx]

        # bottom-up O(n)
        def tabulation(nums):
            if not nums:
                return 0
            dp_table2[0] = 0  # in order to calculate the money we get so far of house 1, we need to put 0 at index 0 of the table
            dp_table2[1] = nums[0]  # it's the money we can have for first house (house 0)
            # as for the other house, we look at the table so far.
            # the money we can get so far for house i is the max value of (table[i-1] + current value)[rob this house] and (table[i])[do not rob this house]
            # the reason why the index we use is different from the recursion is that we simulate the table as the houses along the street, but we but 0 at first position. 
            # by doing so, we can calculate the max money we can have of house[i] at table[i+1]
            # in other words, use the index of input houses to get the value of the table
            for i in xrange(1, len(nums)):
                val = nums[i]
                dp_table2[i + 1] = max(dp_table2[i - 1] + val, dp_table2[i])
            return dp_table2[len(nums)]

        # return recursive(nums, len(nums) - 1)
        # return memoization(nums, len(nums) - 1)
        return tabulation(nums)


if __name__ == '__main__':
    sol = Solution()
    # print sol.rob([1,2,3,1])
    print sol.rob([2, 7, 9, 3, 1])
