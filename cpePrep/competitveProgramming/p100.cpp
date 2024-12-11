// Collatz conjecture or 3n + 1

#include <iostream>
#include <algorithm>

int cycle_length(long long n) {
    int length = 1;
    while (n != 1) {
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;
        length++;
    }
    return length;
}

int max_cycle_length(long long i, long long j) {
    int max_length = 0;
    for (long long num = std::min(i, j); num <= std::max(i, j); ++num) {
        int curr_length = cycle_length(num);
        if (curr_length > max_length)
            max_length = curr_length;
    }
    return max_length;
}

int main() {
    long long i, j;
    while (std::cin >> i >> j) {
        std::cout << i << " " << j << " " << max_cycle_length(i, j) << std::endl;
    }
    return 0;
}