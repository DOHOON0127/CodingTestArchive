#include <bits/stdc++.h>
using namespace std;

int n,r,c,d;
int arr[50][50];
bool visited[50][50];
int arr_distance[50][50];

// 0 상, 1 하, 2 좌, 3 후
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool inRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n);
}

bool isEnd() {
    bool bFlag = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == false && arr[i][j] == 0) {
                bFlag = false;
            }
        }
    }
    return bFlag;
}

int priority[4][4] = {
    {0, 2, 3, 1}, // 상
    {1, 3, 2, 0}, // 하
    {2, 1, 0, 3}, // 좌
    {3, 0, 1, 2}  // 우
};

void moveNear() {
    while (true) {
        bool moved = false;

        for (int i = 0; i < 4; i++) {
            int nd = priority[d][i];

            int nr = r + dr[nd];
            int nc = c + dc[nd];

            if (!inRange(nr, nc)) continue;
            if (arr[nr][nc] == 1) continue;
            if (visited[nr][nc] == true) continue;

            r = nr;
            c = nc;
            d = nd;

            visited[r][c] = true;

            cout << r+1 << " " << c+1 << '\n';

            moved = true;
            break;
        }
        if (!moved) break;
    }
}

pair<int, int> findTarget() {
    int dist[50][50];

    memset(dist, -1, sizeof(dist));

    queue<pair<int, int>> Q;
    Q.push({r,c});
    dist[r][c] = 0;

    while (!Q.empty()) {
        int cr = Q.front().first;
        int cc = Q.front().second;
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nr = cr + dr[dir];
            int nc = cc + dc[dir];

            if (!inRange(nr, nc)) continue;
            if (arr[nr][nc] == 1) continue;
            if (dist[nr][nc] != -1) continue;

            dist[nr][nc] = dist[cr][cc] + 1;
            Q.push({nr, nc});
        }
    }
    int tr = -1;
    int tc = -1;
    int minDist = INT_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1) continue;
            if (visited[i][j] == true) continue;
            if (dist[i][j] == -1) continue;

            if (dist[i][j] < minDist) {
                minDist = dist[i][j];
                tr = i;
                tc = j;
            }
        }
    }
    return {tr, tc};
}

void moveTarget(int tr, int tc) {
    int dist[50][50];
    memset(dist, -1, sizeof(dist));

    queue<pair<int, int>> Q;

    Q.push({tr, tc});
    dist[tr][tc] = 0;

    while (!Q.empty()) {
        int cr = Q.front().first;
        int cc = Q.front().second;
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nr = cr + dr[dir];
            int nc = cc + dc[dir];

            if (!inRange(nr, nc)) continue;
            if (arr[nr][nc] == 1) continue;
            if (dist[nr][nc] != -1) continue;

            dist[nr][nc] = dist[cr][cc] + 1;
            Q.push({nr,nc});
        }
    }
    int moveDir[4] = {2, 1, 3, 0}; // 좌 하 우 상

    while (!(r == tr && c == tc)) {

        for (int i = 0; i < 4; i++) {
            int nd = moveDir[i];

            int nr = r + dr[nd];
            int nc = c + dc[nd];

            if (!inRange(nr, nc)) continue;
            if (arr[nr][nc] == 1) continue;

            if (dist[nr][nc] == dist[r][c] - 1) {
                r = nr;
                c = nc;
                d = nd;

                break;
            }
        }
    }
    visited[r][c] = true;
    cout << r+1 << " " << c+1 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r >> c >> d;
    r--;
    c--;
    d--;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    cout << r+1 << " " << c+1 << '\n';
    visited[r][c] = true;

    while (!isEnd()) {
        moveNear();

        if (isEnd()) break;

        auto target = findTarget();

        moveTarget(target.first, target.second);
    }
    return 0;
}