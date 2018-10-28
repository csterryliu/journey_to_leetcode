class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        def swap(array, idx1, idx2):
            temp = array[idx1]
            array[idx1] = array[idx2]
            array[idx2] = temp

        for k in range(len(nums)-1):
            is_swap = False
            for i in range(0, len(nums)-1-k):
                if nums[i] == 0:
                    swap(nums, i, i+1)
                    is_swap = True
            if not is_swap:
                break

        return


if __name__ == '__main__':
    nums = [0, 1, 0, 3, 12]
    sol = Solution()
    sol.moveZeroes(nums)
    print nums
