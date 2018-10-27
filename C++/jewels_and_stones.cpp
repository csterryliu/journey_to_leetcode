#include "./jewels_and_stones.h"
#include <set>

using namespace std;

int Solution::numJewelsInStones(string J, string S) {
    set<char> mySet;
    int counter = 0; 
    
    for (int i = 0; i < J.length(); ++i) {
        mySet.insert(J[i]);
    }
    
    // accroding to c++11, it may be O(S*logJ)
    for (int i = 0; i < S.length(); ++i) {
        if (mySet.count(S[i]) > 0) {
            counter++;
        }
    }
    
    return counter;
}

int main() {
    string J = "aAKlUngG";
    string S = "aAAbbbbkGnUKKaaA";
    Solution* sol = new Solution();
    int ret = sol->numJewelsInStones(J, S);
    printf("counts: %d\n", ret);
    delete sol;
}

