#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

// 1이 돌을 나타낸다 할 때, 주어진 돌 중 M개의 돌만 적절하게 치워
// K개의 시작점으로부터 상하좌우 인접한 곳으로만 이동하여 도달 가능한 칸의 수를 최대로 하는 프로그램을 작성해보세요
// 정수 0은 해당 칸이 이동할 수 있는 곳임을, 정수 1은 돌이 있어 해당 칸이 이동할 수 없는 곳임을 의미합니다.

int n, k, m; // 격자 크기, 시작점 수, 치워야할 돌의 개수
int max_num = INT_MIN;
int arr[100][100];
bool visited[100][100];

vector<pair<int, int>> V; // 시작점들 저장 벡터
vector<pair<int, int>> stones; // 치울 m개의 돌을 적어넣을 수 있는 벡터

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool inRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n);
}

// 시작점들을 다 큐에 넣고 돌린다음에 도달 가능한 최대 칸수를 리턴
int bfs() {
    int cnt_max = 0; // 도달 가능한 최대 칸 수
    queue<pair<int, int>> Q;
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < V.size(); i++) {
        int r = V[i].first;
        int c = V[i].second;
        Q.push({r, c});
        visited[r][c] = true;
        cnt_max++;
    }

    while (!Q.empty()) {
        int cr = Q.front().first;
        int cc = Q.front().second;
        Q.pop();

        for (int d = 0; d < 4; d++) {
            int nr = cr + dr[d];
            int nc = cc + dc[d];

            if (!inRange(nr, nc)) continue;
            if (visited[nr][nc]) continue;
            if (arr[nr][nc] == 1) continue;

            Q.push({nr, nc});
            visited[nr][nc] = true;
            cnt_max++;
        }
    }

    return cnt_max;
}

void choose(int start, int end) { // 몇번째 돌부터 선택?, 지금까지 선택한 돌의 개수?
    if (end == m) {
        // BFS
        max_num = max(bfs(),max_num);
        return;
    }

    for (int i = start; i < stones.size(); i++) {
        int r = stones[i].first;
        int c = stones[i].second;

        arr[r][c] = 0;

        choose(i+1, end+1);

        arr[r][c] = 1;
    }

}

int main () {

    cin >> n >> k >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 1) {
                stones.push_back({i,j});
            }
        }
    }

    // k개의 시작점을 저장함
    for (int i = 0; i < k; i++) {
        int r;
        int c;
        cin >> r >> c;
        r--;
        c--;
        V.push_back({r,c});
    }

    choose(0,0);

    cout << max_num;

    return 0;
}
