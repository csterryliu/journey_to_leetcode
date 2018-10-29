#include <iostream>
#include "./utility.h"


using namespace std;

void Utility::printVector(vector<int>& v) {
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << " ";
    }
    cout << "\n";
}

void Utility::swapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
