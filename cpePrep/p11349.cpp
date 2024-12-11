#include <iostream>
#include <vector>
using namespace std;

bool isSymmetric(const vector<vector<long long> >& matrix, int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++) {  // Only check the upper or lower triangle
			if (matrix[i][j] < 0) {    // Check for negative values
                return false;
            }
            
			if(matrix[i][j] != matrix[n-1-i][n-1-j]) { // Compare symmetric elements
				return false;
			}
		}
	}
	return true;
}

int main() {
	int T;
	cin >> T;
	
	for(int t = 1; t <= T; t++) {
		string dummy;
		cin >> dummy >> dummy;  // Skipping "Test" "N" "="
		int n;
		cin >> n;
		vector<vector<long long> > matrix(n, vector<long long>(n));
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cin >> matrix[i][j];
			}
		}
		
		if(isSymmetric(matrix, n)) {
			cout << "Test #" << t << ": Symmetric." << endl;
		}else {
			cout << "Test #" << t << ": Non-symmetric." << endl;
		}
	}
	
	return 0;
}
