#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    Solution() {}
    int minCostClimbingStairs(vector<int>& cost);
    int minCost(vector<int>& cost, int step);
    int minCostMemoization(vector<int>& cost, int step);
    int minCostTabulation(vector<int>& cost, int step);
    unordered_map<int, int> table;
};