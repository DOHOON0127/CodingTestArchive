#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k;
int s_r, s_c, e_r, e_c;
int arr[100][100];
int arr_time[100][100];
bool visited[100][100];
int min_time = INT_MAX;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

vector<pair<int,int>> V_wall; // 벽의 위치를 다 담아놓는 배열

// 4 2
// 0 0 0 0
// 0 1 1 1
// 1 1 1 1
// 0 1 0 0
// 1 1
// 4 4

bool inRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n);
}

void bfs() {
    queue<pair<int, int>> Q;
    memset(visited, false, sizeof(visited));
    memset(arr_time, 0, sizeof(arr_time));

    Q.push({s_r, s_c});
    visited[s_r][s_c] = true;

    while (!Q.empty()) {
        auto [r,c] = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (!inRange(nr, nc)) continue;
            if (visited[nr][nc]) continue;
            if (arr[nr][nc] == 1) continue;

            Q.push({nr, nc});
            visited[nr][nc] = true;
            arr_time[nr][nc] = arr_time[r][c] + 1;
        }
    }

}

void choose(int start, int end) {
    if (end == k) {
        bfs();
        if (arr_time[e_r][e_c] == 0) {
            // cout << -1;
        }else {
            min_time = min(min_time, arr_time[e_r][e_c]);
        }
        return;
    }

    for (int i = start; i < V_wall.size(); i++) {
        auto [r,c] = V_wall[i];

        arr[r][c] = 0;

        choose(i+1, end+1);

        arr[r][c] = 1;
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                V_wall.push_back({i,j});
            }
        }
    }

    cin >> s_r >> s_c;
    s_r--;
    s_c--;

    cin >> e_r >> e_c;
    e_r--;
    e_c--;

    choose(0, 0);

    if (min_time == INT_MAX) {
        cout << -1;
    }else {
        cout << min_time;
    }

    return 0;
}