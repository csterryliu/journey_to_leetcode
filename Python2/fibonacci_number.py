class Solution(object):
    def __init__(self):
        self.table = [-1] * 1000

    # O(2^n)
    def fib(self, N):
        if N == 0:
            return 0
        if N == 1:
            return 1
        return self.fib(N-1) + self.fib(N-2)

    # O(N)
    def fibMemoization(self, N):
        if N == 0:
            return 0
        if N == 1:
            return 1
        if self.table[N] < 0:
            result = self.fibMemoization(N-1) + self.fibMemoization(N-2)
            self.table[N] = result
        else:
            result = self.table[N]
        return result

    # O(N)
    def fibTabulation(self, N):
        for num in xrange(N+1):
            if num == 0:
                self.table[num] = 0
            elif num == 1:
                self.table[num] = 1
            else:
                self.table[num] = self.table[num-1] + self.table[num-2]
        return self.table[N]


if __name__ == '__main__':
    sol = Solution()
    print sol.fibMemoization(4)
