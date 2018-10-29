#include <iostream>
#include "./move_zeroes.h"
#include "./utility.h"

using namespace std;

void Solution::moveZeroes(vector<int>& nums) {
    // use a method which is similar to bubble sort
    // worst case may be O(n^2)
    for (int k = 0; k < nums.size() - 1; ++k) {
        bool is_swap = false;
        for (int i = 0; i < (nums.size()-1-k); ++i) {
            if (nums[i] == 0) {
                Utility::swapValues(nums[i], nums[i+1]);
                is_swap = true;
            }
        }
        if (!is_swap) break;
    }
}

int main() {
    vector<int> A;
    
    A.push_back(0);
    A.push_back(1);
    A.push_back(0);
    A.push_back(3);
    A.push_back(12);

    Solution* sol = new Solution();
    sol->moveZeroes(A);
    delete sol;

    Utility::printVector(A);

    return 0;
}