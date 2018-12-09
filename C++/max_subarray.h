#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    Solution() {}
    int maxSubArray(vector<int>& nums);
    int maxSubArrayTabulation(vector<int>& nums);
    unordered_map<int, int> table;
};