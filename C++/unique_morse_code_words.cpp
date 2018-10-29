#include <iostream>
#include <set>
#include "./unique_morse_code_words.h"
#include "./utility.h"

using namespace std;

string Solution::turn_into_morse(string str) {
    const char* morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    string output = "";
    // O(str.length()*O(?))
    for (int i = 0; i < str.length(); i++) {  // O(str.length())
        int idx = static_cast<int>(str[i])-97;  // O(1)
        output += morse[idx];  //O(?)  There are no standard complexity guarantees, typical implementations behave similar to std::vector::insert.
    }
    return output;
}

int Solution::uniqueMorseRepresentations(vector<string>& words) {
    set<string> myset;
    // O(words.size()*(str.length()*O(?) + logn))
    for (vector<string>::const_iterator iter = words.cbegin(); iter != words.cend(); ++iter) {  // O(words.size())
        string morse_str = turn_into_morse(*iter);  // O(str.length()*O(?))
        cout << morse_str << "\n";
        myset.insert(morse_str);  // O(logn)
    }

    return myset.size();
}

int main() {
    vector<string> words;
    words.push_back("gin");
    words.push_back("zen");
    words.push_back("gig");
    words.push_back("msg");

    Solution* sol = new Solution();
    int output = sol->uniqueMorseRepresentations(words);
    delete sol;

    cout << output << "\n";

    return 0;
}