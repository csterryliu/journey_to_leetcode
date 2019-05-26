class Solution(object):
    def isMonotonic(self, A):
        if len(A) <= 1:
            return True
        direction = None
        # O(len(A))
        for idx in xrange(len(A)-1):
            if direction is None and A[idx+1] != A[idx]:
                direction = ((A[idx+1]-A[idx]) > 0)
                continue
            if A[idx+1] == A[idx]:
                continue
            if (A[idx+1]-A[idx] > 0) != direction:
                return False
        return True


if __name__ == '__main__':
    sol = Solution()
    print sol.isMonotonic([6, 5, 4, 4])
