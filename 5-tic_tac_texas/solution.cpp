//This solution was written by Kevin Robb.

#include <string>
#include <iostream>
#include <cmath>

using namespace std;
int main() {
    // construct grid as 2D char array from input
    char grid[3][3];
    for (int i=0; i<3; i++) {
        string line;
        getline(cin, line);
        int j = 0;
        for (char const &c: line) {
            grid[i][j] = c;
            j++;
        }
    }

    // check if there is a row, column, or diagonal with 2 o's and 1 -
    bool sooners_win = false;
    // stop checking once we find one win
    // check rows
    for (int i=0; i<3 && sooners_win == false; i++) {
        int o_in_row = 0;
        int empty_in_row = 0;
        for (int j=0; j<3 && sooners_win == false; j++) {
            if (grid[i][j] == 'o') {
                o_in_row++;
            } else if (grid[i][j] == '-') {
                empty_in_row++;
            }
            if (o_in_row == 2 && empty_in_row == 1) {
                sooners_win = true;
            }
        }
    }
    // check columns
    for (int j=0; j<3 && sooners_win == false; j++) {
        int o_in_col = 0;
        int empty_in_col = 0;
        for (int i=0; i<3 && sooners_win == false; i++) {
            if (grid[i][j] == 'o') {
                o_in_col++;
            } else if (grid[i][j] == '-') {
                empty_in_col++;
            }
            if (o_in_col == 2 && empty_in_col == 1) {
                sooners_win = true;
            }
        }
    }
    // check main diagonal
    if (sooners_win == false) {
        // check for o's
        int o_in_diag = 0;
        if (grid[0][0] == 'o') { o_in_diag++;}
        if (grid[1][1] == 'o') { o_in_diag++;}
        if (grid[2][2] == 'o') { o_in_diag++;}
        // check for -'s    
        int empty_in_diag = 0;
        if (grid[0][0] == '-') { empty_in_diag++;}
        if (grid[1][1] == '-') { empty_in_diag++;}
        if (grid[2][2] == '-') { empty_in_diag++;}
        if (o_in_diag == 2 && empty_in_diag == 1) {
            sooners_win = true;
        }
    }
    // check other diagonal
    if (sooners_win == false) {
        // check for o's
        int o_in_diag = 0;
        if (grid[0][2] == 'o') { o_in_diag++;}
        if (grid[1][1] == 'o') { o_in_diag++;}
        if (grid[2][0] == 'o') { o_in_diag++;}
        // check for -'s    
        int empty_in_diag = 0;
        if (grid[0][2] == '-') { empty_in_diag++;}
        if (grid[1][1] == '-') { empty_in_diag++;}
        if (grid[2][0] == '-') { empty_in_diag++;}
        if (o_in_diag == 2 && empty_in_diag == 1) {
            sooners_win = true;
        }
    }

    // output the result
    if (sooners_win) {
        cout << "Sooners Win!";
    } else {
        cout << "Texas Cheated";
    }

    return 0;
}