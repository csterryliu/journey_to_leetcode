class Solution(object):
    def countPrimeSetBits(self, L, R):
        """
        :type L: int
        :type R: int
        :rtype: int
        """
        output = 0
        counter = 0
        for number in xrange(L, R+1):
            while number:
                if number & 1 == 1:
                    counter += 1
                number = number >> 1
            if self.is_prime(counter):
                output += 1
            counter = 0
        return output
    
    def is_prime(self, number):
    	# 0 and 1 are not prime numbers
    	if number == 0 or number == 1:
    		return False
    	# All even numbers are not prime numbers
    	# But 2 is a prime number
    	if number % 2 == 0 and number > 2:
    		return False
    	# Start from 3 until reaching the square root of the number.
    	# Also skipping all even numbers.
    	for x in range(3, int(number**0.5) + 1, 2):
    	    if number % x == 0:
    	    	return False
    	return True
