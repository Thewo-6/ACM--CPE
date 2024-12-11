#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n, m;
    while (cin >> n >> m) {
        vector<long long> sequence;
        bool boring = false;

        // Check if m is valid (greater than 1)
        if (m <= 1 || n < 1) {
            boring = true;
        } else {
            // Generate the sequence by dividing n by m
            while (n > 1) {
                if (n % m != 0) {
                    boring = true;
                    break;
                }
                sequence.push_back(n);
                n /= m;
            }
            sequence.push_back(1); // Add the final 1 to the sequence
        }

        // Output the result
        if (boring) {
            cout << "Boring!" << endl;
        } else {
            for (size_t i = 0; i < sequence.size(); ++i) {
                if (i > 0) cout << " ";
                cout << sequence[i];
            }
            cout << endl;
        }
    }
    return 0;
}
