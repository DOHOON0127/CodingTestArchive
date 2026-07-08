#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M, cnt;
int arr[104][104];
int min_dist[104][104];
bool visited[104][104];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void BFS() {

    queue<pair<int, int>> Q;

    Q.push({0,0});
    visited[0][0] = true;
    min_dist[0][0] = 0;

    while(!Q.empty()) {
        int r,c;
        tie(r,c) = Q.front();
        Q.pop();
        cnt++;

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < N && nc >= 0 && nc < M && visited[nr][nc] == false
            && arr[nr][nc] == 1) {

                Q.push({nr,nc});
                visited[nr][nc] = true;
                min_dist[nr][nc] = min_dist[r][c] + 1; 

            }
        }


    }


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
            // 뱀이 있으면 0, 없으면 1
            // 시작은 0,0 끝은 n-1, m-1
        }
    }

    BFS();

    if(min_dist[N-1][M-1] == 0) {
        cout << -1;
    }
    else {
        cout << min_dist[N-1][M-1];
    }

    return 0;
}