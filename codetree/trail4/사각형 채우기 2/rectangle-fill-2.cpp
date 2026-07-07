#include <iostream>
#include <cstring>

using namespace std;

int n;
int memo[1004];

int square(int cnt) {
    if(memo[cnt] != -1) {
        return memo[cnt];
    }

    if(cnt == 1) {
        memo[cnt] = 1;
    }
    else if(cnt == 2) {
        memo[cnt] = 3;
    }
    else {
        memo[cnt] = (square(cnt - 1) + square(cnt - 2) * 2) % 10007;
    }
    return memo[cnt];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    memset(memo, -1, sizeof(memo));

    square(n);

    cout << memo[n];

    return 0;
}
