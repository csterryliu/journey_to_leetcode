class Solution(object):
    def lastStoneWeight(self, stones):
        while len(stones) > 1:
            stones.sort()  # O(nlogn)
            s1 = stones.pop()
            s2 = stones.pop()
            if s1 == s2:
                continue
            if s1 > s2:
                stones.append(s1-s2)
            else:
                stones.append(s2-s1)

        return 0 if len(stones) == 0 else stones[0]

    def priorityQueue(self, stones):
        return 0

if __name__ == '__main__':
    sol = Solution()
    print sol.lastStoneWeight([2,7,4,1,8,1])
