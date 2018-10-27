class Solution(object):
    def uniqueMorseRepresentations(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        def turn_into_morse(string):
            temp = []
            # O(len(string))
            # for ch in string:
            #     temp.append(morse[indexOf(ch)])  # amortized O(1)
            temp = [morse[indexOf(ch)] for ch in string] # use list comprehension will be better than normal for loop
            return ''.join(temp)  # O(len(output))

        def indexOf(char):  # O(1)
            return ord(char) - 97

        morse = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]

        myset = set()
        # counter = 0

        for w in words:
            morse_str = turn_into_morse(w)
            # if morse_str not in myset:  # O(1) in average, O(n) in worst
            #     myset.add(morse_str)  # set is implemented in hash table. O(1) if no collision otherwise O(n)
            #     counter += 1

            # add operation of set will keep the elements of set being unique
            myset.add(morse_str)

        # return counter
        return len(myset)


if __name__ == '__main__':
    words = ["gin", "zen", "gig", "msg"]
    sol = Solution()
    print sol.uniqueMorseRepresentations(words)
