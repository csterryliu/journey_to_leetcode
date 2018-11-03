#include <iostream>
#include "./array_partition_I.h"
#include "./utility.h"

using namespace std;

int Solution::arrayPairSum(vector<int>& nums) {
    // sort the array first
    // nlog(n)
    sort(nums.begin(), nums.end());
    Utility::printVector(nums);
    int output = 0;
    // O(n/2) -> O(n)
    for (int i = 0; i < nums.size(); i+=2) {
        cout << nums[i] << nums[i+1] << "\n";
        // output += min(nums[i], nums[i+1]);
        output += nums[i];  // no need to find min value since the array is sorted
    }
    // total: O(nlogn + n)
    return output;
}

int main() {
    vector<int> input;
    input.push_back(1);
    input.push_back(1);
    Utility::printVector(input);

    Solution* sol = new Solution();
    int output = sol->arrayPairSum(input);
    delete sol;

    cout << output << "\n";

    return 0;
}