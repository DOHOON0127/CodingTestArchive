#include <bits/stdc++.h>
using namespace std;

int arr[104][104], visited[104][104], M, N, K;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<int> areas;

int DFS(int y, int x) {

    visited[y][x] = 1;

    int ret = 1;
    
    for(int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;

        if(ny < 0 || nx < 0 || ny >= M || nx >= N || visited[ny][nx] == 1) continue;
        if(arr[ny][nx] == 1) continue;

        ret += DFS(ny, nx);
    }

    return ret;
}

int main() {

    cin >> M >> N >> K;

    for(int i = 0; i < K; i++) {
        int x1, y1, x2, y2; 
        cin >> x1 >> y1 >> x2 >> y2; // 0 2 4 4 

        for(int x = x1; x < x2; x++) {
            for(int y = y1; y < y2; y++) {
                arr[M-y-1][x] = 1;
            }
        }
    }

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(visited[i][j] == 0 && arr[i][j] == 0) {
                areas.push_back(DFS(i, j));
            }
        }
    }

    sort(areas.begin(), areas.end());

    cout << areas.size() << '\n';

    for(int area : areas) {
        cout << area << ' ';
    }

    return 0;
}