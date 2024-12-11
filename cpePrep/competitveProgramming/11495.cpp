#include <iostream>
#include <vector>

using namespace std;

// Function to merge two halves and count inversions
int mergeAndCount(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left;   // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = left;   // Starting index to be sorted
    int inv_count = 0;

    while((i <= mid) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid + 1) - i; // Number of inversions
        }
    }

    // copy the remaining elements of left subarray, if any
    while(i <= mid)
        temp[k++] = arr[i++];

    // remainig elements of right ...
    while(j <= right)
        temp[k++] = arr[j++];

    // Copy the sorted subarray into the original array
    for(i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

// Function to count inversions using merge sort
int mergeSortAndCount(vector<int>& arr, vector<int>& temp, int left, int right) {
    int mid, inv_count = 0;
    if(right > left) {
        mid = (right + left) / 2;

        inv_count += mergeSortAndCount(arr, temp, left, mid);
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right);

        inv_count += mergeAndCount(arr, temp, left, mid, right);
    }
    return inv_count;
}

int main() {
    int N;

    while (cin >> N && N != 0) {
        vector<int> P(N);
        vector<int> temp(N);

        for (int i = 0; i < N; i++) {
            cin >> P[i];
        }

        int inversions = mergeSortAndCount(P, temp, 0, N - 1);

        if(inversions % 2 == 0) {
            cout << "Carlos" << endl;
        } else {
            cout << "Marcelo" << endl;
        }
    }

    return 0;
}