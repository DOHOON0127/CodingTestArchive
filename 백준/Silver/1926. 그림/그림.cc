#include <bits/stdc++.h>
using namespace std;

int a[501][501];
bool visited[501][501];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int num = 0;
    int mx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0 || visited[i][j]) {
                continue;
            }
            num++;
            queue<pair<int, int>> que;
            visited[i][j] = 1;
            que.push({i, j});

            int maxArea = 0;

            while (!que.empty()) {
                maxArea++;
                pair<int, int> p = que.front();
                que.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = p.first + dx[dir];
                    int ny = p.second + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                        continue;
                    }
                    if (visited[nx][ny] || a[nx][ny] != 1) {
                        continue;
                    }
                    visited[nx][ny] = 1;
                    que.push({nx, ny});
                }
            }
            mx = max(mx, maxArea);
        }
    }
    cout << num << '\n' << mx;
}