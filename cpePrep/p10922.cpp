#include <iostream>
#include <string>

using namespace std;

// Function to calculate the sum of digits of a number represented as a string
int sumOfDigits(const string &num) {
    int sum = 0;
    for (char digit : num) {
        sum += digit - '0';  // Convert character to integer
    }
    return sum;
}

int main() {
    string num;
    
    // Continue reading input until the number "0" is encountered
    while (true) {
        cin >> num;

        if (num == "0") {
            break;  // Stop processing if input is "0"
        }

        int degree = 0;
        string current = num;

        // Check if the number is a multiple of 9 by reducing it recursively
        while (true) {
            int sum = sumOfDigits(current);

            if (sum % 9 != 0) {
                cout << num << " is not a multiple of 9." << endl;
                break;
            } else {
                degree++;
                if (sum == 9) {
                    cout << num << " is a multiple of 9 and has 9-degree " << degree << "." << endl;
                    break;
                }
                current = to_string(sum);  // Convert sum back to string for further processing
            }
        }
    }

    return 0;
}
