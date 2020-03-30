//This solution was written by Kevin Robb.

#include <string>
#include <iostream>
#include <cmath>

using namespace std;
int main() {
    int N, M;
    // N = total number of days in semester, max 80
    cin >> N;
    // M = number of days so far, less than N
    cin >> M;

    double percent = (double) M / (double) N;
    int num_pounds = (int) floor((percent * 20));
    
    cout << '[';

    for (int i=0; i<20; i++) {
        if (i < num_pounds) {
            cout << '#';
        } else {
            cout << '-';
        }
    }

    cout << "]";

    return 0;
}