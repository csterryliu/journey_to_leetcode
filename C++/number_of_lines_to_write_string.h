#include <vector>
#include <string>

#define getIndexOfLetter(ch) (ch - 'a')
#define MAX_UNIT_PER_LINE 100

using namespace std;

class Solution {
public:
    Solution() {}
    vector<int> numberOfLines(vector<int>& width, string S);
};