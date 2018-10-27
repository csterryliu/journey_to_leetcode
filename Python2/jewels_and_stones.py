class Solution(object):
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        count = 0
        s = set()
        # O(J)
        for jewel in J:
            s.add(jewel)
            
        # O(S*1) in best/average case. Possible O(S*n) in worst case.
        for stone in S:
            if stone in s:
                count += 1
        return count


if __name__ == '__main__':
    J = "aAKlUngG"
    S = "aAAbbbbkGnUKKaaA"
    sol = Solution()
    print sol.numJewelsInStones(J, S)
