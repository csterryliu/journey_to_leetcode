#include <iostream>
#include "./island_perimeter.h"
#include "./utility.h"

using namespace std;

int Solution::islandPerimeter(vector<vector<int> >& grid) {
    int perimiter = 0;
    // O(row*col)
    for (int row = 0; row < grid.size(); ++row) {
        for (int col = 0; col < grid.at(row).size(); ++col) {
            if (grid.at(row).at(col) == 1) {
                // left
                if (col == 0 || grid.at(row).at(col-1) == 0) perimiter++;
                // top
                if (row == 0 || grid.at(row-1).at(col) == 0) perimiter++;
                // right
                if (col == grid.at(row).size()-1 || grid.at(row).at(col+1) == 0) perimiter++;
                // buttom
                if (row == grid.size()-1 || grid.at(row+1).at(col) == 0) perimiter++;
            }
        }
    }
    return perimiter;
}

int main() {
    vector<vector<int> > grid;
    vector<int> r1;
    r1.push_back(0);
    r1.push_back(1);
    r1.push_back(0);
    r1.push_back(0);
    vector<int> r2;
    r2.push_back(1);
    r2.push_back(1);
    r2.push_back(1);
    r2.push_back(0);
    vector<int> r3;
    r3.push_back(0);
    r3.push_back(1);
    r3.push_back(0);
    r3.push_back(0);
    vector<int> r4;
    r4.push_back(1);
    r4.push_back(1);
    r4.push_back(0);
    r4.push_back(0);
    grid.push_back(r1);
    grid.push_back(r2);
    grid.push_back(r3);
    grid.push_back(r4);
    Utility::printVector(grid[0]);
    Utility::printVector(grid[1]);
    Utility::printVector(grid[2]);
    Utility::printVector(grid[3]);
    
    Solution* sol = new Solution();
    int output = sol->islandPerimeter(grid);
    delete sol;

    cout << output << "\n";

    return 0;
}