class Solution(object):
    def __init__(self):
        self.table = {'q': 1, 'w': 1, 'e': 1, 'r': 1, 't': 1, 'y': 1, 'u': 1, 'i': 1, 'o': 1, 'p': 1,
        'a': 2, 's': 2, 'd': 2, 'f': 2, 'g': 2, 'h': 2, 'j': 2, 'k': 2, 'l': 2,
        'z': 3, 'x': 3, 'c': 3, 'v': 3, 'b': 3, 'n': 3, 'm': 3}

    def findWords(self, words):
        output = []
        should_add = None
        for word in words:
            row = self.table[word[0].lower()]
            should_add = True
            for idx in xrange(1, len(word)):
                if self.table[word[idx].lower()] != row:
                    should_add = False
                    break
            if should_add:
                output.append(word)

        return output


if __name__ == '__main__':
    sol = Solution()
    print sol.findWords(["Hello", "Alaska", "Dad", "Peace"])
