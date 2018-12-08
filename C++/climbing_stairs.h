#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    Solution() {}
    int climbStairs(int n);
    int climbStairsMemoization(int n);
    int climbStairsTabulation(int n);
    unordered_map<int, int> table;
};