#include <iostream>
#include "./self_dividing_numbers.h"
#include "./utility.h"

using namespace std;

vector<int> Solution::selfDividingNumbers(int left, int right) {
    vector<int> output;
    int integer = left;
    bool is_self_dividing;
    while (integer <= right) {
        is_self_dividing = true;

        // find every digit from the rightmost number
        int base = 10;
        int temp = integer;
        do {
            int rightmost = temp % base;
            if (rightmost == 0 || integer % rightmost != 0) {
                is_self_dividing = false;
                break;
            }
            // shift number
            temp /= base;
        } while(temp != 0);
        
        if (is_self_dividing) output.push_back(integer);
        integer++;
    }
    return output;
}

int main() {
    Solution* sol = new Solution();
    vector<int> output = sol->selfDividingNumbers(1, 22);
    delete sol;
    Utility::printVector(output);
    return 0;
}