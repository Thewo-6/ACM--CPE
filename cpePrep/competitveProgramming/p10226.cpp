#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int t;
    string line;

    // Read the number of test cases
    cin >> t;
    getline(cin, line); // To consume the newline after t

    // Blank line after number of test cases
    getline(cin, line);

    while(t--) {
        map<string, int> speciesCount;
        int totalTrees = 0;

        // Read until a blank line or end of input
        while(getline(cin, line) && !line.empty()) {
            speciesCount[line]++;
            totalTrees++;
        }

        // Output species and percentage directly from the map
        for(const auto& entry : speciesCount) {
            double percentage = (entry.second * 100.0) / totalTrees;
            cout << entry.first << " " << fixed << setprecision(4) << percentage << endl;
        }

        // Print a blank line between test cases
        if (t > 0) {
            cout << endl;
        }
    }
    return 0;
}