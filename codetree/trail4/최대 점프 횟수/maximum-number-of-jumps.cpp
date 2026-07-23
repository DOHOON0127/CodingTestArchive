#include <iostream>
#include <climits>
using namespace std;

int n;
int arr[1000];
int dp[1000];
// dp라는게 현재 위치까지 왔을때 최대 점프 횟수라고 정의
// 그러면 dp[0] = 0
// j + a[j] >= i
// 0 <= j < i

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 1; i < n; i++) {
        dp[i] = INT_MIN;
    }

    dp[0] = 0;

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            
            if(j + arr[j] >= i) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    int ans = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(ans < dp[i]) {
            ans = dp[i];
        }
    }

    cout << ans;

    return 0;
}