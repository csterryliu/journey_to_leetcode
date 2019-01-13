class Solution(object):
    # O(logn)
    def search(self, nums, target):
        if not nums:
            return -1
        begin, end = 0, len(nums)-1
        mid = (begin + end) / 2
        if nums[mid] == target:
            return mid
        if nums[mid] > target:
            return self.search(nums[begin:mid], target)
        result = self.search(nums[mid+1:end+1], target)
        return mid+1 + result if result != -1 else result

    # O(logn)
    def searchIteration(self, nums, target):
        begin, end = 0, len(nums) - 1
        while begin <= end:
            mid = (begin + end) / 2
            if nums[mid] == target:
                return mid
            if nums[mid] > target:
                end = mid - 1
                continue
            if nums[mid] < target:
                begin = mid + 1
        return -1


if __name__ == '__main__':
    sol = Solution()
    print sol.searchIteration([-3, -2, -1, 0, 1, 3, 5, 9, 12], 7)
