#include <iostream>
#include <map>  // map is in sorted order
#include "./first_unique_character_in_a_string.h"
#include "./utility.h"

using namespace std;

int Solution::firstUniqChar(string s) {
    map<char, int> counter;
    // construct the counter hash table
    // O(s.length())
    for (int i = 0; i < s.length(); ++i) {
        // find in map: O(logn)
        if (counter.find(s[i]) == counter.end()) {
            // access in map: O(logn)
            counter[s[i]] = 1;
        } else {
            counter[s[i]] += 1;
        }
    }
    // find the first unique character
    // O(s.length())
    for (int i = 0; i < s.length(); ++i) {
        // access in map: O(logn)
        if (counter[s[i]] == 1) {
            return i;
        }
    }
    return -1;
}

int main() {
    string s = "loveleetcode";

    Solution* sol = new Solution();
    int output = sol->firstUniqChar(s);
    delete sol;

    cout << output << "\n";

    return 0;
}