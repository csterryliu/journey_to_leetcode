class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = {}
        for ch in s:
            if ch not in count:
                count[ch] = 1
            else:
                count[ch] += 1
                
        for i in range(len(s)):
            if count[s[i]] == 1:
                return i
            
        return -1


if __name__ == '__main__':
    s = 'leetcode'
    sol = Solution()
    print sol.firstUniqChar(s)
