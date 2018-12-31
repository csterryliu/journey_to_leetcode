#include <iostream>
#include <unordered_set>
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

int Solution::singleNumberHash(vector<int>& nums) {
    unordered_set<int> temp;
    vector<int>::const_iterator iter;
    for (iter = nums.cbegin(); iter != nums.cend(); ++iter) {
        if (temp.count(*iter) == 0) {
            temp.insert(*iter);  // O(1) in average. O(n) in worse (collision)
        } else {
            temp.erase(*iter);  // O(1) in average. O(n) in worse (collision)
        }
    }
    // time: O(n)
    // space: O(n)
    return *(temp.cbegin());
}

int main() {
    vector<int> A;
    
    A.push_back(4);
    A.push_back(1);
    A.push_back(2);
    A.push_back(1);
    A.push_back(2);
    
    Solution* sol = new Solution();
    int output = sol->singleNumberHash(A);
    delete sol;

    cout << output << "\n";

    return 0;
}