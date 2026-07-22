#include <iostream>
#include <climits>
using namespace std;

int N;
int arr[100][100];
int dp[100][100];

void intialize() {

    dp[0][0] = arr[0][0];

    for(int i = 1; i < N; i++) {
        dp[i][0] = max(dp[i-1][0], arr[i][0]);
    }

    for(int i = 1; i < N; i++) {
        dp[0][i] = max(dp[0][i-1], arr[0][i]);
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    intialize();

    for(int i = 1; i < N; i++) {
        for(int j = 1; j < N; j++) {
            dp[i][j] = max(min(dp[i-1][j], dp[i][j-1]), arr[i][j]);
        }
    }

    cout << dp[N-1][N-1];

    return 0;
}