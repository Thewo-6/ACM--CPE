#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;
    
    // Read input line by line
    while (getline(cin, line)) {
        bool insideQuotes = false;

        // Iterate over each character in the line
        for (char& c : line) {
            if (c == '"') {
                if (insideQuotes) {
                    // Replace closing quote with ''
                    cout << "''";
                } else {
                    // Replace opening quote with ``
                    cout << "``";
                }
                insideQuotes = !insideQuotes; // Toggle the insideQuotes flag
            } else {
                cout << c; // Output character as is
            }
        }
        cout << endl; // Output newline at the end of each line
    }

    return 0;
}
