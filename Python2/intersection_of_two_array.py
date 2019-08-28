# Definition for singly-linked list.
class Solution(object):
    # O(len(l1) + len(l2))
    def intersection(self, nums1, nums2):
        return set(nums1) & set(nums2)


if __name__ == '__main__':
    sol = Solution()
    output = sol.intersection([4,9,5], [9,4,9,8,4])
    print output
