#include <bits/stdc++.h>
using namespace std;

int arr[101][101];
int vis[101][101];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j] - '0';
        }
    }

    queue<pair<int, int> > q;
    q.push(make_pair(0,0));

    while (!q.empty()) {

        pair<int, int> p = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {

            int nx = p.first + dx[dir];
            int ny = p.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (arr[nx][ny] == 0 || vis[nx][ny] != 0) continue;

            vis[nx][ny] = vis[p.first][p.second] + 1;
            q.push(make_pair(nx, ny));

        }
    }

    cout << vis[n-1][m-1] + 1 << '\n';
}