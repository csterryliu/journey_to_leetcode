#include <iostream>
#include <unordered_map>
#include <stack>
#include "./next_greater_element_I.h"

using namespace std;

vector<int> Solution::nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    vector<int> output;
    unordered_map<int, int> map;
    vector<int>::const_iterator iter;
    int pos_in_nums;
    // O(n1 * (n2 + n2))  => O(n1*n2)
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

vector<int> Solution::nextGreaterElementMapAndStack(vector<int>& findNums, vector<int>& nums) {
    stack<int> pos_stack;
    unordered_map<int, int> nextg_map;
    // O(n2 * pos_stack.size())
    for (int i = 0; i < nums.size(); ++i) {
        while(!pos_stack.empty() && nums[i] > nums[pos_stack.top()]) {
            nextg_map[nums[pos_stack.top()]] = nums[i];
            pos_stack.pop();
        }
        pos_stack.push(i);
    }
    // O(pos_stack.size())
    while (!pos_stack.empty()) {
        nextg_map[nums[pos_stack.top()]] = -1;
        pos_stack.pop();
    }
    // O(n1)
    for (int i = 0; i < findNums.size(); ++i) {
        findNums[i] = nextg_map[findNums[i]];
    }
    // O(n2 * pos_stack.size() + pos_stack.size() + n1)
    return findNums;
}

int main() {
    vector<int> A;
    A.push_back(4);
    A.push_back(1);
    A.push_back(2);
    vector<int> B;
    B.push_back(1);
    B.push_back(3);
    B.push_back(4);
    B.push_back(2);
    Solution* sol = new Solution();
    vector<int> output = sol->nextGreaterElementMapAndStack(A, B);
    delete sol;

    for (vector<int>::iterator iter = output.begin(); iter != output.end(); iter++) {
        cout << *iter << " ";
    }
    cout << "\n";

    return 0;
}