#include <iostream>
using namespace std;

int N;
int arr[104][104];
int dp[104][104];

// 가능한 경로의 숫자들 중 최솟값의 최댓값을 출력해야 함
// dp[i][j] -> 0,0에서 해당 경로까지 이동했을 때의 최솟값 중 최대


void findSpuareMinMax() {

    dp[1][1] = arr[1][1];

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i == 1 && j == 1 ){
                continue;
            }
            dp[i][j] = min(max(dp[i-1][j], dp[i][j-1]), arr[i][j]);
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

    findSpuareMinMax();

    cout << dp[N][N];


    return 0;
}