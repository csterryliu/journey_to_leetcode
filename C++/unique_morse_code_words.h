#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
    string turn_into_morse(string str);
public:
    Solution() { }
    int uniqueMorseRepresentations(vector<string>& words);
};