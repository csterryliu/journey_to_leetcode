#include <iostream>
#include "./robot_return_to_origin.h"

using namespace std;

bool Solution::judgeCircle(string moves) {
    Cordinate c;
    // O(moves.length())
    for (int i = 0; i < moves.length(); ++i) {
        switch (moves[i]) {
            case 'D':
                movedown(c);
                break;
            case 'U':
                moveup(c);
                break;
            case 'L':
                moveleft(c);
                break;
            case 'R':
                moveright(c);
                break;
            default:
                cout << "unknown move\n";
                return false;
        }
    }
    if (c.x == 0 && c.y == 0) return true;
    return false;
}

int main() {
    string s = "UD";

    Solution* sol = new Solution();
    bool output = sol->judgeCircle(s);
    delete sol;

    cout << output << "\n";

    return 0;
}