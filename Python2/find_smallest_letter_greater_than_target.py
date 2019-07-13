class Solution(object):
    def bestSolutionFromLeetCode(self, letters, target):
        # in fact, binary serach is enough
        # just keep searching even if we have found the answer
        # keyword: "loop invariant"
        l = 0
        r = len(letters) 
        while l < r:
            mid = l + ((r - l) / 2)
            if letters[mid] <= target:
                l = mid + 1
            else:
                r = mid
        # we can use modulo to wrap around!
        # note: l and r will be the same here
        return letters[l % len(letters)]

    def bestSolutionFromLeetCode2(self, letters, target):
        # use built-in binary search function
        index = bisect.bisect(letters, target)
        return letters[index % len(letters)]

    def nextGreatestLetter(self, letters, target):
        # the array is always sorted - considering binary search
        # find the index of the target, then we return the next greater letter
        l = 0
        r = len(letters) - 1
        mid = None
        target_idx = None
        while l <= r:
            mid = l + ((r - l) / 2)
            if letters[mid] == target:
                target_idx = mid
                break
            elif letters[mid] < target:
                l = mid + 1
            else:
                r = mid - 1

        if target_idx is None:
            # 3 cases:
            # target is greater than all letters
            if mid == len(letters) - 1 and letters[mid] < target:
                return letters[0]
            # target is smaller than all letters
            if mid == 0 and letters[mid] > target:
                return letters[0]
            # target should be among the letters, but it's not
            if letters[mid] > target:
                return letters[mid]
            else:
                return letters[mid + 1] if mid < len(letters)-1 else letters[0]

        
        # the letter is among the array.
        # 2 cases:
        
        # the letter is at the last index of the array
        if target_idx == len(letters) - 1:
            return letters[0]

        # it's not at the last index. the letter may be duplicated.
        # we have to loop the array to find the smallest greater letter
        # and we still have to be aware of the last index
        while letters[target_idx] == target:
            target_idx = target_idx + 1
            if target_idx == len(letters):
                target_idx = 0  # wrap arund

        # O(logn) + O(n)?  => O(n)?
        return letters[target_idx]


if __name__ == '__main__':
    sol = Solution()
    print sol.bestSolutionFromLeetCode(["c", "f", "j"], "c")
    print sol.bestSolutionFromLeetCode(["c", "f", "j"], "a")
    print sol.bestSolutionFromLeetCode(["c", "f", "j"], "d")
    print sol.bestSolutionFromLeetCode(["c", "f", "j"], "g")
    print sol.bestSolutionFromLeetCode(["c", "f", "j"], "j")
    print sol.bestSolutionFromLeetCode(["c", "f", "j"], "k")
    print sol.bestSolutionFromLeetCode(["e","e","e","e","e","e","n","n","n","n"], "e")
    print sol.bestSolutionFromLeetCode(["e","e","e","e","e","e","n","n","n","n"], "n")
    print sol.bestSolutionFromLeetCode(["e","e","e","e","e","e","n","n","n","n"], "e")
