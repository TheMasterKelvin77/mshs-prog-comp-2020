//This solution was written by Kevin Robb.

#include <string>
#include <iostream>

using namespace std;

char grid[10][10];
char new_grid[10][10];

int find_num_neighbors(int r, int c) {
    // given row and column index for a specific cell.
    // determine the number of alive cells there are in the 8 neighbor cells.
    int num_alive_neighbors = 0;
    // check all 8 neighbors and ignore out of bounds.
    if (r!=0 && c!=0 && grid[r-1][c-1] == '1') {num_alive_neighbors += 1;}
    if (r!=0 && grid[r-1][c] == '1') {num_alive_neighbors += 1;}
    if (r!=0 && c!=9 && grid[r-1][c+1] == '1') {num_alive_neighbors += 1;}
    if (c!=0 && grid[r][c-1] == '1') {num_alive_neighbors += 1;}
    if (c!=9 && grid[r][c+1] == '1') {num_alive_neighbors += 1;}
    if (r!=9 && c!=0 && grid[r+1][c-1] == '1') {num_alive_neighbors += 1;}
    if (r!=9 && grid[r+1][c] == '1') {num_alive_neighbors += 1;}
    if (r!=9 && c!=9 && grid[r+1][c+1] == '1') {num_alive_neighbors += 1;}
    
    return num_alive_neighbors;
}

int main() {
    // turn the input into a 2D char array, "grid"
    string input_string;
    for (int i=0; i<10; i++) {
        getline(cin, input_string);
        int col = 0;
        for (char const &c: input_string) {
            grid[i][col] = c;
            col++;
        }
    }
    // go through each cell and determine what it's next state will be
    for (int r=0; r<10; r++) {
        for (int c=0; c<10; c++) {
            if (grid[r][c] == '1' && (find_num_neighbors(r,c) == 2 || find_num_neighbors(r,c) == 3)) {
                // alive cell w/ 2 or 3 alive neighbors continues to be alive
                new_grid[r][c] = '1';
            } else if (grid[r][c] == '0' && find_num_neighbors(r,c) == 3) {
                // dead cell w/ 3 alive neighbors becomes alive
                new_grid[r][c] = '1';
            } else {
                // any other cells become dead
                new_grid[r][c] = '0';
            }
        }
    }
    // output new_grid
    for (int r=0; r<10; r++) {
        for (int c=0; c<10; c++) {
            cout << new_grid[r][c];
        }
        cout << "\n";
    }

    return 0;
}