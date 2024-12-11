#include <iostream>
#include <cstdint>
#include <vector>
#include <iomanip>

// Function to reverse the endianess of a 32-bit integer
int32_t reverseEndian(int32_t value) {
    uint32_t uvalue = static_cast<uint32_t>(value);
    uvalue = (uvalue >> 24) | 
             ((uvalue << 8) & 0x00FF0000) | 
             ((uvalue >> 8) & 0x0000FF00) | 
             (uvalue << 24);
    return static_cast<int32_t>(uvalue);
}

int main() {
    std::vector<int32_t> numbers;
    int32_t number;

    // Read integers from input until EOF
    while (std::cin >> number) {
        numbers.push_back(number);
    }

    // Process each number
    for (const auto& num : numbers) {
        int32_t converted = reverseEndian(num);
        std::cout << num << " converts to " << converted << std::endl;
    }

    return 0;
}
