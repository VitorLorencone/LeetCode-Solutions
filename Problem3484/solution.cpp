/* 
'n' is the length of the formula string
'm' is the number of cells stored in grid
Time Complexity: O(1) and O(n)
Space Complexity: O(m)
*/

#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
public:
    unordered_map<string, int> grid;
    int rows; 
    int cols;

    Spreadsheet(int rows) {
        this->rows = rows;
        this->cols = 26;
    }
    
    void setCell(string cell, int value) {
        grid[cell] = value;
    }
    
    void resetCell(string cell) {
        grid[cell] = 0;
    }
    
    int getValue(string formula) {
        size_t pos = formula.find('+');
        string X = formula.substr(1, pos-1);
        string Y = formula.substr(pos+1, formula.size());

        int A = getValueToken(X);
        int B = getValueToken(Y);

        return A+B;
    }
private:
    int getValueToken(string token){
        if(isdigit(token[0])) return stoi(token);
        if(grid.find(token) != grid.end()) return grid[token];
        return 0;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */