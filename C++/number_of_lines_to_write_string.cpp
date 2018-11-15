#include <iostream>
#include "./utility.h"
#include "./number_of_lines_to_write_string.h"

using namespace std;

vector<int> Solution::numberOfLines(vector<int>& width, string S) {
    vector<int> output;
    int current_unit = 0;
    int total_lines = 1;
    string::const_iterator iter;
    // O(s.length())
    for (iter = S.begin(); iter != S.end(); ++iter) {
        int this_width = width[getIndexOfLetter(*iter)];
        if (current_unit + this_width > MAX_UNIT_PER_LINE) {
            total_lines++;
            current_unit = this_width;
        } else {
            current_unit += this_width;
        }
    }
    
    output.push_back(total_lines);
    output.push_back(current_unit);
    
    return output;
}

int main() {
    vector<int> width;
    width.push_back(4);
    for (int i = 0; i < 25; ++i) {
        width.push_back(10);
    }
    string S = "bbbcccdddaaa";
    Solution* sol = new Solution();
    vector<int> output = sol->numberOfLines(width, S);
    delete sol;

    Utility::printVector(output);

    return 0;
}