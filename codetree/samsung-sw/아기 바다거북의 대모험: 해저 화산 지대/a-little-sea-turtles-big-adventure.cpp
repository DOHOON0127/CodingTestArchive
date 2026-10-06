#include <bits/stdc++.h>
using namespace std;

int n,m,k,t;// 격자크기, 바다거북수, 화산수, 턴수
int arr[20][20]; // 빈공간, 산호초 저장 배열
int arr_move[20][20]; // 거북이 이동할떄 확인 배열, 굳어버린 화석도 여기 표현
bool visited[20][20];
int turn[10] = {-1, };
// pair<int, int> arr_turtle[10];

struct Turtle {
    int r;
    int c;
    bool isEnd = false;
};

Turtle arr_turtle[10];

struct Volc {
    int r;
    int c;
    int p;
    int mag = 0;
    bool isOut = false; // 이번 턴에 분출을 일으켰나 아닌가
};
Volc volcs[10];

bool inRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n);
}

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0}; // 우 하 좌 상

int dist[20][20];
// 최단 경로가 존재하는지 파악하는 함수
// nono -> 안식처에서 역으로 BFS 돌리기
void BFS() {
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> Q;
    Q.push({n-1,n-1});
    dist[n-1][n-1] = 0;

    while (!Q.empty()) {
        int cr = Q.front().first;
        int cc = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!inRange(nr, nc)) continue;
            if (arr[nr][nc] == 1) continue;
            if (arr_move[nr][nc] == 1) continue; // 산호초거나, 다른 거북이가 있다면 1
            if (dist[nr][nc] != -1) continue;

            dist[nr][nc] = dist[cr][cc] + 1;
            Q.push({nr, nc});

        }
    }
}

// 바다 거북 이동 함수
// 앞선 거북이의 이동 결과가 반영되어야 함
// 최단 경로가 존재하는 방향으로 움직여야 함
void moveTurtle() {
    for (int i = 0; i < m; i++) {
        if (arr_turtle[i].isEnd == true) continue; // 화석이 되버렸다면 넘기기
        if (turn[i] != -1) continue;

        int r = arr_turtle[i].r;
        int c = arr_turtle[i].c;

        arr_move[r][c] = 0; // 자기 위치 잠깐 제거

        BFS();

        if (dist[r][c] == -1) {
            arr_move[r][c] = 1;
            continue;
        }
        // 우 하 좌 상
        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (!inRange(nr, nc)) continue;
            if (arr[nr][nc] == 1) continue;
            if (arr_move[nr][nc] == 1) continue; // 산호초거나, 다른 거북이가 있다면 1

            if (dist[nr][nc] != dist[r][c] - 1) continue;

            arr_turtle[i].r = nr;
            arr_turtle[i].c = nc;
            if (nr == n-1 && nc == n-1) {
                turn[i] = t; // 해당 턴을 도착 시간으로 기록
            }
            else {
                arr_move[nr][nc] = 1;
            }
            break;

        }
    }
}

// 화산 압력 증가 함수
void increaseMag() {
    for (int i = 0; i < k; i++) {
        volcs[i].mag += 10;
    }
}

// 열기 분출함수
// 1. 열기 전파
// 2. 연쇄 반응
// 3. 바다거북 화석 만들기

int fire[20][20]; // 열기 저장 배열
int fire_dr[4] = {-1, 1, 0, 0};
int fire_dc[4] = {0, 0, -1, 1}; // 상, 하, 좌, 우

bool isVolcOut() {
    for (int i = 0; i < k; i++) {
        if (!volcs[i].isOut) {
            if (volcs[i].mag + fire[volcs[i].r][volcs[i].c] >= volcs[i].p) {
                return true;
            }
        }
    }
    return false;
}

void outFire() {
    // 열기 전파 처음
    for (int i = 0; i < k; i++) {
        if (volcs[i].mag >= volcs[i].p) {
            int r = volcs[i].r;
            int c = volcs[i].c;
            fire[r][c] += volcs[i].p;

            for (int dir = 0; dir < 4; dir++) {
                int nr = r + fire_dr[dir];
                int nc = c + fire_dc[dir];
                int f = fire[r][c];

                while (inRange(nr, nc) && arr[nr][nc] != 1) {
                    f = (f / 2);
                    fire[nr][nc] += f;
                    nr += fire_dr[dir];
                    nc += fire_dc[dir];
                }
            }
            volcs[i].isOut = true;
        }
    }
}

void sideEffect() {
    // 이제 연쇄 반응이 일어나야 하는데,,
    while (isVolcOut()) {
        for (int i = 0; i < k; i++) {
            if (!volcs[i].isOut) {
                if (volcs[i].mag + fire[volcs[i].r][volcs[i].c] >= volcs[i].p) {
                    int r = volcs[i].r;
                    int c = volcs[i].c;
                    fire[r][c] += volcs[i].p;

                    for (int dir = 0; dir < 4; dir++) {
                        int nr = r + fire_dr[dir];
                        int nc = c + fire_dc[dir];
                        int f = volcs[i].p;

                        while (inRange(nr, nc) && arr[nr][nc] != 1) {
                            f = (f / 2);
                            fire[nr][nc] += f;
                            nr += fire_dr[dir];
                            nc += fire_dc[dir];
                        }
                    }
                    volcs[i].isOut = true;
                }
            }
        }
    }
}

void chageTurtle() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] != 1 && arr_move[i][j] == 1 && (fire[i][j] >= 20)) {

                for (int p = 0; p < m; p++) {
                    if (arr_turtle[p].r == i && arr_turtle[p].c == j) {
                        arr_turtle[p].isEnd = true;
                        arr_move[i][j] = 1;
                    }
                }

            }
        }
    }
}

// 환경 초기화
void init_curr() {
    memset(fire, 0, sizeof(fire));
    for (int i = 0; i < k; i++) {
        if (volcs[i].isOut) {
            volcs[i].mag = 0;
            volcs[i].isOut = false;
        }
    }
}

void printLocate() {
    for (int i = 0; i < m; i++) {
        cout << arr_turtle[i].r << " " << arr_turtle[i].c << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                arr_move[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> arr_turtle[i].r >> arr_turtle[i].c;
        int r = arr_turtle[i].r;
        int c = arr_turtle[i].c;

        arr_move[r][c] = 1; // 여기서 거북이의 위치도 1로 만들었고, 이 배열은 지속적으로 변함
    }

    for (int i = 0; i < k; i++) {
        cin >> volcs[i].r >> volcs[i].c >> volcs[i].p;
    }

    fill(turn, turn+10, -1);

    while (++t) {

        if (t >= 101) break;

        moveTurtle();

        increaseMag();

        outFire();

        sideEffect();

        chageTurtle();

        init_curr();
    }

    for (int i = 0; i < m; i++) {
        cout << turn[i] << '\n';
    }

    return 0;
}

