#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Function to calculate the derivative of a polynomial at a given x
int evaluate_derivative(int x, const vector<int>& coefficients) {
    int result = 0;
    int degree = coefficients.size() - 1;
    
    for (int i = 0; i < degree; ++i) {
        result += coefficients[i] * (degree - i) * pow(x, degree - i - 1);
    }
    
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        // First line contains the value of x
        int x = stoi(line);
        
        // Second line contains the coefficients of the polynomial
        getline(cin, line);
        istringstream ss(line);
        vector<int> coefficients;
        int coeff;
        
        while (ss >> coeff) {
            coefficients.push_back(coeff);
        }
        
        // Calculate and output the result of the derivative evaluation
        cout << evaluate_derivative(x, coefficients) << endl;
    }

    return 0;
}
