#include <iostream>
using namespace std;

int n;

void solve(int cnt) {
    if(cnt == 0) {
        return;
    }

    for(int i = 0; i < cnt; i++) {
        cout << '*' << ' ';
    }

    cout << '\n';

    solve(cnt - 1);

    for(int i = 0; i < cnt; i++) {
        cout << '*' << ' ';
    }

    cout << '\n';

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    solve(n);

    return 0;
}