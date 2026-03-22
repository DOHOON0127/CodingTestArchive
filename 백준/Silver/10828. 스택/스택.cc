// #include <bits/stdc++.h>
// using namespace std;
//
// int main(void) {
//     stack<int> S;
//     S.push(10); // 10
//     S.push(20); // 10 20
//     S.push(30); // 10 20 30
//     cout << S.size() << '\n'; // 3
//     if(S.empty()) cout << "S is empty\n";
//     else cout << "S is not empty\n"; // S is not empty
//     S.pop(); // 10 20
//     cout << S.top() << '\n'; // 20
//     S.pop(); // 10
//     cout << S.top() << '\n'; // 10
//     S.pop(); // empty
//     if(S.empty()) cout << "S is empty\n"; // S is empty
//     cout << S.top() << '\n'; // runtime error 발생
// }

#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> S;

    int N;

    cin >> N;

    while (N--) {
        string c;
        cin >> c;
        if (c == "push") {
            int t;
            cin >> t;
            S.push(t);
        }
        else if (c == "pop") {
            if (S.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << S.top() << '\n';
                S.pop();
            }
        }
        else if (c == "size") {
            cout << S.size() << '\n';
        }
        else if (c == "empty") {
            cout << S.empty() << '\n';
        }
        else { // top
            if (S.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << S.top() << '\n';
            }
        }
    }

}