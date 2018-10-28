#include "./flipping_an_image.h"
#include "./utility.h"

using namespace std;

vector<vector<int> > Solution::flipAndInvertImage(vector<vector<int> >& A) {
    int temp = 0;
    // O(A.size())
    for (int i = 0; i < A.size(); ++i) {
        int begin_idx = 0;
        int end_idx = A[i].size() - 1;
        // it won't loop the whole array. it stops at the middle position.
        while (begin_idx < end_idx) {
            // swap begin and end
            // O(1)
            temp = A[i][begin_idx];
            A[i][begin_idx] = A[i][end_idx];
            A[i][end_idx] = temp;

            // invert numbers. use xor.
            // O(1)
            A[i][begin_idx] ^= 1;
            A[i][end_idx] ^= 1;

            // O(1)
            begin_idx++;
            end_idx--;
        }
        // O(1)
        if (begin_idx == end_idx) {
            A[i][begin_idx] ^= 1;
        }
    }
    return A;
}

int main() {
    vector<vector<int> > A;
    
    vector<int> r1;
    r1.push_back(1);
    r1.push_back(1);
    r1.push_back(0);
    vector<int> r2;
    r2.push_back(1);
    r2.push_back(0);
    r2.push_back(1);
    vector<int> r3(3, 0);
    
    A.push_back(r1);
    A.push_back(r2);
    A.push_back(r3);
    Solution* sol = new Solution();
    vector<vector<int> > output = sol->flipAndInvertImage(A);
    delete sol;

    Utility::printVector(output[0]);
    Utility::printVector(output[1]);
    Utility::printVector(output[2]);

    return 0;
}