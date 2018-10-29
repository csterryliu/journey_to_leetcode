#include <iostream>
#include <map>  // map is in sorted order
#include "./reverse_string.h"
#include "./utility.h"

using namespace std;

string Solution::reverseString(string s) {
    int tail = s.size() - 1;
    string output = "";
    // O(s.size())
    while (tail >= 0) {
        output += s[tail];
        tail -= 1;
    }
    return output;
}

int main() {
    string s = "hello";

    Solution* sol = new Solution();
    string output = sol->reverseString(s);
    delete sol;

    cout << output << "\n";

    return 0;
}