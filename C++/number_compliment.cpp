#include <iostream>
#include "./number_compliment.h"

using namespace std;

int Solution::findComplement(int num) {
    int temp = num;
    // if we use int here, the result will be different....
    unsigned int bitmask = 0xFFFFFFFF;
    while ( !(temp & (0x80000000)) ) {
        bitmask >>= 1;   // This operation will be affacted negative number: It will use "1" as the padding!
        temp <<= 1;  // This operation won't be affacted by negative number: It always use "0" as the padding.
    }
    return (~num) & (bitmask);
}

int main() {
    Solution* sol = new Solution();
    int output = sol->findComplement(1);
    delete sol;
    cout << output << "\n";
    return 0;
}