#include <iostream>
#include "./sort_array_by_parity.h"

using namespace std;

vector<int> Solution::sortArrayByParity(vector <int>& A) {
    vector<int> output;
    for (int i = 0; i < A.size(); ++i) {  // O(A.size())
        if (output.empty()) {
            output.push_back(A[i]);  // amortized O(1)
            continue;
        }
        if (A[i] % 2 == 0) {
            // Constant plus linear in the distance between pos and end of the container.
            // cbegin(): constant
            output.insert(output.cbegin(), A[i]);
        } else {
            output.push_back(A[i]);  // amortized O(1)
        }
    }
    return output;
}

int main() {
    vector<int> A;
    A.push_back(3);
    A.push_back(1);
    A.push_back(2);
    A.push_back(4);
    Solution* sol = new Solution();
    vector<int> output = sol->sortArrayByParity(A);
    delete sol;

    for (vector<int>::iterator iter = output.begin(); iter != output.end(); iter++) {
        cout << *iter << " ";
    }
    cout << "\n";

    return 0;
}