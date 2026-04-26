#include <bits/stdc++.h>
using namespace std;

string arr[1004];
int distJ[1004][1004]; // 지훈이 이동시간
int distF[1004][1004]; // 불의 전파 시간

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int R, C;
int start_JR, start_JC;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;

    // fill(시작 주소, 끝 주소, 채울 값);
    // 시작 주소부터 끝 주소 바로 앞까지, 원하는 값으로 채움
    for (int i = 0; i < R; i++) {
        fill(distJ[i], distJ[i]+C, -1);
        fill(distF[i], distF[i]+C, -1);
    }

    queue<pair<int, int> > QJ; // 지훈이 큐
    queue<pair<int, int> > QF; // 불 큐

    for (int r = 0; r < R; r++) {
        cin >> arr[r];

        for (int c = 0; c < C; c++) {
            // 문자열 자르면 단일 문자
            if (arr[r][c] == 'J') {
                QJ.push({r, c});
                distJ[r][c] = 0;
            }
            if (arr[r][c] == 'F') {
                QF.push({r, c});
                distF[r][c] = 0;
            }
        }
    }
    
    // 불에 대한 BFS
    while (!QF.empty()) {
        int Fr = QF.front().first;
        int Fc = QF.front().second;

        QF.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nr = Fr + dr[dir];
            int nc = Fc + dc[dir];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (distF[nr][nc] >= 0 || arr[nr][nc] == '#') continue;

            distF[nr][nc] = distF[Fr][Fc] + 1;
            QF.push({nr, nc});
        }
    }

    // 지훈이에 대한 BFS
    while (!QJ.empty()) {
        int Jr = QJ.front().first;
        int Jc = QJ.front().second;

        QJ.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nr = Jr + dr[dir];
            int nc = Jc + dc[dir];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
                cout << distJ[Jr][Jc] + 1;
                return 0;
            }
            if (distJ[nr][nc] >= 0 || arr[nr][nc] == '#') continue;
            if (distF[nr][nc] != -1 && distF[nr][nc] <= distJ[Jr][Jc] + 1) continue;


            distJ[nr][nc] = distJ[Jr][Jc] + 1;
            QJ.push({nr, nc});
        }
    }
    cout << "IMPOSSIBLE";
}