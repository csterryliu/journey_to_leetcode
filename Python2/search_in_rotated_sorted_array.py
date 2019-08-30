class Solution(object):
    def search(self, nums, target):
        # this solution is from leetcode
        lo = 0
        hi = len(nums)
        while hi > lo:
            # we can use this way to find mid
            # mid = (lo + hi) / 2
            # but this can avoid overflow:
            mid = lo + (hi - lo) / 2
            # nums[0] is the rotating point!
            # Are target and nums[mid] on the same side?
            # If they are, treat it as normal binary search
            # If not, consider that position as a very big number or a very small number as if the list is sorted!
            if (target < nums[0]) == (nums[mid] < nums[0]):
                if target < nums[mid]:
                    hi = mid
                elif target > nums[mid]:
                    lo = mid + 1
                else:
                    return mid
            elif target < nums[mid]:
                lo = mid + 1
            else:
                hi = mid
        return -1

if __name__ == '__main__':
    sol = Solution()
    output = sol.search([4,5,6,7,0,1,2], 0)
    print output
