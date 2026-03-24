#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        string s;
        getline(cin, s);

        stack<char> stack;
        bool isValid = true;

        if (s == ".") {
            break;
        }

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' ) {
                stack.push(s[i]);
            }
            else if (s[i] == ')') {
                if (stack.empty() || stack.top() != '(') {
                    isValid = false;
                    break;
                }
                stack.pop();
            }
            else if (s[i] == ']') {
                if (stack.empty() || stack.top() != '[') {
                    isValid = false;
                    break;
                }
                stack.pop();
            }
        }
        if (!stack.empty()) {
            isValid = false;
        }
        if (isValid) {
            cout << "yes" << '\n';
        }else {
            cout << "no" << '\n';
        }
    }


    return 0;
}