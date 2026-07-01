#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n, k, m;
int grid[100][100];
bool visited[100][100];
int r[10000], c[10000];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
vector<pair<int, int> > V;
int ans_max;

int BFS() {

    memset(visited, false, sizeof(visited));
    queue<pair<int, int> > Q;
    int count = 0;

    for (int i = 0; i < k; i++) {
        int sr = r[i];
        int sc = c[i];

        if (!visited[sr][sc]) {
            visited[sr][sc] = true;
            Q.push({sr,sc});
            count++;
        }
    }

    while(!Q.empty()) {
        int r = Q.front().first;
        int c = Q.front().second;

        Q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < n
            && visited[nr][nc] == false && grid[nr][nc] == 0) {

                visited[nr][nc] = true;
                Q.push({nr, nc});
                count++;
            }
        }
    }
    return count;
}

// idx : 현재 확인 중인 돌
// cnt : 지금까지 치운 돌 개수
void removeRock(int idx, int cnt) {

    if (cnt == m) {
        // 여기서 BFS 실행
        int curr_ans = BFS();
        if (curr_ans > ans_max) {
            ans_max = curr_ans;
        }
        return;
    }

    if (idx == V.size()) {
        return;
    }

    int r = V[idx].first;
    int c = V[idx].second;

    grid[r][c] = 0;
    removeRock(idx + 1, cnt + 1);

    grid[r][c] = 1;

    removeRock(idx + 1, cnt);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 1) {
                V.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> r[i] >> c[i];
        r[i]--;
        c[i]--;
    }

    // Please write your code here.

    removeRock(0, 0);

    cout << ans_max << '\n';

    return 0;
}
