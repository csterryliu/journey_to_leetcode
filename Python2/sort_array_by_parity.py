class Solution(object):
    def sortArrayByParity(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """

        if len(A) > 5000:
            return None

        even = []
        odd = []
        # O(len(A))
        for element in A:
            if element % 2 == 0:
                even.append(element)
            else:
                odd.append(element)
        # + operation: O(len(odd))
        # total: O(len(A) + len(odd))
        return even + odd


if __name__ == '__main__':
    A = [3, 1, 2, 4]
    sol = Solution()
    print sol.sortArrayByParity(A)
