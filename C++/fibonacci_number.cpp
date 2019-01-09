#include <iostream>
#include "./fibonacci_number.h"

using namespace std;

int Solution::fib(int N) {
    // this method is very slow
    // O(2^n)
    if (N == 0) return 0;
    if (N == 1) return 1;
    return fib(N-1) + fib(N-2);
}

// Use dynamic programming will provide better performance

// state: fib(n)
// It stands for the fibonacci number of a given n

// It has overlapping subproblems:
// fib(5) = fib(4) + fib(3)
// fib(4) = fib(3) + fib(2)
// It also has optimal substurcture property. It combines the results of the subproblems

// memorization (top-down)
// O(n). All values are only calculated for once.
int Solution::fibMemorization(int N) {
    // If the data is in the table, just use it and don't calculate it again!
    if (table.count(N) > 0) return table[N];
    if (N == 0) return 0;
    if (N == 1) return 1;
    // Otherwise, calculate the result and memorize it in the table
    table[N] = fib(N-1) + fib(N-2);
    return table[N];
}

// tabulation (buttom-up)
// Usually it would be iteration. Because we have to make the table during each calculation, from buttom to top.
// O(n)
int Solution::fibTabulation(int N) {
    for (int i = 0; i <= N; ++i ) {
        if (i == 0) {
            table[i] = 0;
        } else if (i == 1) {
            table[i] = 1;
        } else {
            table[i] = table[i-1] + table[i-2];
        }
    }
    return table[N];
}

int main() {
    Solution* sol = new Solution();
    cout << sol->fib(4) << "\n";
    delete sol;

    return 0;
}