#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n, t, m;
        cin >> n >> t >> m;
        queue<pair<int, int> > left, right;
        vector<int> results(m);

        for (int i = 0; i < m; i++) {
            int time;
            char bank[10];
            cin >> time >> bank;
            if (bank[0] == 'l') {
                left.push({time, i});
            } else {
                right.push({time, i});
            }
        }

        bool isLeft = true; // The ferry starts at the left bank.
        int currentTime = 0;

        while (!left.empty() || !right.empty()) {
            int nextArrival = 1e9;
            if (!left.empty()) nextArrival = min(nextArrival, left.front().first);
            if (!right.empty()) nextArrival = min(nextArrival, right.front().first);

            currentTime = max(currentTime, nextArrival);

            int count = 0;
            if (isLeft) {
                while (!left.empty() && left.front().first <= currentTime && count < n) {
                    results[left.front().second] = currentTime + t;
                    left.pop();
                    count++;
                }
            } else {
                while (!right.empty() && right.front().first <= currentTime && count < n) {
                    results[right.front().second] = currentTime + t;
                    right.pop();
                    count++;
                }
            }

            currentTime += t;
            isLeft = !isLeft;
        }

        for (int time : results) {
            cout << time << endl;
        }
        if (c > 0) cout << endl; // Print an empty line between test cases
    }
    return 0;
}