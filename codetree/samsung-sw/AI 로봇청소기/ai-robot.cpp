#include <bits/stdc++.h>
using namespace std;

int n,k,l; // 배역 크기, 로봇 청소기 개수, 테스트 횟수
int arr[30][30]; // 먼지 저장 배열, -1은 물건이 위치함
struct Robot {
    int r;
    int c;
};
Robot robots[50];

// 총 먼지량 출력 함수
int printSumDust() {
    int sumDust = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] > 0) {
                sumDust += arr[i][j];
            }
        }
    }
    return sumDust;
}

int arr_dist[30][30]; // 거리 저장 배열
bool visited[30][30];
int dr[4] = {0, -1, 0, 1}; // 좌 상 우 하
int dc[4] = {-1, 0, 1, 0};

bool inRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n);
}

void BFS(int t) { // 로봇청소기의 초기위치가 들어옴 -> 이를 기준으로 BFS 돌려서 거리 측정
    // t번 로봇청소기인지도 알아야 함
    memset(arr_dist, -1, sizeof(arr_dist));
    memset(visited, false, sizeof(visited));

    queue<pair<int, int>> Q;
    int r = robots[t].r;
    int c = robots[t].c;
    Q.push({r,c});
    visited[r][c] = true;
    arr_dist[r][c] = 0;

    while (!Q.empty()) {
        int cr = Q.front().first;
        int cc = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            bool isRobot = false;
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!inRange(nr, nc)) continue;
            if (visited[nr][nc]) continue;
            if (arr[nr][nc] == -1) continue;
            // 로봇 있는 위치인지도 체크해야됨
            for (int p = 0; p < k; p++) {
                if (p == t) continue;
                if (robots[p].r == nr && robots[p].c == nc) {
                    isRobot = true;
                }
            }
            if (isRobot) continue;

            arr_dist[nr][nc] = arr_dist[cr][cc] + 1;
            visited[nr][nc] = true;
            Q.push({nr,nc});
        }
    }

    int clo_r = r;
    int clo_c = c;
    int min_dist = INT_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr_dist[i][j] < 0) continue;
            if (arr[i][j] <= 0) continue;
            // 이동거리가 가까우면서 오염된 격자인경우
            if (min_dist > arr_dist[i][j]) {
                min_dist = arr_dist[i][j];
                clo_r = i;
                clo_c = j;
            }
        }
    }
    // 로봇 위치 갱신
    robots[t].r = clo_r;
    robots[t].c = clo_c;
}

// 청소하는 함수
// 청소할 수 있는 4가지 격자
// 청소할 수 있는 먼지량이 가장 큰 방향에서 청소 시작

void cleanArr() {
    // 청소할 수 있는 먼지량을 구하면서 시작해야 하는데,,,
    // 일단 청소기 순서대로 진행되니까
    int isCleanDust = 0; // 청소할 수 있는 먼지량 (얘가 큰 방향에서부터 청소 시작)
    int curr_dir = 0;
    for (int i = 0; i < k; i++) {
        int r = robots[i].r;
        int c = robots[i].c;

        int temp_isCleanDust = 0;

        for (int cdr = 0; cdr < 4; cdr++) {
            isCleanDust = min(arr[r][c],20);
            for (int dir = 0; dir < 4; dir++) {
                // bool isRobot = false;
                if (dir == cdr) continue;
                int nr = r + dr[dir];
                int nc = c + dc[dir];

                if (!inRange(nr, nc)) continue;
                if (arr[nr][nc] == -1) continue;
                // // 로봇 있는 위치인지도 체크해야됨
                // for (int p = 0; p < k; p++) {
                //     if (p == i) continue;
                //     if (robots[p].r == nr && robots[p].c == nc) {
                //         isRobot = true;
                //     }
                // }
                // if (isRobot) continue;

                isCleanDust += min(20, arr[nr][nc]); // 새로운 4칸에 담겨있는 청소할 수 있는 먼지량의 합
            }
            if (cdr == 0) {
                temp_isCleanDust = isCleanDust;
                curr_dir = cdr;
            }else {
                if (temp_isCleanDust < isCleanDust) {
                    curr_dir = cdr;
                    temp_isCleanDust = isCleanDust;
                }
            }
        }
        if (arr[r][c] - 20 <= 0) {
            arr[r][c] = 0;
        }else {
            arr[r][c] -= 20;
        }
        for (int d = 0; d < 4; d++) {
            if (d == curr_dir) continue;
            // bool isRobot = false;

            int nr = r + dr[d];
            int nc = c + dc[d];

            if (!inRange(nr, nc)) continue;
            if (arr[nr][nc] == -1) continue;
            // 로봇 있는 위치인지도 체크해야됨
            // for (int p = 0; p < k; p++) {
            //     if (p == i) continue;
            //     if (robots[p].r == nr && robots[p].c == nc) {
            //         isRobot = true;
            //     }
            // }
            // if (isRobot) continue;

            if (arr[nr][nc] - 20 <= 0) {
                arr[nr][nc] = 0;
            }else {
                arr[nr][nc] -= 20;
            }
        }
    }
}

// 동시에 먼지가 확산되는걸 표현하기 위한 새로운 배열
int temp_dust[30][30];

// 4방향 뒤져서 먼지합 구하고 그걸 10으로 나눈 몫을 반환
int find_four_space(int r, int c) {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (!inRange(nr, nc)) continue;
        if (arr[nr][nc] == -1) continue;

        sum += arr[nr][nc];
    }
    if (sum == 0) {
        return 0;
    }
    return sum / 10;
}

void spreadDust() {
    memset(temp_dust, 0, sizeof(temp_dust));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0) {
                temp_dust[i][j] = find_four_space(i, j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (temp_dust[i][j] > 0) {
                arr[i][j] = temp_dust[i][j];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> l;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> robots[i].r >> robots[i].c;
        robots[i].r--;
        robots[i].c--;
    }

    while (l--) {
        // 1. 청소기 이동
        for (int i = 0; i < k; i++) {
            BFS(i);
        }

        // 2. 청소
        cleanArr();

        // 3. 먼지 축적
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] > 0) {
                    arr[i][j] += 5;
                }
            }
        }

        // 4. 먼지 확산
        spreadDust();

        // 5. 출력
        int sumD = printSumDust();
        cout << sumD << '\n';
        if (sumD == 0) break;
    }

    return 0;
}

