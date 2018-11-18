#include <iostream>
#include "./utility.h"
#include "./shortest_distance_to_a_char.h"

using namespace std;

vector<int> Solution::shortestToChar(string S, char C) {
    vector<int> output;
    // if we don't divided by 2, the value will become positive
    int prev_index_of_c = INT_MIN / 2 ;
    // do not forget: O(N + N) => O(2N) => O(N)
    for (int i = 0; i < S.size(); ++i) {
        if (S[i] == C) {
            prev_index_of_c = i;
        }
        output.push_back(i - prev_index_of_c);
    }
    prev_index_of_c = INT_MAX;
    for (int i = S.size()-1; i >= 0; --i) {
        if (S[i] == C) {
            prev_index_of_c = i;
        }
        output[i] = min(output[i], prev_index_of_c - i);
    }
    return output;
}

vector<int> Solution::shortestToCharFaster(string S, char C) {
    vector<int> output;
    vector<int> positions_of_c;
    for (int i = 0; i < S.length(); ++i) {
        output.push_back(0);
        if (S[i] == C) {
            positions_of_c.push_back(i);
        }
    }
    for (int i = 0; i < S.length(); ++i) {
        int temp = S.length();
        for (int j = 0; j < positions_of_c.size(); ++j) {
            if (abs(i - positions_of_c.at(j)) < temp) {
                temp = abs(i - positions_of_c.at(j));
            }
        }
        // note: the performance of operator[] and at() is different
        // at() is faster than operator[]
        // although they are basically constant time
        
        // at() offers bounds checking while operator[] doen't
        output.at(i) = temp;
    }
    return output;
}


int main() {
    string input = "loveleetcode";
    Solution* sol = new Solution();
    vector<int> output = sol->shortestToChar(input, 'e');
    delete sol;
    Utility::printVector(output);
    return 0;
}