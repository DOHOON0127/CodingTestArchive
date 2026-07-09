#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int N,H,M;
int arr[104][104];
bool visited[104][104];
int ans[104][104];
int min_dist[104][104];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int BFS(int i, int j) {

    queue<pair<int, int>> Q;

    Q.push({i, j});
    visited[i][j] = true;
    
    while(!Q.empty()) {

        int r,c;
        tie(r,c) = Q.front();
        Q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < N && nc >= 0 && nc < N && visited[nr][nc] == false
            && arr[nr][nc] != 1) {

                if(arr[nr][nc] == 3) {
                    min_dist[nr][nc] = min_dist[r][c] + 1;
                    return min_dist[nr][nc];
                }

                Q.push({nr, nc});
                visited[nr][nc] = true;
                min_dist[nr][nc] = min_dist[r][c] + 1;

            }
        }

    }

    return -1;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> H >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {

            if(arr[i][j] == 2){
                memset(visited, false, sizeof(visited));
                memset(min_dist, 0, sizeof(min_dist));

                ans[i][j] =  BFS(i, j);
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }



    return 0;
}