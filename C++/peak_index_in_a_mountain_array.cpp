#include <iostream>
#include "./peak_index_in_a_mountain_array.h"

using namespace std;

int Solution::peakIndexInMountainArray(vector <int>& A) {
    // use linear search
    // O(n)
    int i = 0;
    while (A[i] < A[i+1]) ++i;
    return i;
}

int Solution::peakIndexInMountainArrayBinarySeach(vector<int>& A) {
    // better solution with O(logn)
    // there's no way to get subvector. use index calculation
    int low = 0;
    int high = A.size() -1;
    int middle;
    while (low < high) {
        middle = (low+high) / 2;
        if (A[middle] > A[middle-1] && A[middle] > A[middle+1]) {
            return middle;
        } else if (A[middle] < A[middle+1]) {
            low = middle + 1;
        } else if (A[middle] < A[middle -1]) {
            high = middle;
        }
    }
    return -1; // no match
}

int main() {
    vector<int> A;
    A.push_back(1);
    A.push_back(5);
    A.push_back(4);
    A.push_back(3);
    A.push_back(2);
    A.push_back(1);
    Solution* sol = new Solution();
    int output = sol->peakIndexInMountainArrayBinarySeach(A);
    delete sol;

    cout << output << "\n";

    return 0;
}