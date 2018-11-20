#include <iostream>
#include "./toeplitz_matrix.h"
#include "./utility.h"

using namespace std;

bool Solution::isToeplitzMatrix(vector<vector<int> >& matrix) {
    // I think the total time complexity is O(row*col)
    // And space complexity may be O(1) because it is in-place

    // this one do the half part of the matrix
    // note: at() and size() are constant time
    for (int col = 0; col < matrix.at(0).size(); ++col) {
        int temp_row = 0;
        int temp_col = col;
        int value = matrix.at(temp_row).at(temp_col);
        while (temp_row < matrix.size() && temp_col < matrix.at(0).size()) {
            if (value != matrix.at(temp_row).at(temp_col)) {
               return false;
            }
            ++temp_row;
            ++temp_col;
        }
    }

    // this one do the rest of the matrix. so all elements will be traversed
    for (int row = 1; row < matrix.size(); ++row) {
        int temp_row = row;
        int temp_col = 0;
        int value = matrix.at(temp_row).at(temp_col);
        while (temp_row < matrix.size() && temp_col < matrix.at(0).size()) {
            if (value != matrix.at(temp_row).at(temp_col)) {
               return false;
            }
            ++temp_row;
            ++temp_col;
        }
    }
    return true;
}

int main() {
    vector<vector<int> > matrix;
    vector<int> r1;
    r1.push_back(11);
    r1.push_back(74);
    r1.push_back(0);
    r1.push_back(93);
    vector<int> r2;
    r2.push_back(40);
    r2.push_back(11);
    r2.push_back(74);
    r2.push_back(7);
    /*vector<int> r3;
    r3.push_back(9);
    r3.push_back(5);
    r3.push_back(1);
    r3.push_back(2);*/
    matrix.push_back(r1);
    matrix.push_back(r2);
    //matrix.push_back(r3);
    Utility::printVector(matrix[0]);
    Utility::printVector(matrix[1]);
    //Utility::printVector(matrix[2]);
    
    Solution* sol = new Solution();
    bool output = sol->isToeplitzMatrix(matrix);
    delete sol;

    cout << output << "\n";

    return 0;
}