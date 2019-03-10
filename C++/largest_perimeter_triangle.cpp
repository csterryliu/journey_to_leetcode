#include <iostream>
#include "./largest_perimeter_triangle.h"
#include "./utility.h"

using namespace std;

int Solution::largestPerimeter(vector<int>& A) {
    sort(A.begin(), A.end());
    for (int i = A.size()-3; i >= 0; --i) {
        if (A[i] + A[i+1] > A[i+2]) {
            return A[i] + A[i+1] + A[i+2];
        }
    }
    return 0;
}

int main() {
    vector<int> A;
    
    A.push_back(2);
    A.push_back(1);
    A.push_back(2);
    
    Solution* sol = new Solution();
    int output = sol->largestPerimeter(A);
    delete sol;

    cout << output << "\n";

    return 0;
}