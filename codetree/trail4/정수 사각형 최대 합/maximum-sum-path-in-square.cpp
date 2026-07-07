#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[104][104];
int dp[104][104]; 

// dp[i][j]는 (i, j)위치에 있을때의 최대의 숫자의 합
// = max (dp[i-1][j] + arr[i], dp[i][j-1] + arr[i])

void sumDP(int cnt) {

    for(int i = 1; i <= cnt; i++) {
        for(int j = 1; j <= cnt; j++) {
            dp[i][j] = max(dp[i-1][j] + arr[i][j], dp[i][j-1] + arr[i][j]);
        }
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }

    sumDP(N);

    cout << dp[N][N];

    return 0;
}