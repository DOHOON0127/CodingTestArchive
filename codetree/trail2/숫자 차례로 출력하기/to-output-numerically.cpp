#include <iostream>
using namespace std;

int N;

void solve(int cnt) {
    if(cnt == 0){
        return;
    }

    solve(cnt-1);

    cout << cnt << " ";

}


void solve2(int cnt) {
    if(cnt == 0){
        return;
    }

    cout << cnt << " ";

    solve2(cnt-1);

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    solve(N);

    cout << '\n';

    solve2(N);

    return 0;
}