#include <iostream>
#include "./transpose_matrix.h"
#include "./utility.h"

using namespace std;

vector<vector<int> > Solution::transpose(vector<vector<int> >& A) {
    vector<vector<int> > output;
    int row = A.size();
    int col = A[0].size();
    // we have to swap the row and column
    // O(col*row) -> O(N), where N is the total number of elements
    for (int i = 0; i < col; ++i) {
        vector<int> new_row;
        for (int j = 0; j < row; ++j) {
            new_row.push_back(A[j][i]);
        }
        output.push_back(new_row);
    }

    return output;
}

int main() {
    vector<vector<int> > A;
    
    vector<int> r1;
    r1.push_back(1);
    r1.push_back(2);
    r1.push_back(3);
    A.push_back(r1);
    vector<int> r2;
    r2.push_back(4);
    r2.push_back(5);
    r2.push_back(6);
    A.push_back(r2);
    

    Utility::printVector(A[0]);
    Utility::printVector(A[1]);
    
    Solution* sol = new Solution();
    
    vector<vector<int> > output = sol->transpose(A);
    delete sol;

    Utility::printVector(output[0]);
    Utility::printVector(output[1]);
    Utility::printVector(output[2]);

    return 0;
}