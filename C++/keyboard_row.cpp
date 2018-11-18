#include <iostream>
#include <unordered_map>
#include "./utility.h"
#include "./keyboard_row.h"

using namespace std;

vector<string> Solution::findWords(vector<string>& words) {
    vector<string> output;
    unordered_map<char, int> map;
    map['q'] = 1;
    map['w'] = 1;
    map['e'] = 1;
    map['r'] = 1;
    map['t'] = 1;
    map['y'] = 1;
    map['u'] = 1;
    map['i'] = 1;
    map['o'] = 1;
    map['p'] = 1;

    map['a'] = 2;
    map['s'] = 2;
    map['d'] = 2;
    map['f'] = 2;
    map['g'] = 2;
    map['h'] = 2;
    map['j'] = 2;
    map['k'] = 2;
    map['l'] = 2;

    map['z'] = 3;
    map['x'] = 3;
    map['c'] = 3;
    map['v'] = 3;
    map['b'] = 3;
    map['n'] = 3;
    map['m'] = 3;

    for (vector<string>::const_iterator iter = words.cbegin(); iter != words.cend(); ++iter) {
        int temp;
        bool is_same_row = true;
        for (int i = 0; i < (*iter).length(); ++i) {
            if (i == 0) {
                temp = map[tolower((*iter).at(i))];
                continue;
            }
            if (temp != map[tolower((*iter).at(i))]) {
                is_same_row = false;
                break;
            } 
        }
        if (is_same_row) {
            output.push_back(*iter);
        }
    }

    return output;
}



int main() {
    vector<string> input;
    input.push_back("Hello");
    input.push_back("Alaska");
    input.push_back("Dad");
    input.push_back("Peace");
    Solution* sol = new Solution();
    vector<string> output = sol->findWords(input);
    delete sol;
    for (int i = 0; i < output.size(); ++i) {
        cout << output[i] << "\n";
    }
    return 0;
}