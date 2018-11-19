#include <iostream>
#include <unordered_set>
#include "./groups_of_special_equivalent_strings.h"
#include "./utility.h"

using namespace std;

// from leetcode discuss
// use in-place sort instead of count, separate even index and odd index
// space complexity: O(1), time: 8ms
int Solution::numSpecialEquivGroups(vector<string>& A) {
    for (int i = 0; i < A.size(); ++i) {
        sortWord(A[i]);
    }
    sort(A.begin(), A.end());
        
    int result = 0;
    for (int i = 0; i < A.size(); ++i) {
        if (i > 0 && A[i] == A[i - 1]) {
            continue;
        }
        ++result;
    }
    return result;
}

void Solution::sortWord(string& s) {
    // put all chars with even index to the left, odd index to the right:
    int i = 1, j = s.size() - 1;
    if (j % 2) {
        --j;
    }        
    while (i < j) {
        swap(s[i], s[j]);
        i += 2;
        j -= 2;
    }
    // sort left and right separately:
    int mid = (s.size() + 1) / 2;
    sort(s.begin(), s.begin() + mid);
    sort(s.begin() + mid, s.end());
}

// ----------------------------------------------
// from leetcode
// just count them all and put them into a set
// the duplicated one won't be put into it!
// time: 4ms
int Solution::numSpecialEquivGroupsBetter(vector<string>& A) {
    unordered_set<string> dict;
    for (const auto& s : A)
    {
        dict.insert(getCanonical(s));
    }
    return dict.size();
}

string Solution::getCanonical(const string& s) {
    string canon(s);
    int len = canon.size();
    for (int i = 0; i < len; ++i)
    {
        for (int j = i + 1; j < len; ++j)
        {
            if (i % 2 == j % 2 && canon[j] > canon[i])
            {
                swap(canon[i], canon[j]);
            }
        }
    }
    return canon;
}

int main() {
    vector<string> A;
    
    A.push_back("abc");
    A.push_back("acb");
    A.push_back("bac");
    A.push_back("bca");
    A.push_back("cab");
    A.push_back("cba");

    Solution* sol = new Solution();
    int output = sol->numSpecialEquivGroups(A);
    delete sol;

    cout << output << "\n";

    return 0;
}