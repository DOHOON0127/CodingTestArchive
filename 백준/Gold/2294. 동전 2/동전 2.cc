#include <bits/stdc++.h>
using namespace std;

/*
 * 동전 n가지 종류 -> 합을 k원으로 만듦
 * 동전의 개수는 최소여야 함
 * 각각의 동전은 몇개라도 사용가능
 * n,k가 주어짐, 다음 n개의 줄에는 각각의 동전의 가치가 주어짐
 * n,k는 각각 100,10000 이하의 자연수
 * 동전의 가치는 십만이하
 * 가치가 같은 동전이 여러 번 주어질 수도 있음
 *
 * 3, 15
 * 1,
 * 5,
 * 12
 * 가 입력되었다고 치면 출력은 3
 * 1 1 1 12, 5 5 5
 * 어떻게 해야될까? 일단 큰수부터 채워넣기? 하지만 그게 최소횟수라는 보장이 없음
 */

int main() {
    int n, k;

    cin >> n >> k;

    int coin[101];
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    int INF = 987654321;
    int dp[10001];
    fill(dp, dp + 10001, INF);
    dp[0] = 0;

    for (int j = 1; j <= k; j++) {
        for (int i = 0; i < n; i++) {
            if (j - coin[i] >= 0) {
                dp[j] = min(dp[j], dp[j - coin[i]] + 1);
            }
        }
    }

    if (dp[k] == INF) {
        cout << -1 << '\n';
    }
    else {
        cout << dp[k] << '\n';
    }

    return 0;
}