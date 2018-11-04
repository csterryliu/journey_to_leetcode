class Solution(object):
    def peakIndexInMountainArray(self, nums):
        low = 0
        hi = len(nums) - 1
        while low < hi:
            middle = (low+hi)/2
            if nums[middle] > nums[middle+1] and nums[middle] > nums[middle-1]:
                return middle
            elif nums[middle] < nums[middle+1]:
                low = middle + 1
            elif nums[middle] < nums[middle-1]:
                hi = middle
        return -1


if __name__ == '__main__':
    nums = [1, 5, 4, 3, 2, 1]
    sol = Solution()
    print sol.peakIndexInMountainArray(nums)
