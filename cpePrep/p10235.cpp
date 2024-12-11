#include <iostream>
#include <cmath>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;  // Numbers less than or equal to 1 are not prime
    if (n == 2 || n == 3) return true;  // 2 and 3 are prime
    if (n % 2 == 0 || n % 3 == 0) return false;  // Divisible by 2 or 3 means not prime
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)  // Check divisibility by other numbers
            return false;
    }
    return true;  // If no divisors are found, it's prime
}

// Function to reverse the digits of a number
int reverseNumber(int n) {
    int reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

int main() {
    int N;
    while (cin >> N) {
        if (!isPrime(N)) {
            // If N is not prime, print "not prime"
            cout << N << " is not prime." << endl;
        } else {
            int reversedN = reverseNumber(N);
            if (N != reversedN && isPrime(reversedN)) {
                // If both N and reversedN are prime and they are different, it's emirp
                cout << N << " is emirp." << endl;
            } else {
                // If N is prime but reversedN is either not prime or they are the same, print "prime"
                cout << N << " is prime." << endl;
            }
        }
    }
    return 0;
}
