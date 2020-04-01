//This solution was written by Kevin Robb.

#include <string>
#include <iostream>

using namespace std;
int main() {
    string input_string;
    getline(cin, input_string);

    for (char const &c: input_string) {
        if (c == 'a') {
            cout << 'A';
        } else if (c == 'e') {
            cout << 'E';
        } else if (c == 'i') {
            cout << 'I';
        } else if (c == 'o') {
            cout << 'O';
        } else if (c == 'u') {
            cout << 'U';
        } else {
            cout << c;
        }
	}

    return 0;
}