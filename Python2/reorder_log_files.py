class Solution(object):
    def reorderLogFiles(self, logs):
        def f(log):
            id_, rest = log.split(" ", 1) # O(n)
            return (0, rest, id_) if rest[0].isalpha() else (1,)

        # Timsort, O(nlogn)
        return sorted(logs, key=f)


if __name__ == '__main__':
    input_val = ["a1 9 2 3 1", "g1 act car", "zo4 4 7", "ab1 off key dog", "a8 act zoo"]
    sol = Solution()
    print sol.reorderLogFiles(input_val)
