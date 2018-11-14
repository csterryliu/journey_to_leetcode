#include <iostream>
#include "./reverse_words_in_a_string_III.h"

using namespace std;

string Solution::reverseWords(string s) {
    if (s.length() == 1) return s;
    string::iterator iter;
    string::iterator temp_start_iter = s.begin();
    for (iter = s.begin(); iter != s.end(); ++iter) {
        if (*iter == ' ') {
            reverse(temp_start_iter, iter);
            temp_start_iter = iter+1;
        }
    }
    reverse(temp_start_iter, s.end());

    // the time complexity may be O(N + N) => O(N)
    return s;
}

int main() {
    string s = "Let's take LeetCode contest";

    Solution* sol = new Solution();
    string output = sol->reverseWords(s);
    delete sol;

    cout << output << "\n";

    return 0;
}