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
	
    def twoSumBinarySearch(self, numbers, target):
	#O(nlogn)
	for i in range(len(numbers)):
	    l = i + 1
	    r = len(numbers) - 1
	    compliment =  target - numbers[i]
            # using binary search to find the compliment
	    while l <= r:
	        mid = l + ((r - l) / 2). # or (l + r)/2
	        if numbers[mid] == compliment:
		    return [i+1, mid+1]
	        if numbers[mid] > compliment:
	            r = mid - 1
	        elif numbers[mid] < compliment:
	            l = mid + 1
	return None
