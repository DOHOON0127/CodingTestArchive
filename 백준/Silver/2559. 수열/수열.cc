#include <bits/stdc++.h>
using namespace std;

int N, K, a;
int asum[100004]; // 누적합 저장
int mx = -10000004;

int main() {

    cin >> N >> K;

    for(int i = 1; i <= N; i++) {
        cin >> a;
        asum[i] = asum[i-1] + a;
    }

    for(int i = K; i <= N; i++) {
        int sum = asum[i] - asum[i-K];

        mx = max(mx, sum);
    }

    cout << mx << '\n';

    return 0;
}