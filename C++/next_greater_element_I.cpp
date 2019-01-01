#include <iostream>
#include <unordered_map>
#include "./next_greater_element_I.h"

using namespace std;

vector<int> Solution::nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    vector<int> output;
    unordered_map<int, int> map;
    vector<int>::const_iterator iter;
    int pos_in_nums;
    for (iter = findNums.cbegin(); iter != findNums.cend(); ++iter) {
        pos_in_nums = 0;
        if (map.count(*iter) == 1) {
            pos_in_nums = map[*iter];
        } else {
            for (int i = 0; i < nums.size(); ++i) {
                if (map.count(nums.at(i)) == 0) {
                    map[nums.at(i)] = i;
                }
                if (*iter == nums.at(i)) {
                    pos_in_nums = i;
                    break;
                }
            }
        }
        while (pos_in_nums < nums.size()-1) {
            if (nums.at(pos_in_nums+1) > *iter) {
                output.push_back(nums.at(pos_in_nums+1));
                break;
            }
            pos_in_nums++;
        }
        if (pos_in_nums == nums.size()-1) {
            output.push_back(-1);
        }
    }
    return output;
}

int main() {
    vector<int> A;
    A.push_back(2);
    A.push_back(4);
    //A.push_back(2);
    vector<int> B;
    B.push_back(1);
    B.push_back(2);
    B.push_back(3);
    B.push_back(4);
    Solution* sol = new Solution();
    vector<int> output = sol->nextGreaterElement(A, B);
    delete sol;

    for (vector<int>::iterator iter = output.begin(); iter != output.end(); iter++) {
        cout << *iter << " ";
    }
    cout << "\n";

    return 0;
}