#include <bits/stdc++.h>
using namespace std;

long long dp[31][31];

long long go(int w, int h) { 
    // 모든 약을 다 먹었을 때
    if(w == 0 && h == 0) return 1;

    if(dp[w][h] != -1) {
        return dp[w][h];
    }

    long long ret = 0;

    if(w > 0) {
        ret += go(w-1, h+1);
    }

    if(h > 0) {
        ret += go(w, h-1);
    }

    dp[w][h] = ret;
    return ret;
}

int main() {
    int N;

    while(true) {
        cin >> N;

        if(N == 0) {
            break;
        }

        memset(dp, -1, sizeof(dp));

        cout << go(N, 0) << '\n';
    }

    return 0;
}