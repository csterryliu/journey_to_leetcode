#include <iostream>
#include "./climbing_stairs.h"
#include "./utility.h"

using namespace std;

// the state: state(n)
// it stands for the number of distinct way to climb to the top when total steps is n

// recursive solution
// complexity: O(2^n)
int Solution::climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    return climbStairs(n-1) + climbStairs(n-2);
}

// dynamic programming: memoization (top-down)
// complexity: O(n)
int Solution::climbStairsMemoization(int n) {
    if (table.count(n) > 0) {
        return table[n];
    }
    if (n == 1) return 1;
    if (n == 2) return 2;
    table[n] = climbStairs(n-1) + climbStairs(n-2);
    return table[n];
}

// dymamic programming: tabulation (bottom-up)
// complexity: O(n)
// better than top-down method
int Solution::climbStairsTabulation(int n) {
    table[1] = 1;
    table[2] = 2;
    for (int i = 3; i <= n; ++i) {
        table[i] = table[i-1] + table[i-2];
    }
    return table[n];
}

int main() {
    Solution* sol = new Solution();
    //int output = sol->climbStairs(4);
    //int output = sol->climbStairsMemoization(4);
    int output = sol->climbStairsTabulation(4);
    delete sol;

    cout << output << "\n";

    return 0;
}