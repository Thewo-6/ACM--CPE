#include <iostream>
#include <vector>
using namespace std;

int countSwaps(vector<int>& carriages) {
    int swapCount = 0;
    int n = carriages.size();

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++)
            if(carriages[j] > carriages[j + 1]) {
                swap(carriages[j], carriages[j + 1]);
                swapCount++;
            }
    }
    return swapCount;
}

int main() {
    int N;
    cin >> N; // Number of test cases

    while(N--) {
        int L;
        cin >> L;
        vector<int> carriages(L);

        for(int i = 0; i < L; i++) {
            cin >> carriages[i];
        }

        int result = countSwaps(carriages);
        cout << "Optimal train swapping takes " << result << " swaps." << endl;

    }

    return 0;
}