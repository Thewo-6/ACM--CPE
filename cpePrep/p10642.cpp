#include <iostream>
using namespace std;

typedef long long ll;

// Function to calculate the node number for given coordinates
ll nodeNumber(ll x, ll y) {
    ll s = x + y;
    return s * (s + 1) / 2 + x;
}

int main() {
    int n;
    cin >> n; // Number of test cases
    for (int i = 1; i <= n; ++i) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2; // Source and destination coordinates

        ll N1 = nodeNumber(x1, y1);
        ll N2 = nodeNumber(x2, y2);

        ll steps = N2 - N1;

        cout << "Case " << i << ": " << steps << endl;
    }
    return 0;
}
