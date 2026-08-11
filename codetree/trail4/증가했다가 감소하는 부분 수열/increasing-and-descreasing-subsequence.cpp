#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1000];
// dp[i][j]
// 마지막으로 고른 원소의 위치가 i이면서
// 현재 증가-감소 상태가 j일때 (증가하는 중이면 j = 0, 감소하는 중이면 j = 1)
// 부분 수열 중 최장 증가-감소 부분 수열의 길이
int dp[1000][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {
        dp[i][0] = 1;
        dp[i][1] = 1;

        for(int j = 0; j < i; j++) {

            if(arr[j] < arr[i]) {
                dp[i][0] = max(dp[i][0], dp[j][0] + 1);
            }

            if(arr[j] > arr[i]) {
                dp[i][1] = max(dp[i][1], dp[j][1] + 1);
            }
        }

        dp[i][1] = max(dp[i][1], dp[i][0]);
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, dp[i][1]);
    }

    cout << ans;

    return 0;
}