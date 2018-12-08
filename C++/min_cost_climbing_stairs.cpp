#include <iostream>
#include "./min_cost_climbing_stairs.h"
#include "./utility.h"

using namespace std;


// my state: minCost(n)
// it stands for the minimum cost of step n

int Solution::minCostClimbingStairs(vector<int>& cost) {
    // recursive way
    //return min(minCost(cost, 0), minCost(cost, 1));

    // top-down
    // construct the table first
    //minCostMemoization(cost, 0);
    //return min(table[0], table[1]);

    // buttom-up
    // construct the table first
    minCostTabulation(cost, 0);
    return min(table[0], table[1]);
}

// O(2^n). very bad
int Solution::minCost(vector<int>& cost, int step) {
    if (step + 1 >= cost.size() || step + 2 >= cost.size()) {
        return cost[step];
    }
    return cost[step] + min(minCost(cost, step+1), minCost(cost, step+2));
}

// Dynamic programming: memoization (top-down) or tabulation (buttom-up)
// The complexity is O(n). Because we only need to compute each value once.
// Tabulation is better than memoization (Based on the result on the LeetCode website)
int Solution::minCostMemoization(vector<int>& cost, int step) {
    if (table.count(step) > 0) return table[step];
    if (step + 1 >= cost.size() || step + 2 >= cost.size()) {
        return cost[step];
    }
    table[step] = cost[step] + min(minCostMemoization(cost, step+1), minCostMemoization(cost, step+2));
    return table[step];
}

int Solution::minCostTabulation(vector<int>& cost, int step) {
    // We have to traverse the array backword.
    // Because the original order has us compute forword.
    // But it's easier to compute the table backword.
    for (int i = cost.size()-1; i >= step; --i) {
        if (i + 1 >= cost.size() || i + 2 >= cost.size()) {
            table[i] = cost.at(i);
        } else {
            table[i] = cost.at(i) + min(table[i+1], table[i+2]);
        }
    }
    return table[step];
}

int main() {
    vector<int> A;

    /*A.push_back(10);
    A.push_back(15);
    A.push_back(20);*/
    
    A.push_back(1);
    A.push_back(100);
    A.push_back(1);
    A.push_back(1);
    A.push_back(1);
    A.push_back(100);
    A.push_back(1);
    A.push_back(1);
    A.push_back(100);
    A.push_back(1);
    
    Solution* sol = new Solution();
    int output = sol->minCostClimbingStairs(A);
    delete sol;

    cout << output << "\n";

    return 0;
}