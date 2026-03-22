// int main(void) {
//     list<int> L = {1,2}; // 1 2
//     list<int>::iterator t = L.begin(); // t는 1을 가리키는 중
//     L.push_front(10); // 10 1 2
//     cout << *t << '\n'; // t가 가리키는 값 = 1을 출력
//     L.push_back(5); // 10 1 2 5
//     L.insert(t, 6); // t가 가리키는 곳 앞에 6을 삽입, 10 6 1 2 5
//     t++; // t를 1칸 앞으로 전진, 현재 t가 가리키는 값은 2
//     t = L.erase(t); // t가 가리키는 값을 제거, 그 다음 원소인 5의 위치를 반환
//     // 10 6 1 5, t가 가리키는 값은 5
//     cout << *t << '\n'; // 5
//     for(auto i : L) cout << i << ' ' ;
//     cout << '\n';
//     for(list<int>::iterator it = L.begin(); it != L.end(); it++)
//         cout << *it << ' ';
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;

    cin >> s;
    list<char> L;

    for (auto c : s) {
        L.push_back(c);
    }

    auto cursor = L.end();

    int M;
    cin >> M;

    while (M--) {
        char op;
        cin >> op;

        if (op == 'P') {
            char add;
            cin >> add;
            L.insert(cursor, add);
        }
        else if (op == 'L') {
            if (cursor != L.begin()) {
                cursor--;
            }
        }
        else if (op == 'D') {
            if (cursor != L.end()) {
                cursor++;
            }
        }
        else {
            if (cursor != L.begin()) {
                cursor--;
                cursor = L.erase(cursor);
            }
        }
    }

    for (auto c : L) {
        cout << c;
    }
}