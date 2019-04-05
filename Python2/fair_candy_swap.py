class Solution(object):
    def fairCandySwap(self, A, B):
        sum_a = sum(A)
        sum_b = sum(B)
        # O(AB), very bad
        for c1 in A:
            for c2 in B:
                if (sum_a - c1 + c2) == (sum_b - c2 + c1):
                    return [c1, c2]
        return None

    def fairCandySwapEnhanced(self, A, B):
        # I figured out this method with luck. It's not professional
        size_set = set(B)
        sum_a = sum(A)
        sum_b = sum(B)
        step = abs(sum_a - sum_b) / 2
        target = sum_a + step if sum_a < sum_b else sum_b + step
        for candy in A:
            need = target - (sum_a - candy)
            if need in size_set:
                return [candy, need]
        return None

    def fairCandySwapLeetCodeEquation(self, A, B):
        # This method is from leetcode
        # Let SA = sum of A and SB = sum of B.
        # If x stands for the candy which A needs to remove and y stands for the candy which A retreives from B
        # According to the question, we'll get this equation: SA - x + y = SB - y + x.
        # Finally we'll know the y which A needs is: y = (SB-SA) / 2 + x
        # So we just need to know whether B has that kind of y or not
        sum_a, sum_b = sum(A), sum(B)
        set_b = set(B)  # O(B.length)
        for x in A:  # O(A.length)
            target = (sum_b - sum_a)/2 + x
            if target in set_b:
                return [x, target]
        # time complexity: O(A.length + B.length)
        # space complexity: O(B.length) for the set of B
        return None


if __name__ == '__main__':
    sol = Solution()
    ans = sol.fairCandySwapLeetCodeEquation([35,17,4,24,10], [63, 21])
    print ans
