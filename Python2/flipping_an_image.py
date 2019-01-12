class Solution(object):
    def flipAndInvertImage(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """

        for row in A:
            front = 0
            end = len(A)-1
            while front < end:
                temp = row[front]
                row[front] = row[end]
                row[end] = temp
                row[front] ^= 1
                row[end] ^= 1
                front = front + 1
                end = end - 1

            if front == end:
                row[front] ^= 1

        # O(len(A) * len(row)/2)
        return A

    def flipAndInvertImage2(self, A):
        # O(len(A) * len(row))
        for row in A:
            # O(len(row))
            row.reverse()
            # O(len(row))
            for i in xrange(len(row)):  # use xrange is better than range when looping. xrange offers iterator.
                row[i] ^= 1

        return A


if __name__ == '__main__':
    A = [[1, 1, 0], [1, 0, 1], [0, 0, 0]]
    sol = Solution()
    print sol.flipAndInvertImage(A)
