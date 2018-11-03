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


if __name__ == '__main__':
    s = 'RRDD'
    sol = Solution()
    print sol.judgeCircle(s)
