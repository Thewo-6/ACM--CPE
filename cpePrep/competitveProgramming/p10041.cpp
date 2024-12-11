#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int arr[500];
    int n = 0;
    int r = 0;

    int ntestCase = -1;
    cin >> ntestCase;
    while(ntestCase--) {
        cin >> r;
        while(r--) {
            cin >> arr[n++];
        }

        sort(arr, arr+n);
        int middle = n/2;
        int all = 0;
        for(int i = 0; i < n; i++) {
            all += abs(arr[i] - arr[middle]);
        }

        cout << all << endl;
        n = 0;
        r = 0;
    }
    return 0;
}