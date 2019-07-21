class Solution(object):
    def twoCitySchedCost(self, costs):
        # use difference...this solution is from leetcode
        costs.sort(key=lambda x: x[1] - x[0], reverse=True)
        # now, the first half of the array has the largest different of B-A, which means they should fly to A (Going to A is cheaper than going to B).
        # then, the rest of the array should all go to B no matter the cost of it.
        # the final result will be the min cost
        ans = 0
        for i in xrange(len(costs)/2):
            ans = ans + costs[i][0] + costs[i + len(costs)/2][1]
        # O(nlogn)
        return ans

if __name__ == '__main__':
    sol = Solution()
    print sol.twoCitySchedCost([[10, 20], [30, 200], [400, 50], [30, 20]])
