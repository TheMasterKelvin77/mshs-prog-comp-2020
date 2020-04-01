//This solution was written by Kevin Robb.

#include <string>
#include <iostream>
#include <cmath>

using namespace std;
int main() {
    double x1, y1, r1, x2, y2, r2;
    cin >> x1;
    cin >> y1;
    cin >> r1;
    cin >> x2;
    cin >> y2;
    cin >> r2;

    // check distance between centers to determine if they overlap
    double min_dist = r1 + r2;
    double actual_dist = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

    if (actual_dist < min_dist) {
        cout << "Unfair Picture";
    } else {
        cout << "Good Picture";
    }

    return 0;
}