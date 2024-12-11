#include <iostream>
using namespace std;

// Custom GCD function using the Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int N;
    
    while (cin >> N && N != 0) {
        long long G = 0;
        
        for (int i = 1; i < N; ++i) {
            for (int j = i + 1; j <= N; ++j) {
                G += gcd(i, j);
            }
        }
        
        cout << G << endl;
    }
    
    return 0;
}
