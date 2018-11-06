class Solution(object):
    def sortArrayByParity(self, A):
        output = []
        evenIndex = oddIndex = 0
        for i in range(len(A)):
            if i % 2 == 0:
                # print 'even index'
                while A[evenIndex] % 2 != 0: evenIndex += 1
                output.append(A[evenIndex])
                evenIndex += 1
            else:
                # print 'odd index'
                while A[oddIndex] % 2 == 0: oddIndex += 1
                output.append(A[oddIndex])
                oddIndex += 1
        return output


if __name__ == '__main__':
    A = [3, 1, 2, 4]
    sol = Solution()
    print sol.sortArrayByParity(A)
