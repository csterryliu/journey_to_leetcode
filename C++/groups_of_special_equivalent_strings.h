#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    void sortWord(string& s);
    string getCanonical(const string& s);
public:
    Solution() {}
    int numSpecialEquivGroups(vector<string>& A);
    int numSpecialEquivGroupsBetter(vector<string>& A);
};