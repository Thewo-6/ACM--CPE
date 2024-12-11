#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

// Structure to store letter and frequency
struct LetterFrequency {
    char letter;
    int frequency;
};

// Comparator function to sort based on frequency and alphabetically
bool compare(LetterFrequency a, LetterFrequency b) {
    if (a.frequency == b.frequency)
        return a.letter < b.letter;
    return a.frequency > b.frequency;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // To ignore the newline after the integer input
    
    vector<int> freq(26, 0); // Frequency array for each letter (A-Z)

    // Reading input and calculating frequencies
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        
        // Analyze each character in the line
        for (char c : line) {
            if (isalpha(c)) { // Check if the character is a letter
                c = toupper(c); // Convert to uppercase
                freq[c - 'A']++; // Increment the frequency for this letter
            }
        }
    }

    // Create a vector of LetterFrequency to store results
    vector<LetterFrequency> result;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > 0) {
            result.push_back({char('A' + i), freq[i]});
        }
    }

    // Sort the result based on frequency and alphabetically if frequencies are the same
    sort(result.begin(), result.end(), compare);

    // Print the result
    for (auto lf : result) {
        cout << lf.letter << " " << lf.frequency << endl;
    }

    return 0;
}