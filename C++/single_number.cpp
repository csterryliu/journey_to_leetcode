#include <iostream>
#include "./single_number.h"
#include "./utility.h"

using namespace std;

int Solution::singleNumber(vector<int>& nums) {
    if (nums.size() == 1) return nums.at(0);
    // sort the array
    sort(nums.begin(), nums.end());
    vector<int>::const_iterator iter;
    for (iter = nums.cbegin(); iter != nums.cend(); ++iter) {
        if ((iter == nums.cbegin() && (*iter) != *(iter+1)) ||
            (iter == nums.cend() && (*iter) != *(iter-1)) ||
            ((*iter) != *(iter+1) && (*iter) != *(iter-1))) {
            return (*iter);
        }
    }
    // O(nlogn + n)
    return 0;
}

int main() {
    vector<int> A;
    
    A.push_back(4);
    A.push_back(1);
    A.push_back(2);
    A.push_back(1);
    A.push_back(2);
    
    Solution* sol = new Solution();
    int output = sol->singleNumber(A);
    delete sol;

    cout << output << "\n";

    return 0;
}