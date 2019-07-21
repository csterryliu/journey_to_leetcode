class Solution(object):
    def lastStoneWeight(self, stones):
        while len(stones) > 1:
            stones.sort()  # O(nlogn)
            s1 = stones.pop()
            s2 = stones.pop()
            if s1 == s2:
                continue
            stones.append(abs(s1-s2))

        return 0 if len(stones) == 0 else stones[0]

    def priorityQueue(self, stones):
        import heapq
        # heapq is a min-heap priority queue
        # so we need to use negative value in order to put the largest number in the root node
        hq = [-stone for stone in stones]  # O(n)
        heapq.heapify(hq)  # O(nlogn) or O(n)
        for _ in xrange(len(stones) - 1):
            # apply negative again to get the original value
            s1, s2 = -heapq.heappop(hq), -heapq.heappop(hq)
            # calculate the difference and save the negative value into the heap
            heapq.heappush(hq, -abs(s1-s2))
        return -hq[0]  # hq[0] will be the smallest number. apply negative to restore the value

if __name__ == '__main__':
    sol = Solution()
    print sol.priorityQueue([2,7,4,1,8,1])
