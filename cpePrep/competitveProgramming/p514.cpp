#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    while(cin >> n && n != 0) {
        while(true) {
            vector<int> target(n);
            cin >> target[0];
            if(target[0] == 0) {
                cout << endl;
                break;
            }
            for (int i = 1; i < n; ++i) {
                cin >> target[i];
            }

            stack<int> station;
            int current_coach = 1;
            bool possible = true;

            for(int i = 0; i < n; ++i) {
                while (current_coach <= target[i]) {
                    station.push(current_coach);
                    ++current_coach;
                }

                if (station.top() == target[i]) {
                    station.pop();
                } else {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
        return 0;
    }
}