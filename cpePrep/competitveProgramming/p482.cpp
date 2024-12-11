#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        int n, index = 0;
        vector<int> permutation;
        char c;
        while(cin >> n) {
            permutation.push_back(n);
            permutation[index++]--;

            //when using the peek function you are reading the next character in a stream without extracting it/
            if (cin.peek() == '\n') {
                cin.get(c); // Consume newline character
                break; // Exit the loop
            }
        }

        int vector_size = permutation.size();

        vector<string> numbers(vector_size);
        for (int i = 0; i < vector_size; ++i) {
            cin >> numbers[i];
        }
        
        vector<string> permuted_numbers(vector_size);
        for (int i = 0; i < vector_size; ++i) {
            permuted_numbers[permutation[i]] = numbers[i];
        }
        
        for (int i = 0; i < vector_size; ++i) {
            cout << permuted_numbers[i] << endl;
        }
        
        if (t > 0) cout << endl; // Printing a blank line between test cases
    }

    return 0;
}