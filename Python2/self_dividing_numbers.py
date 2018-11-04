class Solution(object):
    def selfDividingNumbers(self, left, right):
        output = []
        integer = left
        base = 10
        while integer <= right:
            is_self_dividing = True
            temp = integer
            while temp:
                rightmost = temp % base
                if rightmost == 0 or integer % rightmost != 0:
                    is_self_dividing = False
                    break
                temp /= base
            if is_self_dividing:
                output.append(integer)
            integer += 1
        return output


if __name__ == '__main__':
    sol = Solution()
    print sol.selfDividingNumbers(1, 22)
