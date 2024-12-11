#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    
    while (cin >> n) {
        if (n == 0) break; // Exit if n is 0 (EOF)

        vector<int> numbers(n);

        // Read the numbers
        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
        }

        // Sort the numbers to find the median
        sort(numbers.begin(), numbers.end());

        // Find the two middle elements (for even `n`, there are two middle elements)
        int median1 = numbers[(n - 1) / 2];  // Median from the lower half
        int median2 = numbers[n / 2];        // Median from the upper half

        // Count how many numbers are equal to median1 (or median2, because they are the same or adjacent)
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (numbers[i] == median1) {
                count++;
            }
        }

        // Calculate how many distinct possible values for `A` exist (range between median1 and median2)
        int distinct_medians = median2 - median1 + 1; // The number of integers between median1 and median2, inclusive

        // Output the result: median1, the count of occurrences of median1, and the distinct values of A
        cout << median1 << " " << count << " " << distinct_medians << endl;
    }

    return 0;
}