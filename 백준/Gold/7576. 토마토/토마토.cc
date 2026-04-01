#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int a[1001][1001];
int dist[1001][1001];

int dx[4] = {1, 0, -1 ,0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    queue<pair<int, int>> Q;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            dist[i][j] = -1;

            if (a[i][j] == 1) {
                Q.push(make_pair(i, j));
                dist[i][j] = 0;
            }
        }
    }

    pair<int, int> p;

    while (!Q.empty()) {
        p = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i ++) {
            int nx = p.X + dx[i];
            int ny = p.Y + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                continue;
            }

            if (a[nx][ny] == -1 ||   dist[nx][ny] >= 0) {
                continue;
            }

            dist[nx][ny] = dist[p.X][p.Y] + 1;
            Q.push(make_pair(nx, ny));
        }
    }

    int ans = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == -1 && a[i][j] == -1) continue;
            if (dist[i][j] == -1 && a[i][j] != -1) {
                cout << -1 << '\n';
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }

    cout << ans << '\n';
}