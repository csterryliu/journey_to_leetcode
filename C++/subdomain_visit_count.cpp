#include <iostream>
#include <unordered_map>
#include "./subdomain_visit_count.h"

using namespace std;

vector<string> Solution::subdomainVisits(vector<string>& cpdomains){
    vector<string> output;
    unordered_map<string, int> map;  // find: O(1) on average case. O(N) on worst case
    for (vector<string>::const_iterator iter = cpdomains.cbegin(); iter != cpdomains.cend(); ++iter) {
        int begin_index = (*iter).find(' '); // find: Constant on average, worst case linear in the size of the container. 
        int visits = stoi(*iter); // stoi: Unspecified, but generally linear in the number of characters interpreted.
        // substr: Linear in count.
        // This function takes two values pos and len as an argument and returns a newly constructed string object with its value initialized to a copy of a sub-string of this object.
        string this_level = (*iter).substr(begin_index+1);
        while (true) {
            if (!map.count(this_level)) {  // count: Constant on average, worst case linear in the size of the container.
                map[this_level] = visits;  // access or insert: Average case: constant, worst case: linear in size. 
            } else {
                map[this_level] += visits;
            }
            begin_index = this_level.find('.');
            if (begin_index == string::npos) break;
            this_level = this_level.substr(begin_index+1);
        }
    }
    for (unordered_map<string, int>::const_iterator iter = map.cbegin(); iter != map.cend(); ++iter) {
        // string concatenation:
        // Unspecified, but generally linear in the resulting string length (and linear in the length of the non-moved argument for signatures with rvalue references).
        // It returns a newly constructed string object

        // to_string: ?? maybe O(N)??
        string ans = to_string((*iter).second) + " " + (*iter).first;
        cout << ans << "\n";
        output.push_back(ans);  // constant time (amortize)
    }
    
    return output;
}

int main() {
    vector<string> cpdoamins;
    cpdoamins.push_back("900 google.mail.com");
    cpdoamins.push_back("50 yahoo.com");
    cpdoamins.push_back("1 intel.mail.com");
    cpdoamins.push_back("5 wiki.org");
    Solution* sol = new Solution();
    vector<string> output = sol->subdomainVisits(cpdoamins);
    delete sol;

    return 0;
}