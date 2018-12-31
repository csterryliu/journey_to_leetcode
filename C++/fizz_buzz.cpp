#include <iostream>
#include <cstdio>
#include <string>
#include "./utility.h"
#include "./fizz_buzz.h"

using namespace std;

vector<string> Solution::fizzBuzz(int n) {
    vector<string> output;
    // O(n)
    for (int i = 1; i <= n; ++i) {
        if (i % 15 == 0) {
            output.push_back("FizzBuzz");
        } else if (i % 3 == 0) {
            output.push_back("Fizz");
        } else if (i % 5 == 0) {
            output.push_back("Buzz");
        } else {
            char temp[100];
            sprintf(temp, "%d", i);
            output.push_back(temp);
        }
    }
    return output;
}

int main() {
    int input = 15;
    Solution* sol = new Solution();
    vector<string> output = sol->fizzBuzz(input);
    delete sol;

    for (int i = 0; i <= input; ++i) {
        cout << output[i] << " ";
    }
    return 0;
}