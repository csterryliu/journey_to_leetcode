# Definition for singly-linked list.
class Solution(object):
    # O(len(l1) + len(l2))
    def intersection(self, nums1, nums2):
        output = []
        counter_map = {}
        # O(num1)
        for n in nums1:
            if n not in counter_map:
                counter_map[n] = 1
            else:
                counter_map[n] += 1
        # O(num2)
        for n in nums2:
            if n in counter_map and counter_map[n] > 0:
                output.append(n)
                counter_map[n] -= 1
        return output


if __name__ == '__main__':
    sol = Solution()
    output = sol.intersection([1, 2, 2, 1], [2, 2])
    print output
