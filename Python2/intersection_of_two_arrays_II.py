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

    # according to the running result, it's slower than previous solution
    def intersectionII(self, nums1, nums2):
        from collections import Counter
        # c1: Counter({1: 2, 2: 2})
        c1 = Counter(nums1)
        # c2: Counter({2: 2})
        c2 = Counter(nums2)
        # c1 & c2: Counter({2: 2})
        return list((c1 & c2).elements())  # [2, 2]


if __name__ == '__main__':
    sol = Solution()
    output = sol.intersectionII([1, 2, 2, 1], [2, 2])
    print output
