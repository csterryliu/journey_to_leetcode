class Solution(object):
    def __init__(self):
        self.max_unit_per_line = 100
        self.ascii_a = ord('a')

    def numberOfLines(self, widths, S):
        def index_of_ch(ch):
            return ord(ch) - self.ascii_a

        total_lines = 1
        current_width = 0
        for ch in S:
            if current_width + widths[index_of_ch(ch)] >\
               self.max_unit_per_line:
                total_lines += 1
                current_width = widths[index_of_ch(ch)]
            else:
                current_width += widths[index_of_ch(ch)]
        return [total_lines, current_width]


if __name__ == '__main__':
    widths = [4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
    S = "bbbcccdddaaa"
    sol = Solution()
    print sol.numberOfLines(widths, S)
