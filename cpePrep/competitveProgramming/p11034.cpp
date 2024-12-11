#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int c;
    cin >> c;
    while(c--) {
        int l, m;
        cin >> l >> m;
        queue<pair<int, string> > right, left;
        
        for(int i = 0; i < m; ++i) {
            int carLength;
            string bank;
            cin >> carLength >> bank;

            if(bank[0] == 'l'){
                left.push(make_pair(carLength, bank));
            }else {
                right.push(make_pair(carLength, bank));
            }
        }

        bool isLeft = true; // The initial position of the ferry
        int  ferryLength = l*100;
        int crosses = 0;    // Track the number of time the ferry crosses the river
        
        while(!left.empty() || !right.empty()) {
            int laneLength = 0;
            if(isLeft) {
                while(!left.empty() && (laneLength + left.front().first <= ferryLength)) {
                    laneLength += left.front().first;
                    left.pop();
                }
            } else {
                while(!right.empty() && (laneLength + right.front().first <= ferryLength)) {
                    laneLength += right.front().first;
                    right.pop();
                }
            }

            crosses++;
            isLeft = !isLeft;
        }

        cout << crosses << endl;
    }
    return 0;
}