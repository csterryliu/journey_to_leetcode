#include "./to_lower_case.h"
#include <iostream>

using namespace std;

string Solution::toLowerCase(string str) {
    for (int i = 0; i<str.length(); ++i) {
        if (str[i] <= 'Z' && str[i] >= 'A') {
            str[i] += 32;
        }
    }
    return str;
}


int main() {
    string input = "Hello";
    Solution* sol = new Solution();
    string output = sol->toLowerCase(input);
    delete sol;
    cout << output << "\n";
    return 0;
}