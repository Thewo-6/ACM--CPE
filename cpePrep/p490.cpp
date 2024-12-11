#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::string> sentences;
    std::string line;
    
    // Reading input sentences
    while (std::getline(std::cin, line)) {
        sentences.push_back(line);
    }
    
    // Find the longest sentence length
    int max_length = 0;
    for (const std::string& sentence : sentences) {
        if (sentence.length() > max_length) {
            max_length = sentence.length();
        }
    }

    // Rotate the sentences 90 degrees clockwise
    for (int col = 0; col < max_length; ++col) {
        for (int row = sentences.size() - 1; row >= 0; --row) {
            if (col < sentences[row].length()) {
                std::cout << sentences[row][col];
            } else {
                std::cout << ' '; // Fill in the spaces for shorter sentences
            }
        }
        std::cout << '\n';
    }

    return 0;
}
