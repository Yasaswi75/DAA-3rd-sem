#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str;
    cin >> str;

    stack<char> s;

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

        
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        
        else {
            if (s.empty()) {
                cout << "Invalid Parentheses";
                return 0;
            }

            char top = s.top();
            s.pop();

            if (ch == ')' && top != '(') {
                cout << "Invalid Parentheses";
                return 0;
            }

            if (ch == '}' && top != '{') {
                cout << "Invalid Parentheses";
                return 0;
            }

            if (ch == ']' && top != '[') {
                cout << "Invalid Parentheses";
                return 0;
            }
        }
    }

    if (s.empty())
        cout << "Valid Parentheses";
    else
        cout << "Invalid Parentheses";

    return 0;
}
