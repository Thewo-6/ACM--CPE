#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n;
    while (cin >> n && n != 0) {
        // Calculate the square root of n
        long long root = static_cast<long long>(sqrt(n));
        // Check if n is a perfect square
        if (root * root == n) {
            cout << "yes" << endl; // Light is on
        } else {
            cout << "no" << endl; // Light is off
        }
    }
    return 0;
}