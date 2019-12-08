#include "squares_of_a_sorted_array.h"
#include "utility.h"
#include <iostream>
#include <set>
using namespace std;

vector<int> Solution::sortedSquares(vector<int>& A) {
    vector<int> output;
    // O(n)
    for (vector<int>::const_iterator iter = A.cbegin(); iter != A.cend(); ++iter) {
        output.push_back((*iter)*(*iter));
    }
    // O(nlogn)
    sort(output.begin(), output.end());
    return output;
}

// this method uses more memory but its time consumption is close to the first method
vector<int> Solution::sortedSquares2(vector<int>& A) {
    // set only has unique keys. but multiset allows the same key
    multiset<int> s;
    // O(n * nlogn)?
    for (vector<int>::const_iterator iter = A.cbegin(); iter != A.cend(); ++iter) {
        s.insert((*iter)*(*iter));
    }
    vector<int> output(s.begin(), s.end());
    return output;
}

int main() {
    vector<int> A;
    A.push_back(-4);
    A.push_back(-1);
    A.push_back(0);
    A.push_back(3);
    A.push_back(10);
    Utility::printVector(A);
    cout << endl;
    Solution* s = new Solution();
    vector<int> output = s->sortedSquares2(A);
    Utility::printVector(output);
    cout << endl;
    return 0;
}