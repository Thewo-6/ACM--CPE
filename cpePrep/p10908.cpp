#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the minimum of four values
int minFour(int a, int b, int c, int d) {
    return min(min(a, b), min(c, d));
}

// Function to find the largest square with the same characters centered at (r, c)
int findLargestSquare(const vector<string>& grid, int r, int c, int M, int N) {
    char centerChar = grid[r][c];
    int maxSize = minFour(r, c, M - r - 1, N - c - 1);
    for (int size = 1; size <= maxSize; ++size) {
        for (int i = r - size; i <= r + size; ++i) {
            if(grid[i][c - size] != centerChar || grid[i][c + size] != centerChar) {
                return 2 * size - 1;
            }
        }
        for (int j = c - size; j <= c + size; ++j) {
            if (grid[r - size][j] != centerChar || grid[r + size][j] != centerChar) {
                return 2 * size - 1;
            }
        }
    }
    return 2 * maxSize + 1;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int M, N, Q;
        cin >> M >> N >> Q;
        
        vector<string> grid(M);
        for (int i = 0; i < M; ++i) {
            cin >> grid[i];
        }
        
        cout << M << " " << N << " " << Q << endl;
        
        for (int i = 0; i < Q; ++i) {
            int r, c;
            cin >> r >> c;
            cout << findLargestSquare(grid, r, c, M, N) << endl;
        }
    }
    
    return 0;
}
