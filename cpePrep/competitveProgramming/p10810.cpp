#include <iostream>
#include <vector>

using namespace std;

long long mergeAndCount(vector<int> &arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    vector<int> left(n1);
    vector<int> right(n2);

    // Copy data to temp arrays left[] and right[]
    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    long long swaps = 0;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            swaps += (n1 - i);
        }
    }

    // Copy the remaining elemetns of left[], if there are any
    while (i < n1)
        arr[k++] = left[i++];
    // Do the same for right[]
    while (j < n2)
        arr[k++] = right[j++];

    return swaps;
}

long long mergeSortAndCount(vector<int> &arr, int l, int r) {
    long long count = 0;
    if (l < r) {
        int m = l + (r - l) / 2;

        // Count inversions in the left half
        count += mergeSortAndCount(arr, l, m);

        // Count inversions in the right half
        count += mergeSortAndCount(arr, m + 1, r);

        // Count split inversions
        count += mergeAndCount(arr, l, m, r);
    }
    return count;
}

int main() {
    int n;
    while(cin >> n && n > 0) {
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << mergeSortAndCount(arr, 0, n - 1) << endl;
    }
    return 0;
}
