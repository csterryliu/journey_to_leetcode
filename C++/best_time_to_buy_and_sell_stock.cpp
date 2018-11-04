#include <iostream>
#include "./best_time_to_buy_and_sell_stock.h"

using namespace std;

int Solution::maxProfit(vector<int>& prices) {
    int max_profit = 0;
    // O(n^2). not good
    for (int buy_day = 0; buy_day < prices.size(); ++buy_day) {
        for (int sell_day = buy_day + 1; sell_day < prices.size(); ++sell_day) {
            if (prices[sell_day] > prices[buy_day]){
                int temp = prices[sell_day] - prices[buy_day];
                if (temp > max_profit){
                    max_profit = temp;
                }
            }
        }
    }
    return max_profit;
}

int Solution::maxProfitOptimize(vector<int>& prices) {
    // The point is, just find the mininum value. That will be the best buying day.
    // After you find it, you don't care about the days before it since this is the best day to buy
    // Then, just check when is your best day to sell it. And this day must be the day after it.
    if (prices.empty()) return 0;
    int min_price = prices.front();
    int max_profit = 0;
    // it only costs O(n)!
    for (int day = 0; day < prices.size(); ++day) {
        if (prices[day] < min_price) {
            min_price = prices[day];
        } else if (prices[day] - min_price > max_profit) {
            max_profit = prices[day] - min_price;
        }
    }
    return max_profit;
}

int main() {
    vector<int> A;
    A.push_back(7);
    A.push_back(1);
    A.push_back(5);
    A.push_back(3);
    A.push_back(6);
    A.push_back(4);

    Solution* sol = new Solution();
    int output = sol->maxProfitOptimize(A);
    delete sol;

    cout << output << "\n";
    return 0;
}