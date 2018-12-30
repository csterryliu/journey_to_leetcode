#include <iostream>
#include <unordered_set>
#include "./distribute_candies.h"

using namespace std;

int Solution::distributeCandies(vector<int>& candies) {
    int length = candies.size();
    int counts_per_person = length / 2;
    unordered_set<int> all_kinds;
    // O(n)
    for (int i = 0; i < length; ++i) {
        all_kinds.insert(candies[i]);
    }
    int total_kinds = all_kinds.size();
    // if (total_kinds >= counts_per_person) {
    //     return counts_per_person;
    // } else {
    //     return total_kinds;
    // }
    return min(total_kinds, counts_per_person);
}

int main() {
    vector<int> candies;
    candies.push_back(1);
    candies.push_back(1);
    candies.push_back(2);
    candies.push_back(3);
    //candies.push_back(3);
    //candies.push_back(3);
    Solution* sol = new Solution();
    int output = sol->distributeCandies(candies);
    delete sol;

    cout << output << "\n";

    return 0;
}