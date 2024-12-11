#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Convert character to its numeric value based on its position in the base
int charValue(char c) {
    if (isdigit(c)) {
        return c - '0';       // For digits '0' to '9'
    } else if (isupper(c)) {
        return c - 'A' + 10;  // For uppercase letters 'A' to 'Z'
    } else {
        return c - 'a' + 36;  // For lowercase letters 'a' to 'z'
    }
}

// Function to check if the number is valid in the given base and divisible by (base - 1)
bool isValidBase(const string& number, int base) {
    long long mod = 0;
    for (char c : number) {
        if (c == '-' || c == '+') continue; // Skip signs
        int digit = charValue(c);
        if (digit >= base) return false;    // Invalid digit for the current base

        // Perform the modular arithmetic digit by digit
        mod = (mod * base + digit) % (base - 1);
    }
    return mod == 0;  // Check if divisible by (base - 1)
}

// Function to find the smallest base for which the number is valid and divisible by (base - 1)
int findSmallestBase(const string& number) {
    // Handle special case where the number is 0
    if (number == "0") return 2;  // Smallest base for 0 is base 2

    int maxDigit = 0;
    for (char c : number) {
        if (c == '-' || c == '+') continue;  // Skip signs
        maxDigit = max(maxDigit, charValue(c));  // Find the maximum digit in the number
    }

    // Start checking from the smallest possible base
    for (int base = maxDigit + 1; base <= 62; ++base) {
        if (isValidBase(number, base)) {
            return base;  // Return the smallest valid base
        }
    }
    return -1;  // No valid base found
}

int main() {
    string number;
    while (cin >> number) {
        int base = findSmallestBase(number);
        if (base == -1) {
            cout << "such number is impossible!" << endl;
        } else {
            cout << base << endl;
        }
    }
    return 0;
}
