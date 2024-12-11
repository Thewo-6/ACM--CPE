#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    while(n--) {
        stack<char> check;

        string str;
        getline(cin, str);
        bool ans_given = false;

        for(const char &c : str) {
            if(c == '(' || c == '['){
                if (check.size() == 128) {
                    cout << "No" << endl;
                    ans_given = true;
                    break;
                } else {
                    check.push(c);
                }
            } else if(c == ')') {
                if(check.empty()) {
                    cout << "No" << endl;
                    ans_given = true;
                    break;
                } else if (check.top() == '(') {
                    check.pop();
                }
            } else if(c == ']') {
                if(check.empty()) {
                    cout << "No" << endl;
                    ans_given = true;
                    break;
                } else if (check.top() == '[') {
                    check.pop();
                }
            }
        }
        if(!ans_given) {
            if(check.empty())
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}

/*

#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if the parentheses and brackets are balanced
bool isBalanced(const string& s) {
    stack<char> stk;
    for (char c : s) {
        // Push opening brackets/parentheses onto the stack
        if (c == '(' || c == '[') {
            stk.push(c);
        } 
        // Handle closing brackets/parentheses
        else if (c == ')' || c == ']') {
            // If the stack is empty or the top doesn't match, it's unbalanced
            if (stk.empty()) {
                return false;
            }
            char top = stk.top();
            stk.pop();
            if ((c == ')' && top != '(') || (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    // If stack is empty, all opened brackets/parentheses were closed
    return stk.empty();
}

int main() {
    int n;
    cin >> n; // Read the number of strings

    // Clear newline after reading integer
    cin.ignore();

    // Iterate over the strings
    for (int i = 0; i < n; ++i) {
        string input;
        getline(cin, input); // Read each string including spaces
        if (isBalanced(input)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}

*/