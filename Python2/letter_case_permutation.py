class Solution(object):
    # time complexity:
    # If we treat string concatenation (v+p) as O(1),
    # then the total time complexity should be:
    # O(2^(number of alphabets) + (number of non-alphabets))

    # I solved this problem in dynamic programming way (tabulation)
    # But in leetcode, this is belonged to "backtracking" category.
    # Maybe I should look into that.

    def letterCasePermutation(self, S):
        def getPermutations(value_to_add, permutations):
            output = []
            for v in value_to_add:
                for p in permutations:
                    output.append(v + p)
            return output

        table = [0] * len(S)
        idx = len(S) - 1
        if S[idx].isalpha():
            table[idx] = [S[idx].upper(), S[idx].lower()]
        else:
            table[idx] = [S[idx]]
        idx -= 1
        while idx >= 0:
            if S[idx].isalpha():
                table[idx] = getPermutations([S[idx].upper(), S[idx].lower()],
                                             table[idx+1])
            else:
                table[idx] = getPermutations([S[idx]], table[idx+1])
            idx -= 1
        return table[0]


if __name__ == '__main__':
    sol = Solution()
    output = sol.letterCasePermutation('54321')
    print output
