class Solution(object):
    def is_letter(self, ch):
        ascii_code = ord(ch.lower())
        if ascii_code >= 97 and ascii_code <= 122:
            return True
        return False

    def swap(self, array, idx1, idx2):
        temp = array[idx1]
        array[idx1] = array[idx2]
        array[idx2] = temp

    def reverseOnlyLetters(self, S):
        output = [0] * len(S)
        front = 0
        rear = len(S) - 1
        #  O(N), where N is the length of S.
        while front <= rear:
            if not self.is_letter(S[front]):
                output[front] = S[front]
                front += 1
                continue
            if not self.is_letter(S[rear]):
                output[rear] = S[rear]
                rear -= 1
                continue
            if front < rear:
                output[front] = S[rear]
                output[rear] = S[front]
            elif front == rear:
                output[front] = S[front]
            front += 1
            rear -= 1
        return ''.join(output)

    def reverseOnlyLettersStack(self, S):
        # From leetcode
        # It's better and more elegant.
        # Very simple and clear. I should try my best to think in this way!
        output = []
        letters_stack = [c for c in S if c.isalpha()]
        for ch in S:
            if ch.isalpha():
                output.append(letters_stack.pop())
            else:
                output.append(ch)
        return ''.join(output)

    def reverseOnlyLettersReversedPointer(self, S):
        output = []
        rear = len(S) - 1
        for i, x in enumerate(S):
            if x.isalpha():
                while not S[rear].isalpha():
                    rear -= 1
                output.append(S[rear])
                rear -= 1
            else:
                output.append(x)
        return ''.join(output)



if __name__ == '__main__':
    sol = Solution()
    ans = sol.reverseOnlyLettersReversedPointer('a-bC-dEf-ghIj')
    print ans
