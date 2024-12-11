#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers(5);
    numbers.push_back(4);
    numbers.push_back(2);
    numbers.push_back(1);
    for(int it = 0; it < numbers.size(); ++it) {
        std::cout << numbers.at(it) << " ";
    }

    return 0;
}