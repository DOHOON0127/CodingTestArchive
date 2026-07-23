#include <iostream>
#include <climits>
using namespace std;

int n;
int arr[1000];
int dp[1000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    for(int i = 0; i < n; i++) {
        dp[i] = 1;
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++){
            if(arr[j] > arr[i]) {
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