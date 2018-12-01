#include <iostream>
#include "./min_cost_climbing_stairs.h"
#include "./utility.h"

using namespace std;

#define COST(i) (i<cost.size()?cost.at(i):0)

int Solution::minCostClimbingStairs(vector<int>& cost) {
    /*// from leetcode
    // use dynamic programming
    reverse(cost.begin(), cost.end());
    int f1 = 0;
    int f2 = 0;
    for (int i = 0; i < cost.size(); ++i) {
        f1 = min(f1, f2) + cost.at(i);
        f2 = f1;
    }
    return min(f1, f2);*/
    
    
    
    if (cost.size() == 2) {
        return min(cost.at(0), cost.at(1));
    }
    int index = 0;
    int output = 0;
    while (cost.size() - index > 2) {
        int min_value = INT_MAX;
        int base_value = COST(index);
        int jump = 0;
        int dst = 0;
        for (int i = 1; i <= 4; i++) {
            dst = (i > 2 ? i - 1 : i);
            if (i == 3) {
                base_value = COST(index + 1);
            }
            if (base_value + COST(index+dst) < min_value) {
                min_value = base_value + COST(index+i);
                jump = dst;
            }
        }
        index += jump;
        output += min_value;
    }
    return output;
}

int main() {
    vector<int> A;
    
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