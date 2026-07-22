#include <iostream>
#include <climits>
using namespace std;

// N개의 숫자가 주어졌을 때, 가장 긴 증가 부분 수열의 길이를 구하는 프로그램.
int N;
int arr[1000];
int dp[1000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < N; i++) {
        dp[i] = 1;
    }

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++) {            
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int ans = INT_MIN;

    for(int i = 0; i < N; i++) {
        if(ans < dp[i]) {
            ans = dp[i];
        }
    }

    cout << ans;

    return 0;
}