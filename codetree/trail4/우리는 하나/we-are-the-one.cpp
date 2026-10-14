// #include <iostream>
// #include <vector>
// #include <queue>
// #include <cstring>
// #include <tuple>
// #include <cmath>
// using namespace std;

// int N; // 격자 크기 N x N
// int K; // 고를 도시의 개수
// int U, D; // 두 도시간의 높이차는 U 이상 D이하, 도시 높이차가 이 범위 안이라면 계속 뻗어나갈 수 있음

// int arr[10][10];
// bool visited[10][10];

// int dr[4] = {-1, 0, 1, 0};
// int dc[4] = {0, 1, 0, -1};

// vector<pair<int, int> > V_k; // k개의 좌표를 담을 벡터

// int max_cnt;

// void BFS() {

//     memset(visited, false, sizeof(visited));

//     int cnt = 0;

//     queue<pair<int, int> > Q;

//     // 초기 K개의 시작점을 큐에 넣을 때 바로 방문 처리!
//     for(int i = 0; i < (int)V_k.size(); i++) {
//         Q.push({V_k[i]});
//         visited[V_k[i].first][V_k[i].second] = true;
//         cnt++;
//     }

//     while(!Q.empty()) {
//         int r, c;
//         tie(r, c) = Q.front();
//         Q.pop();

//         for(int j = 0; j < 4; j++) {
//             int nr = r + dr[j];
//             int nc = c + dc[j];

//             if(nr >= 0 && nr < N && nc >= 0 && nc < N && visited[nr][nc] == false
//             && abs(arr[nr][nc] - arr[r][c]) >= U && abs(arr[nr][nc] - arr[r][c]) <= D) {

//                 Q.push({nr, nc});
//                 visited[nr][nc] = true;
//                 cnt++;
//             }
//         }
//     }

//     if(cnt > max_cnt) {
//         max_cnt = cnt;
//     }

// }


// // idx : 0 ~ N*N-1 까지의 인덱스
// void chooseK(int idx, int cnt) { // cnt : 고른 점의 개수

//     // K개를 다 고른 경우
//     if(cnt == K) {

//         // 여기서 BFS 돌리기
//         BFS();

//         return;
//     }

//     // K개를 다 고르지 못한 경우
//     if(idx == N * N) {
//         return;
//     }

//     // 1차원 idx를 2차원 좌표(r,c)로 바꾸는 방법
//     int r = idx / N;
//     int c = idx % N;

//     // r,c를 선택하는 경우
//     V_k.push_back({r, c});
//     chooseK(idx+1, cnt+1);
//     V_k.pop_back();

//     // r,c를 선택하지 않고 넘어가는 경우
//     chooseK(idx+1, cnt);

// }

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> N >> K >> U >> D;

//     for(int i = 0; i < N; i++) {
//         for(int j = 0; j < N; j++) {
//             cin >> arr[i][j];
//         }
//     }

//     chooseK(0, 0);

//     cout << max_cnt;


//     return 0;
// }

#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int n, k, u, d;
int arr[8][8];
bool visited[8][8];
int max_city = INT_MIN; // 고를 수 있는 서로 다른 도시의 최대 개수

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

vector<pair<int, int>> V; // 전체 도시를 담는 벡터
vector<pair<int, int>> city; // 고른 도시를 담는 벡터

// 3 2 2 3
// 1 2 3
// 2 4 5
// 2 1 5
// 출력
// 6

bool inRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n);
}

int bfs() {
    queue<pair<int, int>> Q;
    memset(visited, false, sizeof(visited));

    int cnt = 0;

    for (int i = 0; i < city.size(); i++) {
        int r = city[i].first;
        int c = city[i].second;
        Q.push({r,c});
        visited[r][c] = true;
        cnt++;
    }

    while (!Q.empty()) {
        int cr = Q.front().first;
        int cc = Q.front().second;
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nr = cr + dr[dir];
            int nc = cc + dc[dir];

            if (!inRange(nr, nc)) continue;
            if (visited[nr][nc]) continue;
            if (abs(arr[nr][nc] - arr[cr][cc]) < u) continue;
            if (abs(arr[nr][nc] - arr[cr][cc]) > d) continue;

            Q.push({nr,nc});
            visited[nr][nc] = true;
            cnt++;
        }
    }
    return cnt;
}

// k개의 도시를 골라야함 1 <= k <= min(n, 3)
// 1 <= n <= 8
void choose(int start, int end) { // 시작도시, 지금까지 고른 도시의 수
    if (end == k) {
        max_city = max(max_city, bfs());
        return;
    }

    for (int i = start; i < V.size(); i++) {
        int r = V[i].first;
        int c = V[i].second;

        city.push_back({r,c});

        choose(i+1, end+1);

        city.pop_back();
    }
}

int main() {

    cin >> n >> k >> u >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            V.push_back({i,j});
        }
    }

    choose(0, 0);

    cout << max_city;

    return 0;
}