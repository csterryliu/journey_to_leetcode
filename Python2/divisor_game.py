class Solution(object):
    # from GeeksForGeeks
    # O(sqrt(N))
    def divisors(self, N):
        import math
        output = []
        i = 1
        while i <= math.sqrt(N):
            if N % i == 0:
                if N / i == i:
                    output.append(i)
                else:
                    output.append(i)
                    if i > 1:
                        output.append(N / i)
            i = i + 1
        return output

    def divisorGameRecursive(self, N):
        if N == 1:
            return False
        # find all possible x
        all_x = self.divisors(N)
        will_bob_win = False
        for x in all_x:
            will_bob_win = self.divisorGameRecursive(N - x)
            if not will_bob_win:
                break
        return not will_bob_win

    def divisorGameMemoization(self, N):
        dp = [0] * (N + 1)

        def memo(N):
            if dp[N] != 0:
                return dp[N]
            if N == 1:
                dp[N] = False
                return False
            # find all possible x
            all_x = self.divisors(N)
            will_bob_win = False
            for x in all_x:
                will_bob_win = memo(N - x)
                if not will_bob_win:
                    break
            dp[N] = not will_bob_win
            return dp[N]
        return memo(N)

    # this solution is from leetcode
    def divisorGameTabulation(self, N):
        dp = [False] * (N + 1)

        def tab(N):
            # build the table from the very begining
            for i in xrange(N+1):
                # we can get the divisors of a number except itself by doing this
                for j in xrange(1, (i/2) + 1):
                    # check if bob will lose after alice get its number
                    if i % j == 0 and not dp[i - j]:
                        dp[i] = True
                        break
            return dp[N]
        return tab(N)



if __name__ == '__main__':
    sol = Solution()
    # print sol.rob([1,2,3,1])
    # print sol.divisorGameRecursive(81)
    # print sol.divisorGameMemoization(81)
    print sol.divisors(100)
