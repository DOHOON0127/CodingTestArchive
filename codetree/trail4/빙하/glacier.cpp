#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int N, M;
int ice[201][201];
int ice_w[201][201];
bool visited[201][201];
bool w_visited[201][201];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int iCnt, lastIceSize;

void outIce() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << ice[i][j] << ' ';
        }
        cout << '\n';
    }
}

// 1로 둘러쌓인 0을 2로 만들기
void findWaterIce() {

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            ice_w[i][j] = ice[i][j];
        }
    }

    memset(w_visited, false, sizeof(w_visited));

    queue<pair<int, int>> Q_water;

    w_visited[0][0] = true;
    Q_water.push({0,0});
    ice_w[0][0] = 1;

    while(!Q_water.empty()) {
        int r, c;
        tie(r,c) = Q_water.front();
        Q_water.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < N && nc >= 0 && nc < M && w_visited[nr][nc] == false 
            && ice[nr][nc] == 0) {
                ice_w[nr][nc] = 1;
                Q_water.push({nr, nc});
                w_visited[nr][nc] = true;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(ice_w[i][j] == 0) {
                ice[i][j] = 2;
            }
        }
    }

}

// 한번 전체 BFS돌리고 2를 -> 0으로 초기화
void find2to0() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(ice[i][j] == 2){
                ice[i][j] = 0;
            }
        }
    }
}

bool find0(int r, int c) {

    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(ice[nr][nc] == 0) {
            return true;
        }
    }

    return false;
}

bool noIce() {
    int cnt = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(ice[i][j] == 1){
                cnt++;
            }
        }
    }

    if(cnt == 0) {
        return true;
    }
    else {
        return false;
    }

}

void lastIce() {
    int cnt = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(ice[i][j] == 1){
                cnt++;
            }
        }
    }

    lastIceSize = cnt;
}

void meltIce() {

    queue<pair<int, int> > Q;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(ice[i][j] == 1 && visited[i][j] == false && find0(i,j) == true) {
                visited[i][j] = true;
                Q.push({i, j});
            }
        }
    }

    while(!Q.empty()) {
        int r, c;
        tie(r, c) = Q.front();
        Q.pop();
        ice[r][c] = 0;
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> ice[i][j];
            ice_w[i][j] = ice[i][j];
        }
    }

    // 빙하가 전부 녹는데 걸리는 시간, 마지막으로 녹은 빙하의 크기

    while(!noIce()) {

        findWaterIce();

        lastIce();

        meltIce();

        iCnt++;

        find2to0();

    }

    cout << iCnt << ' ' << lastIceSize;

    return 0;
}