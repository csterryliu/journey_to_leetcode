class Solution(object):
    # it's too slow! every characters need to perform n times of loop!
    # so the time complexity may be close to O(n*(n-1))! Which is O(n^2)!!
    def shortestToChar(self, S, C):
        output = []
        distance_pre = 0
        distance_post = 0
        for i in xrange(len(S)):
            if S[i] == C:
                output.append(0)
                continue
            # search backword
            temp = i - len(S)
            while temp >= -len(S):
                if S[temp] == C:
                    break
                distance_pre += 1
                temp -= 1
            if temp < -len(S):
                distance_pre = 0xFFFFFFFF  # not found
            # search forword
            temp = i
            while temp < len(S):
                if S[temp] == C:
                    break
                distance_post += 1
                temp += 1
            if temp == len(S):
                distance_post = 0xFFFFFFFF  # not found
            # append the shortest distance
            output.append(min(distance_pre, distance_post))
            distance_pre = 0
            distance_post = 0

        return output


if __name__ == '__main__':
    sol = Solution()
    print sol.shortestToChar('abaa', 'b')
