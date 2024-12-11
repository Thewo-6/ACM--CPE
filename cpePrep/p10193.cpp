#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

// Function to convert a binary string to an integer
long long binaryToDecimal(const string& binaryStr) {
    return bitset<30>(binaryStr).to_ullong(); // Convert binary string to unsigned long long
}

// Function to compute the greatest common divisor (GCD)
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int N;
    cin >> N; // Number of test cases

    for (int i = 1; i <= N; ++i) {
        string S1, S2;
        cin >> S1 >> S2;

        long long num1 = binaryToDecimal(S1); // Convert binary string S1 to decimal
        long long num2 = binaryToDecimal(S2); // Convert binary string S2 to decimal

        // Find GCD of the two numbers
        if (gcd(num1, num2) > 1) {
            cout << "Pair #" << i << ": All you need is love!" << endl;
        } else {
            cout << "Pair #" << i << ": Love is not all you need!" << endl;
        }
    }

    return 0;
}
