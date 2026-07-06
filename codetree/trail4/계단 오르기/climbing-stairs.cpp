#include <iostream>
#include <cstring>

using namespace std;

int n;

int memo[1004];

int upStair(int cnt) {
    if(memo[cnt] != -1) {
        return memo[cnt];
    }

    if(cnt == 2 || cnt == 3) {
        memo[cnt] = 1;
    }
    else {
        memo[cnt] = (upStair(cnt - 2) + upStair(cnt - 3)) % 10007;
    }

    // cout << memo[cnt] << '\n';
    return memo[cnt];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    memset(memo, -1, sizeof(memo));
    memo[1] = 0;

    upStair(n);

    cout << memo[n];


    return 0;
}