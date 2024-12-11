#include <iostream>
#include <stack>
#include <vector>
#include <cctype>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

// Function to convert infix to postfix expression
string infixToPostfix(vector<char> &infix) {
    stack<char> operators;
    string postfix = "";

    for (char token : infix) {
        // If the token is an operand, add it to the postfix expression
        if (isdigit(token)) {
            postfix += token;
        }
        // If the token is '(', push it to the stack
        else if (token == '(') {
            operators.push(token);
        }
        // If the token is ')', pop from the stack until '(' is found
        else if (token == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Remove the '('
        }
        // If the token is an operator
        else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(token)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(token);
        }
    }

    // Pop all remaining operators from the stack
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main() {
    int testCases;
    cin >> testCases;
    cin.ignore(); // Ignore newline after the testCases integer

    while (testCases--) {
        vector<char> infix;
        string line;

        // Skip the blank line before each test case(handled the newline character after the testCase)
        if (cin.peek() == '\n') cin.ignore();

        // Read each character one by one (in the format specified by the problem)
        while (getline(cin, line) && !line.empty()) {
            infix.push_back(line[0]); // Push the first character of each line
        }

        // Convert the infix expression to postfix and print the result
        string postfix = infixToPostfix(infix);
        cout << postfix << endl;

        if (testCases > 0) {
            cout << endl; // Print a blank line between test cases
        }
    }

    return 0;
}