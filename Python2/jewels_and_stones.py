class Solution(object):
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        count = 0
        # O(J)
        s = set(J)

        # Because we use set (hash table) here, the finding procedure won't be too long
        # It's O(S*1) in best/average case. O(S*n) in worst case. (collision)
        for stone in S:
            if stone in s:
                count += 1
        return count

    def numJewelsInStones2(self, J, S):
        count = 0
        # O(S*J)
        for stone in S:
            if stone in J:
                count += 1
        return count


if __name__ == '__main__':
    J = "z"
    S = "ZZ"
    sol = Solution()
    print sol.numJewelsInStones2(J, S)
