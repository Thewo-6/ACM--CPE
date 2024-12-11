#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;  // number of test cases
    cin >> T;

    while (T--) {
        int N;  // number of days
        cin >> N;

        int P;  // number of political parties
        cin >> P;

        vector<int> hartals(P);  // hartal parameter for each party

        for (int i = 0; i < P; ++i) {
            cin >> hartals[i];
        }

        vector<bool> isHartal(N + 1, false);  // to mark hartal days

        for (int i = 0; i < P; ++i) {
            int h = hartals[i];
            for (int day = h; day <= N; day += h) {
                // Skip Fridays (6th day of the week) and Saturdays (7th day of the week)
                if (day % 7 != 6 && day % 7 != 0) {
                    isHartal[day] = true;
                }
            }
        }

        int lostDays = 0;
        for (int day = 1; day <= N; ++day) {
            if (isHartal[day]) {
                ++lostDays;
            }
        }

        cout << lostDays << endl;
    }

    return 0;
}
