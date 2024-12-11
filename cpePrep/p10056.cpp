#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int S; // number of test cases
    cin >> S;

    while (S--) {
        int N, I;  // N = number of players, I = the player whose probability is to be determined
        double p;  // p = probability of success in a single throw
        cin >> N >> p >> I;

        double result;

        if (p > 0) {
            // Calculate the probability using the formula
            result = (p * pow(1 - p, I - 1)) / (1 - pow(1 - p, N));
        } else {
            // If p is zero (unlikely in the problem), the result is zero
            result = 0.0;
        }

        // Output result with 4 decimal places
        cout << fixed << setprecision(4) << result << endl;
    }

    return 0;
}
