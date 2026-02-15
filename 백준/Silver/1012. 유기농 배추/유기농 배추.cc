#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool visited[54][54];
int arr[54][54];

int T, M, N, K, X, Y, m, n, ret;

void DFS(int y, int x) { // y : 행, x : 열

    visited[y][x] = 1;

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i]; 

        if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

        if(!visited[ny][nx] && arr[ny][nx] == 1){
            DFS(ny, nx);
        }
    }

}

int main () {

    cin >> T;

    for(int t = 0; t < T; t++) {
        cin >> M >> N >> K;

        memset(visited, 0, sizeof(visited));
        memset(arr, 0, sizeof(arr));
        ret = 0;  

        for(int i = 0; i < K; i++) {

            int x, y;
            cin >> x >> y; // x : 가로, y : 세로
            arr[y][x] = 1;

        }

        for(int y = 0; y < N; y++){
            for(int x = 0; x < M; x++){
                if(!visited[y][x] && arr[y][x] == 1){   
                    DFS(y, x);
                    ret++;
                }
            }
        }

        cout << ret << '\n';

    }

    return 0;

}