class Solution(object):
    def transpose(self, A):
        output = []
        row = len(A)
        col = len(A[0])
        for i in range(col):
            new_row = []
            for j in range(row):
                new_row.append(A[j][i])
            output.append(new_row)
        return output

    def unzip(self, A):
        return zip(*A)

    def list_comprehension(self, A):
        return [[row[col] for row in A] for col in range(len(A[0]))]


if __name__ == '__main__':
    A = [[1, 2, 3], [4, 5, 6]]
    sol = Solution()
    print sol.transpose(A)
    print sol.unzip(A)
    print sol.list_comprehension(A)
