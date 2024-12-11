#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to hold the frequency and ASCII value of a character
struct CharFreq {
    char ch;
    int freq;
};

// Comparator to sort first by frequency and then by ASCII value (descending if frequencies are equal)
bool compare(const CharFreq &a, const CharFreq &b) {
    if (a.freq == b.freq) {
        return a.ch > b.ch;  // If frequencies are the same, sort by ASCII value (descending)
    }
    return a.freq < b.freq;  // Sort by frequency (ascending)
}

int main() {
    string line;
    bool first = true;  // To handle the blank line between outputs

    // Continue reading lines until EOF
    while (getline(cin, line)) {
        if (!first) {
            cout << endl;  // Print a blank line between each output
        }
        first = false;

        // Create a map to count the frequency of each character
        map<char, int> freqMap;
        for (char ch : line) {
            freqMap[ch]++;
        }

        // Store the characters and their frequencies in a vector
        vector<CharFreq> freqVec;
        for (auto &entry : freqMap) {
            freqVec.push_back({entry.first, entry.second});
        }

        // Sort the vector by frequency and ASCII value
        sort(freqVec.begin(), freqVec.end(), compare);

        // Output the results
        for (auto &entry : freqVec) {
            cout << (int)entry.ch << " " << entry.freq << endl;
        }
    }

    return 0;
}