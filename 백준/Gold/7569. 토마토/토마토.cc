#include <bits/stdc++.h>
using namespace std;

int a[101][101][101];
int dist[101][101][101];

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, h;

    cin >> m >> n >> h; // 5 3 2

    queue<tuple<int, int, int>> Q;

    int count = 0;

    for (int i = 0; i < h; i++) { // 2
        for (int j = 0; j < n; j++) { // 3
            for (int k = 0; k < m; k++) { // 5
                cin >> a[j][k][i];
                dist[j][k][i] = -1;

                if (a[j][k][i] == 1) {
                    dist[j][k][i] = 0;

                    Q.push(make_tuple(j, k, i));
                }

                if (a[j][k][i] == 0) {
                    count++;
                }
            }
        }
    }

    if (count == 0) {
        cout << 0 << '\n';
        return 0;
    }

    while (!Q.empty()) {
        auto[X, Y, Z] = Q.front();
        Q.pop();

        for (int i = 0; i < 6; i++) {
            int nx = X + dx[i];
            int ny = Y + dy[i];
            int nz = Z + dz[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if (a[nx][ny][nz] == -1 || dist[nx][ny][nz] >= 0) continue;

            dist[nx][ny][nz] = dist[X][Y][Z] + 1;
            Q.push(make_tuple(nx, ny, nz));
        }
    }

    int ans = 0;

    for (int i = 0; i < h; i++) { // 2
        for (int j = 0; j < n; j++) { // 3
            for (int k = 0; k < m; k++) { // 5
                if (dist[j][k][i] == -1 && a[j][k][i] == -1) continue;
                if (dist[j][k][i] == -1 && a[j][k][i] != -1) {
                    cout << -1 << '\n';
                    return 0;
                }

                ans = max(ans, dist[j][k][i]);
            }
        }
    }

    cout << ans << '\n';

}