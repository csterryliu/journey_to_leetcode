#include "./hamming_distance.h"
#include <iostream>

using namespace std;

int Solution::countSetBits(int x) {
    int count = 0;
    // theta(logn)
    while (x) {
        count += (x & 1);  // AND 1 to know the value of the last bit
        x >>= 1; // shift right by 1
    }
    return count;
}

int Solution::hammingDistance(int x, int y) {
    // Do XOR first
    int xor_result = x ^ y;
    // count the number of set bits
    return countSetBits(xor_result);
}


int main() {
    Solution* sol = new Solution();
    int output = sol->hammingDistance(1, 4);
    delete sol;
    cout << output << "\n";
    return 0;
}