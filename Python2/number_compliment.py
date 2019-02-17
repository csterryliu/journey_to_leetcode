class Solution(object):
    def findComplement(self, num):
        bitmask = 0xFFFFFFFF  # all bits are "1"
        temp = num
        # find the number of leading zero bits we need to filter out
        while not temp & 0x80000000:
            # Because we will do AND operation. The zero bits will be used to filter the leading "1" bits after inverting the bits
            # On the contrary, the "1" bits won't affect the original value
            bitmask >>= 1
            # this is for knowing when we should stop: reaching the first non-zero bit
            temp <<= 1
        return ~(num) & bitmask


if __name__ == '__main__':
    sol = Solution()
    print sol.findComplement(1)
