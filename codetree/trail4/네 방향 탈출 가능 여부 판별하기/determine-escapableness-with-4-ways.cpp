#include <bits/stdc++.h>
#include <queue>
using namespace std;

int arr[104][104];
bool visited[104][104];

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    queue<pair<int,int> > Q;
    Q.push(make_pair(0,0));
    visited[0][0] = true;

    while (!Q.empty()) {
        int fr = Q.front().first;
        int fc = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = fr + dr[i];
            int nc = fc + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if (visited[nr][nc] == true || arr[nr][nc] == 0) continue;

            if (nr == N-1 && nc == M-1) {
                cout << 1 << '\n';
                return 0;
            }

            Q.push(make_pair(nr, nc));
            visited[nr][nc] = true;
        }
    }

    cout << 0 << '\n';
    return 0;

}