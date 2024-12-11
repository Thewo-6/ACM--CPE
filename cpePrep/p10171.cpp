#include <iostream>
using namespace std;

int main() {
    long long S, D;
    
    // Read input values
    while (cin >> S >> D) {
        long long total_days = S;
        long long group_size = S;
        
        // Find the group staying on the D-th day
        while (total_days < D) {
            group_size++;
            total_days += group_size;
        }
        
        // Output the group size
        cout << group_size << endl;
    }

    return 0;
}
