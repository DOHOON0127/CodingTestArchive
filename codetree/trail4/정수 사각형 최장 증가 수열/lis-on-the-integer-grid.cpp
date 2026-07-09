#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// 시작점을 적절하게 잡아서, 상하좌우인접한 칸으로 가는데, 계속 정수값이 커져야함
// 이때 밟고 지나갈 수 있는 최대 칸의 수를 구하는 프로그램?
// 흠 애매띠니 한데
// 

int arr[501][501];
int dp[501][501];
int N;

// (x, y)에서 출발하여 조건을 만족하며 
// 도달 할 수 있는 칸의 수 중 
// 최대 칸의 수
int findMax(int x, int y) {

    if(dp[x][y] != -1) {
        return dp[x][y];
    }

    int best = 1;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && ny < N && ny >= 0 && ny < N && arr[nx][ny] > arr[x][y]) {
            best = max(best, findMax(nx, ny) + 1);
        }
    }

    dp[x][y] = best;

    return dp[x][y];

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

    memset(dp, -1, sizeof(dp));

    int ans = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            ans = max(ans, findMax(i, j));
        }
    }

    cout << ans;

    return 0;
}