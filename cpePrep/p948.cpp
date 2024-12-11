#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to generate Fibonacci numbers up to the largest number less than or equal to 100,000,000
vector<int> generateFibonacci() {
    vector<int> fib = {1, 2};
    while (true) {
        int next = fib[fib.size() - 1] + fib[fib.size() - 2];
        if (next > 100000000) break;
        fib.push_back(next);
    }
    return fib;
}

// Function to convert a decimal number to Fibonaccimal base
string toFibonaccimalBase(int num, const vector<int>& fib) {
    string fibBase = "";
    bool started = false;
    for (int i = fib.size() - 1; i >= 0; --i) {
        if (fib[i] <= num) {
            num -= fib[i];
            fibBase += "1";
            started = true;
        } else if (started) {
            fibBase += "0";
        }
    }
    return fibBase;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> numbers(N);
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }
    
    vector<int> fib = generateFibonacci();
    
    // Process each number and print the output in the required format
    for (int i = 0; i < N; ++i) {
        string fibBase = toFibonaccimalBase(numbers[i], fib);
        cout << numbers[i] << " = " << fibBase << " (fib)" << endl;
    }

    return 0;
}
