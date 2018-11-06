class Solution(object):
    def maxProfit(self, prices):
        """
        The point is, just find the mininum value. That will be the best buying day.
        After you find it, you don't care about the days before it since this is the best day to buy
        Then, just check when is your best day to sell it. And this day must be the day after it.
        """
        if not prices:
            return 0
        min_prices = prices[0]
        max_profit = 0
        for day in range(len(prices)):
            if prices[day] < min_prices:
                min_prices = prices[day]
            elif prices[day] - min_prices > max_profit:
                max_profit = prices[day] - min_prices
        return max_profit


if __name__ == '__main__':
    sol = Solution()
    print sol.maxProfit([7,1,5,3,6,4])
