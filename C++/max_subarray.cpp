#include <iostream>
#include "./max_subarray.h"
#include "./utility.h"

using namespace std;

// state: max_sum(start_index) = 
// max(num_array[start_index], num_array[start_index] + max_sum(start_index+1))


int Solution::maxSubArray(vector<int>& nums) {
    return maxSubArrayTabulation(nums);
}

// dynamic programming: tabulation
// O(n)
int Solution::maxSubArrayTabulation(vector<int>& nums) {
    table[nums.size()-1] = *(--(nums.cend()));
    int max_sum = table[nums.size()-1];
    for (int i = nums.size()-2; i >= 0; --i) {
        table[i] = max(nums.at(i), nums.at(i) + table[i+1]);
        if (table[i] > max_sum) {
            max_sum = table[i];
        }
    }
    return max_sum;
}


int main() {
    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(4);
    Solution* sol = new Solution();
    int output = sol->maxSubArray(nums);
    delete sol;

    cout << output << "\n";

    return 0;
}