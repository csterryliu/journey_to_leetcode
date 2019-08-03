class Solution(object):
    def rob(self, nums):
        # the robber has 2 options to rob along the street:
        # 1. Rob this house (index: i). So he can't rob house i-1. But he can rob house i-2.
        # 2. Do not rob this house. So he can rob house i-1
        # If he choose option 1, the money he can have is the money of current house + the money he has stolen from house i-2.
        # if he choose option 2, the money he can have is the money he has stolen from house i-1.
        # So we can have the recursive formula:
        # rob(i) = Math.max( rob(i - 2) + currentHouseValue, rob(i - 1) )
        def recursive(nums, houseIdx):
            if houseIdx < 0:
                return 0
            return max(recursive(nums, houseIdx - 2) + nums[houseIdx], recursive(nums, houseIdx - 1))

        return recursive(nums, len(nums) - 1)


if __name__ == '__main__':
    sol = Solution()
    # print sol.rob([1,2,3,1])
    print sol.rob([2, 7, 9, 3, 1])
