//This solution was written by Kevin Robb.

#include <string>
#include <iostream>

using namespace std;

string possible_chars = "IVXLCDM";
int values[] = {1, 5, 10, 50, 100, 500, 1000};

int convert_to_int(string roman_num) {
    // first make an array of int values corresponding to the given roman numeral
    int converted_vals[roman_num.length()];
    int index = 0;
    for (char const &c: roman_num) {
        converted_vals[index] = values[possible_chars.find(c)];
        index++;
	}
    // now iterate through converted_vals and check for out of order sections, keeping a running sum
    int sum = 0;
    for (int i=0; i<roman_num.length(); i++) {
        // if we are at the end, add and break to avoid out of bounds error
        if (i == roman_num.length()-1) {sum+=converted_vals[i]; break;}

        if (converted_vals[i] > converted_vals[i+1]) {
            // numbers are decreasing, so add to sum. 
            sum += converted_vals[i];
        } else if (converted_vals[i] == converted_vals[i+1]) {
            //will not subtract two adjacent numbers, so add to sum
            sum += converted_vals[i];
        } else { 
            //numbers are increasing. subtraction is necessary
            sum -= converted_vals[i];
        }
    }

    return sum;
}

int main() {
    string num_cases_rn;
    getline(cin, num_cases_rn);

    int num_cases = convert_to_int(num_cases_rn);

    for (int i=0; i<num_cases; i++) {
        string input_rn;
        getline(cin, input_rn);
        cout << convert_to_int(input_rn) << "\n";
    }
	
    return 0;
}