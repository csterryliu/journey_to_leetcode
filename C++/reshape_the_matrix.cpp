#include <iostream>
#include "./reshape_the_matrix.h"
#include "./utility.h"

using namespace std;

vector<vector<int> > Solution::matrixReshape(vector<vector<int> >& nums, int r, int c) {
    // error handing
    int origin_rows = nums.size();
    int origin_cols =  origin_rows > 0 ? nums[0].size(): 0;
    int product = origin_cols * origin_rows;
    if (product == 0 || product != (r * c)) {
        cout << "sxxxxx";
        return nums;
    }

    vector<vector<int> > output;
    int origin_row_idx = 0, origin_col_idx = 0;
    // O(r*c)
    for (int i = 0; i < r; ++i) {
        vector<int> this_row;
        for (int j = 0; j < c; ++j) {
            this_row.push_back(nums[origin_row_idx][origin_col_idx]);
            origin_col_idx++;
            // carriage return
            if (origin_col_idx == origin_cols) {
                origin_col_idx = 0;
                origin_row_idx += 1;
            }
        }
        output.push_back(this_row);
    }

    return output;
}

int main() {
    vector<vector<int> > A;
    
    vector<int> r1;
    r1.push_back(1);
    r1.push_back(2);
    vector<int> r2;
    r2.push_back(3);
    r2.push_back(4);
    
    A.push_back(r1);
    A.push_back(r2);

    Solution* sol = new Solution();
    vector<vector<int> > output = sol->matrixReshape(A, 1, 4);
    delete sol;

    Utility::printVector(output[0]);

    return 0;
}