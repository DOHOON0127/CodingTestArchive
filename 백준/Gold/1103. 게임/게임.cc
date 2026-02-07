#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[51][51];
int dp[51][51];
int visited[51][51];

int dx[] = {0, 0, 1, -1}; // 좌 우 하 상
int dy[] = {-1, 1, 0, 0};

int go(int x, int y) {

    if(x < 0|| y < 0 || x >= N || y >= M) return 0;
    if(arr[x][y] == 0) return 0;

    if(visited[x][y] == 1) {
        cout << -1 << '\n';
        exit(0);
    }

    if(visited[x][y] == 2) return dp[x][y];

    visited[x][y] = 1;

    int tmp = arr[x][y];   
    int ret = 0;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i] * tmp;
        int ny = y + dy[i] * tmp;
        ret = max(ret, go(nx, ny));
    }

    visited[x][y] = 2;
    dp[x][y] = ret + 1;

    return dp[x][y];
}


int main () {

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            char c;
            cin >> c;
            if(c == 'H'){
                arr[i][j] = 0;
            }else {
                arr[i][j] = c - '0';
            }
        }
    }   
    // 1, 1에서 시작 (0,0)
    cout << go(0, 0) << '\n';

    return 0;
}