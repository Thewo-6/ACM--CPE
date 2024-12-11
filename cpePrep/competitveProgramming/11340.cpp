#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <sstream>

int main() {
    int N;
    std::cin >> N;

    while (N--) {
        int K;
        std::cin >> K;

        std::unordered_map<char, int> char_values;

        for (int i = 0; i < K; ++i) {
            char c;
            int value;
            std::cin >> c >> value;
            char_values[c] = value;
        }

        int M;
        std::cin >> M;
        std::cin.ignore();

        long long total_payment = 0;
        for (int i = 0; i < M; ++i) {
            std::string line;
            std::getline(std::cin, line);

            for(char c : line) {
                if (char_values.find(c) != char_values.end()) {
                    total_payment += char_values[c];
                }
            }
        }

        std::ostringstream result;
        result << std::fixed << std::setprecision(2) << (total_payment / 100.0) << "$";
        std::cout << result.str() << std::endl;
    }

    return 0;
}