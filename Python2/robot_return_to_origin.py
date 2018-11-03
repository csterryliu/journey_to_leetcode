class Solution(object):
    def judgeCircle(self, s):
        cordinate = [0, 0]
        for direction in s:
            if direction == 'U':
                cordinate[0] += 1
            elif direction == 'D':
                cordinate[0] -= 1
            elif direction == 'L':
                cordinate[1] -= 1
            elif direction == 'R':
                cordinate[1] += 1
            else:
                print 'Unknown move'
                return False
        if cordinate[0] == 0 and cordinate[1] == 0:
            return True
        return False

    def judgeCircleByCount(self, s):
        # count() is O(n), but it is implemented in native code.
        # So it will be faster than normal Python implementation
        # And we just have to make sure the number of L/R and U/D are the same
        return s.count('L') == s.count('R') and s.count('U') == s.count('D')


if __name__ == '__main__':
    s = 'RRDD'
    sol = Solution()
    print sol.judgeCircleByCount(s)
