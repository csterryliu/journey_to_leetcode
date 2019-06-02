class Solution(object):
    def reverseVowels(self, s):
        # vowel letters in English: A, E, I, O, U
        # Y is not considered as the vowel here
        vowels = set(['a', 'e', 'i', 'o', 'u'])
        vowels_in_string = []
        index_to_be_put = []
        output = []
        # O(len(s))
        for idx, letter in enumerate(s):
            if letter.lower() in vowels:
                vowels_in_string.append(letter)
                index_to_be_put.append(idx)
                output.append(0)
            else:
                output.append(letter)
        for idx in index_to_be_put:
            output[idx] = vowels_in_string.pop()
        return ''.join(output)

if __name__ == '__main__':
    sol = Solution()
    print sol.reverseVowels('leetcode')
