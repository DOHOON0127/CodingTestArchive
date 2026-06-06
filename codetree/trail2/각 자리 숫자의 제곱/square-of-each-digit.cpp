#include <iostream>
using namespace std;

int N;

int solve(int cnt) {

    if(cnt < 10) {
        return cnt * cnt;
    }

    return solve(cnt / 10) + (cnt % 10) * (cnt % 10);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    cout << solve(N);

    return 0;
}