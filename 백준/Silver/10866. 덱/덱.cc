// #include <bits/stdc++.h>
// using namespace std;
//
// int main(void){
//     deque<int> DQ;
//     DQ.push_front(10); // 10
//     DQ.push_back(50); // 10 50
//     DQ.push_front(24); // 24 10 50
//     for(auto x : DQ) cout << x << ' ';
//     cout << DQ.size() << '\n'; // 3
//     if(DQ.empty()) cout << "DQ is empty\n";
//     else cout << "DQ is not empty\n"; // DQ is not empty
//     DQ.pop_front(); // 10 50
//     DQ.pop_back(); // 10
//     cout << DQ.back() << '\n'; // 10
//     DQ.push_back(72); // 10 72
//     cout << DQ.front() << '\n'; // 10
//     DQ.push_back(12); // 10 72 12
//     DQ[2] = 17; // 10 72 17
//     DQ.insert(DQ.begin()+1, 33); // 10 33 72 17
//     DQ.insert(DQ.begin()+4, 60); // 10 33 72 17 60
//     for(auto x : DQ) cout << x << ' ';
//     cout << '\n';
//     DQ.erase(DQ.begin()+3); // 10 33 72 60
//     cout << DQ[3] << '\n'; // 60
//     DQ.clear(); // DQ의 모든 원소 제거
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> deque;

    int N;
    cin >> N;

    while(N--) {
        string s;
        cin >> s;

        if (s == "push_back") {
            int i;
            cin >> i;

            deque.push_back(i);
        }
        else if (s == "push_front") {
            int i;
            cin >> i;

            deque.push_front(i);

        }
        else if (s == "pop_back") {
            if (deque.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << deque.back() << '\n';
                deque.pop_back();
            }

        }
        else if (s == "pop_front") {
            if (deque.empty()) {
                cout << -1 << '\n';
            }else {
                cout << deque.front() << '\n';
                deque.pop_front();
            }

        }
        else if (s == "empty") {
            if (deque.empty()) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }

        }
        else if (s == "front") {
            if (deque.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << deque.front() << '\n';
            }
        }
        else if (s == "back") {
            if (deque.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << deque.back() << '\n';
            }
        }
        else if (s == "size") {
            cout << deque.size() << '\n';
        }
    }
}