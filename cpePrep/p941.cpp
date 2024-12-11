#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long int t, n, fac[21];
    string s;

    fac[0] = fac[1] = 1;
    for(int i = 2; i <= 20; i++)
        fac[i] = i * fac[i - 1];

    cin >> t;
    while(t--) {
        long long int idx;
        cin >> s >> n;
        sort(s.begin(), s.end());

        for(int r = s.size() - 1; r >= 0; r--) {
            idx = n / fac[r];
            n %= fac[r];
            cout << s[idx];
            s.erase(s.begin() + idx);
        }
        cout << "\n";
    }

    return 0;
}