class Solution(object):
    def twoSumTwoPointer(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
		  r = 0
   		l = len(numbers) - 1
		  # O(n)
		  while r < l:
	  	  s = numbers[r] + numbers[l]
			  if s > target:
	  		    l -= 1
	  		elif s < target:
	  		    r += 1
		  	else:
		  		return [r+1, l+1]
	  	return None
