#include <iostream>
#include <unordered_map>
#include "./utility.h"
#include "./uncommon_words_from_two_sentences.h"

using namespace std;

vector<string> Solution::uncommonFromSentences(string A, string B) {
    vector<string> output;
    // string concat: generally linear in the resulting string length
    // It returns a newly constructed string object
    // count: Constant on average, worst case linear in the size of the container.
    // access or insert: Average case: constant, worst case: linear in size. 
    
    // string length: constant (after c++11)
    // string at: constant
    string merge = A + " " + B;
    unordered_map<string, int> map;
    int start_pos = 0;
    // O(merge.length)
    for (int i = 0; i <= merge.length(); ++i) {
        if (i == merge.length() || merge.at(i) == ' ') {
            // substr: Linear in count.
            string word = merge.substr(start_pos, i - start_pos);
            if (!map.count(word)) {
                map[word] = 1;
            } else {
                map[word] += 1;
            }
            start_pos = i + 1;
        }
    }
    
    // O(map.size())
    for (unordered_map<string, int>::const_iterator iter = map.cbegin(); iter != map.end(); ++iter) {
        if ((*iter).second == 1) {
            output.push_back((*iter).first);
        }
    }

    // total: O(A.length + B.length + map.size)
    return output;
}


int main() {
    string A = "s z z z s";
    string B = "s z ejt";
    Solution* sol = new Solution();
    vector<string> output = sol->uncommonFromSentences(A, B);
    delete sol;
    for (int i = 0; i < output.size(); ++i) {
        cout << output[i] << "\n";
    }
    return 0;
}