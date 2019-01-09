#include <unordered_map>
using namespace std;

class Solution {
public:
    Solution() {}
    int fib(int N);
    int fibMemorization(int N);
    int fibTabulation(int N);
    unordered_map<int, int> table;
};