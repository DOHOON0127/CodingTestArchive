// #include <bits/stdc++.h>
// using namespace std;
//
// int main(void) {
//     queue<int> Q;
//     Q.push(10); // 10
//     Q.push(20); // 10 20
//     Q.push(30); // 10 20 30
//     cout << Q.size() << '\n'; // 3
//     if(Q.empty()) cout << "Q is empty\n";
//     else cout << "Q is not empty\n"; // Q is not empty
//     Q.pop(); // 20 30
//     cout << Q.front() << '\n'; // 20
//     cout << Q.back() << '\n'; // 30
//     Q.push(40); // 20 30 40
//     Q.pop(); // 30 40
//     cout << Q.front() << '\n'; // 30
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    queue<int> q;

    while (N--) {
        string s;
        cin >> s;

        if (s == "push") {
            int t;
            cin >> t;

            q.push(t);
        }
        else if (s == "pop") {
            if (q.empty() != true) {
                cout << q.front() << '\n';
                q.pop();
            }
            else {
                cout << -1 << '\n';
            }
        }
        else if (s == "size") {
            cout << q.size() << '\n';
        }
        else if (s == "empty") {
            if (q.empty() != true) {
                cout << 0 << '\n';
            }
            else {
                cout << 1 << '\n';
            }
        }
        else if (s == "front") {
            if (q.empty() != true) {
                cout << q.front() << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
        else  {
            if (q.empty() != true) {
                cout << q.back() << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
    }
}