class Solution(object):
    def reverseWords(self, s):
        # total: O(n+n+n) => O(n)
        words = s.split()  # O(n)
        return ' '.join([w[::-1] for w in words]) # O(n + n)



if __name__ == '__main__':
    s = "Let's take LeetCode contest"
    sol = Solution()
    print sol.reverseWords(s)