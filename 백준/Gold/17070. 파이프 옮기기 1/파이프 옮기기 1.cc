#include <bits/stdc++.h>
using namespace std;

int N; // 집의 크기
int arr[17][17];
int dp[17][17][3]; // 가로 대각선 세로

int dx[] = {0, 1, 1}; 
int dy[] = {1, 1, 0};

int go(int x, int y, int dir) {

    if(x >= N || y >= N) return 0;
    if(arr[x][y] == 1) return 0;
    if(dir == 1 && (arr[x-1][y] == 1 || arr[x][y-1] == 1)) return 0;
    if(x == N-1 && y == N-1) return 1;

    int &ret = dp[x][y][dir];
    if(ret != -1) return ret;
    ret = 0;

    if(dir == 0) { // 현재 가로
        ret += go(x+dx[0], y+dy[0], 0);
        ret += go(x+dx[1], y+dy[1], 1);
    }
    else if(dir == 1) { // 현재 대각선
        ret += go(x+dx[0], y+dy[0], 0);
        ret += go(x+dx[1], y+dy[1], 1);
        ret += go(x+dx[2], y+dy[2], 2);
    }
    else { // 현재 세로
        ret += go(x+dx[1], y+dy[1], 1);
        ret += go(x+dx[2], y+dy[2], 2);
    }

    return ret;
}

int main () {
    memset(dp, -1, sizeof(dp));
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    cout << go(0, 1, 0) << '\n';
    return 0;
    
}