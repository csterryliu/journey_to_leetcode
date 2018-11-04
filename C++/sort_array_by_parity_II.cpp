#include <iostream>
#include <stack>
#include "./utility.h"
#include "./sort_array_by_parity_II.h"

using namespace std;

vector<int> Solution::sortArrayByParity(vector <int>& A) {
    // no need to produce new array. it's in-place.
    vector<int> output;
    stack<int> even_index_need_swap;
    stack<int> odd_index_need_swap;
    // O(n)
    for (int i = 0; i < A.size(); ++i) {
        if (i % 2 == 0) { // even index
            if (A[i] % 2 != 0) {
                if (!odd_index_need_swap.empty()) {
                    Utility::swapValues(A[i], A[odd_index_need_swap.top()]);
                    odd_index_need_swap.pop();
                } else {
                    even_index_need_swap.push(i);
                }
            }
        } else {  // odd index
            if (A[i] % 2 == 0){
                if (!even_index_need_swap.empty()) {
                    Utility::swapValues(A[i], A[even_index_need_swap.top()]);
                    even_index_need_swap.pop();
                } 
                else {
                    odd_index_need_swap.push(i);
                }
            } 
        }
    }
    return A;
}

vector<int> Solution::sortArrayByParityOptimize(vector <int>& A) {
    /* from leetcode
    int oddIndex = 0, evenIndex = 0;
        vector<int> ret;
        for (int i = 0; i < A.size(); i++) {
            if (i % 2) { // odd
                while (A[oddIndex] % 2 == 0) oddIndex++;
                ret.push_back(A[oddIndex++]);
            } else { // even
                while (A[evenIndex] % 2) evenIndex++;
                ret.push_back(A[evenIndex++]);
            }
        }
        return ret;
    */



    vector<int> output;
    int evenindex= 0, oddindex = 0;
    // O(n)
    for (int i = 0; i < A.size(); ++i) {
        if (i % 2 == 0) { // even index
            while(A[evenindex] % 2 != 0) evenindex++;
            output.push_back(A[evenindex++]);
        } else {  // odd index
            while(A[oddindex] % 2 == 0) oddindex++;
            output.push_back(A[oddindex++]);
        }
    }
    return output;
}

int main() {
    vector<int> A;
    A.push_back(648);
    A.push_back(831);
    A.push_back(560);
    A.push_back(986);
    A.push_back(192);
    A.push_back(424);
    A.push_back(997);
    A.push_back(829);
    A.push_back(897);
    A.push_back(843);
    Solution* sol = new Solution();
    vector<int> output = sol->sortArrayByParity(A);
    delete sol;

    Utility::printVector(A);
    cout << "\n";

    return 0;
}