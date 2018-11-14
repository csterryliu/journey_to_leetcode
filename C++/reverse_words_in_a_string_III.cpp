#include <iostream>
#include <map>  // map is in sorted order
#include "./reverse_words_in_a_string_III.h"
#include "./utility.h"

using namespace std;

string Solution::reverseWords(string s) {
    string output = "";
    return output;
}

int main() {
    string s = "Let's take LeetCode contest";

    Solution* sol = new Solution();
    string output = sol->reverseWords(s);
    delete sol;

    cout << output << "\n";

    return 0;
}