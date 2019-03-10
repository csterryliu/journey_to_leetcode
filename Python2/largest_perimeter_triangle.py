# The condition to form a triangle:
# The sum of any 2 lengthes must be greater or equal to the third length.
# So if a <= b <= c, then a + b >= c.

# By sorting the array first, we can know the largest c. We have to find
# the largest sum of a+b.
# And because we have already sorted the array, we just need to check the
# adjacent 2 values before the "c" we are looking at.
# Then,
# the sum of a+b+c will be the largest perimeter of the triangle if a+b>=c.


class Solution(object):
    def largestPerimeter(self, A):
        A.sort()  # O(nlogn)
        # O(n) or (O(n-2))
        for i in xrange(len(A) - 3, -1, -1):
            if A[i] + A[i+1] > A[i+2]:
                return A[i] + A[i+1] + A[i+2]
        # total: O(n + nlogn) => O(n(1+logn)) => O(nlogn)
        return 0


if __name__ == '__main__':
    sol = Solution()
    print sol.largestPerimeter([2, 1, 2])
