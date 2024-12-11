#include <iostream>
#include <vector>
#include <cstdio>

int main() {
    int n;

    // Read input until the case where n = 0
    while(scanf("%d", &n), n != 0) {
        std::vector<int> ages(n);
        int count[100] = {0}; // Array to store the count of each age from 1 to 99

        // Read the ages
        for (int i = 0; i < n; ++i) {
            scanf("%d", &ages[i]);
            ++count[ages[i]];   // Count the occurence of each age
        }

        // Output the sorted ages
        bool first = true;
        for(int age = 1; age <= 99; ++age) {
            while(count[age]--) {
                if (!first) printf(" ");
                printf("%d", age);
                first = false;
            }
        }
        printf("\n");
    }

    return 0;
}