class Solution(object):
    # it's too slow! every character need to perform n times of loop!
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

    # from leetcode solution
    # O(n)
    def betterSol(self, S, C):
        output = []
        # negtive_num - (-inf) = inf. We can consider it as a very big int
        last_pos_of_c = float('-inf')
        # O(n)
        for idx, ch in enumerate(S):
            if ch == C:
                last_pos_of_c = idx
            # Because we go toward right. Index must be greater than the latest index of the target we found
            output.append(idx - last_pos_of_c)
        last_pos_of_c = float('inf')
        # O(n)
        for idx in xrange(len(S)-1, -1, -1):
            if S[idx] == C:
                last_pos_of_c = idx
            # Because we go toward left. Index must be lesser than the latest index of the target we found
            output[idx] = min(output[idx], last_pos_of_c - idx)
        return output


if __name__ == '__main__':
    sol = Solution()
    # print sol.shortestToChar('loveleetcode', 'e')
    print sol.betterSol('loveleetcode', 'e')
