#include "backspace_string_compare.h"
#include <iostream>

using namespace std;

// this is not a good way to erase the last char
// the behavior is unknown
// char backsapce = '#';
// stack1.push_back('H');
// stack1.push_back('E');
// *(--(stack1.end())) = '\0';
// stack1.push_back('L');

void Solution::stackChar(string& stack, string& target) {
    char backsapce = '#';
    for (string::const_iterator iter = target.cbegin(); iter != target.cend(); ++iter) {
        if (*iter == backsapce) {
            if (!stack.empty()) {
                stack.erase(stack.end()-1);
                // if you are in C++11, you can use stack.pop_back()
            }
            continue;
        } else {
            stack.push_back(*iter);
        }
    }
}

bool Solution::backspaceCompare(string S, string T) {
    string stack1;
    string stack2;
    // stack1.push_back('H');
    // stack1.push_back('E');
    // stack1.push_back('L');
    // stack1.erase(stack1.end()-1);
    // stack1.erase(stack1.end()-1);
    // stack1.erase(stack1.end()-1);
    // cout << stack1 << endl;

    stackChar(stack1, S);
    cout << stack1 << endl;
    stackChar(stack2, T);
    cout << stack2 << endl;
    return stack1 == stack2;
}

int main() {
    Solution* s = new Solution();
    cout << endl;
    printf("%d\n", s->backspaceCompare("y#fo##f", "y#f#o##f"));
    delete s;
    return 0;
}