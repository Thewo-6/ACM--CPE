#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

// Function to calculate the cost of printing a number in a particular base
int calculateCost(long long num, int base, const vector<int>& cost) {
    int totalCost = 0;
    if (num == 0) {
        return cost[0]; // Cost of printing 0
    }
    while (num > 0) {
        totalCost += cost[num % base];
        num /= base;
    }
    return totalCost;
}

int main() {
    int testCases;
    cin >> testCases;

    for (int t = 1; t <= testCases; t++) {
        // Read character costs
        vector<int> cost(36);
        for (int i = 0; i < 36; i++) {
            cin >> cost[i];
        }

        int queries;
        cin >> queries;

        cout << "Case " << t << ":\n";
        for (int q = 0; q < queries; q++) {
            long long number;
            cin >> number;

            // Find the cheapest base(s)
            int minCost = INT_MAX;
            vector<int> cheapestBases;

            for (int base = 2; base <= 36; base++) {
                int currentCost = calculateCost(number, base, cost);
                if (currentCost < minCost) {
                    minCost = currentCost;
                    cheapestBases.clear();
                    cheapestBases.push_back(base);
                } else if (currentCost == minCost) {
                    cheapestBases.push_back(base);
                }
            }

            // Output the result
            cout << "Cheapest base(s) for number " << number << ":";
            for (int base : cheapestBases) {
                cout << " " << base;
            }
            cout << "\n";
        }
        if (t != testCases) {
            cout << "\n";
        }
    }

    return 0;
}
