#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
#include <climits>
using namespace std;

int n, k;
int grid[100][100];
int min_dist[100][100];
bool visited[100][100];
int r1, c1, r2, c2;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int min_time = INT_MAX;

// 갈 수 있는 곳 0, 갈 수 없는 곳 1(벽)
// 한 칸 이동시 1초 소요


// 일단 1들 중에서 K개를 골라서 0으로 바꾸는 함수를 만들고
// 그 다음에 K개가 0으로 바꿔진 grid에서
// BFS를 돌려서 거리를 표시한 다음에 최단거리를 뽑는데
// 만약에 그때 도착점에 도달할 수 없다면 -1을 출력하면 될 것 같음


void BFS(int ir, int ic) {

    memset(visited, false, sizeof(visited));
    memset(min_dist, 0, sizeof(min_dist));

    queue<pair<int, int>> Q;
    Q.push({ir, ic});
    visited[ir][ic] = true;
    min_dist[ir][ic] = 0;

    while(!Q.empty()) {
        int r, c;
        tie(r,c) = Q.front();
        Q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < n && visited[nr][nc] == false
            && grid[nr][nc] == 0) {

                Q.push({nr, nc});
                visited[nr][nc] = true;
                min_dist[nr][nc] = min_dist[r][c] + 1;
            }
        }
    }
}


// 1들 중에서 k개를 골라서 0으로 바꾸는 함수
// idx : 0 ~ n*n-1까지의 인덱스
// cnt 고른 점의 개수

vector<pair<int, int>> v_k;

void chageKto0(int idx, int cnt) {

    if(cnt == k) {

        for(int i = 0; i < (int)v_k.size(); i++) {
            grid[v_k[i].first][v_k[i].second] = 0;
        }

        BFS(r1, c1);

        if(min_dist[r2][c2] != 0) {
            if(min_time > min_dist[r2][c2]) {
                min_time =  min_dist[r2][c2];
            }
        }

        for(int i = 0; i < (int)v_k.size(); i++) {
            grid[v_k[i].first][v_k[i].second] = 1;
        }

        return;
    }

    if(idx == n * n) {
        return;
    }

    int r = idx / n;
    int c = idx % n;

    if(grid[r][c] == 1) {
        v_k.push_back({r, c});
        chageKto0(idx+1, cnt+1);
        v_k.pop_back();

        chageKto0(idx+1, cnt);
    }else{
        chageKto0(idx+1, cnt);
    }

}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r1 >> c1; // 시작점
    cin >> r2 >> c2; // 도착점

    r1--;
    c1--;
    r2--;
    c2--;

    // Please write your code here.

    chageKto0(0, 0);

    if(min_time == INT_MAX) {
        cout << -1;
    }
    else{
        cout << min_time;
    }


    return 0;
}
