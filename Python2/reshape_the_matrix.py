class Solution(object):
    origin_rows = 0
    origin_cols = 0

    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        self.origin_rows = len(nums)
        self.origin_cols = len(nums[0]) if self.origin_rows > 0 else 0
        if self.origin_cols*self.origin_rows == 0 or (self.origin_rows*self.origin_cols) != (r*c):
            return nums

        return self.optimized_way(nums, r, c)

    def optimized_way(self, nums, r, c):
        lst = [y for x in nums for y in x]
        # output = []
        # for i in range(r):
        #     output.append(lst[i*c:i*c+c])
        #return output
        return [lst[i*c:i*c+c] for i in range(r)]

    def easy_way(self, nums, r, c):
        output = []
        origin_row_idx = origin_col_idx = 0
        for _ in range(r):
            this_row = []
            for _ in range(c):
                print origin_row_idx, origin_col_idx
                this_row.append(nums[origin_row_idx][origin_col_idx])
                origin_col_idx += 1
                if origin_col_idx == self.origin_cols:
                    origin_row_idx += 1
                    origin_col_idx = 0
            output.append(this_row)
        return output


if __name__ == '__main__':
    nums = [[1, 2], [3, 4]]
    r = 1
    c = 4
    sol = Solution()
    print sol.matrixReshape(nums, r, c)
