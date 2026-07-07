#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[104][104];
int dp[104][104];

void initialize(int n) {
    for(int i = n-1; i >= 1; i--) {
        dp[1][i] = dp[1][i+1] + arr[1][i]; 
    }

    for(int i = 1; i < n; i++) {
        dp[i+1][n] = dp[i][n] + arr[i+1][n];
    }
}

void minSumSquare(int n) {
    for(int i = 2; i <= n; i++) {
        for(int j = n-1; j >= 1; j--) {
            dp[i][j] = min(dp[i-1][j] + arr[i][j], dp[i][j+1] + arr[i][j]);
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

    dp[1][N] = arr[1][N];

    initialize(N);

    minSumSquare(N);

    cout << dp[N][1];

    return 0;
}