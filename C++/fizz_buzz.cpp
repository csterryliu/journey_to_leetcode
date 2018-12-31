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

vector<string> Solution::fizzBuzzOptimize(int n) {
    vector<string> output;
    // this method decrease the number of if-else condition
    // O(n)
    for (int i = 1; i <= n; ++i) {
        string str = "";
        if (i % 3 == 0) {
            str += "Fizz";
        }
        if (i % 5 == 0) {
            str += "Buzz";
        }

        if (str == "") {
            char temp[100];
            sprintf(temp, "%d", i);
            str += temp;
        }

        output.push_back(str);
    }
    return output;
}

int main() {
    int input = 15;
    Solution* sol = new Solution();
    vector<string> output = sol->fizzBuzzOptimize(input);
    delete sol;

    for (int i = 0; i <= input; ++i) {
        cout << output[i] << " ";
    }
    return 0;
}