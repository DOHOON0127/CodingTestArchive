#include <iostream>
#include <queue>

using namespace std;

int n, k;
int grid[100][100];
int r[10000], c[10000];
bool visited[100][100];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int cnt;

void BFS(int curr_r, int curr_c) {

    queue<pair<int, int>> Q;

    if(visited[curr_r][curr_c] == false) {
        Q.push({curr_r, curr_c});
        visited[curr_r][curr_c] = true;

        cnt++;
    }

    while(!Q.empty()) {

        int r = Q.front().first;
        int c = Q.front().second;

        Q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < n 
            && visited[nr][nc] == false && grid[nr][nc] == 0) {

                Q.push({nr, nc});
                visited[nr][nc] = true;

                cnt++;

            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            cin >> grid[i][j];

    for (int i = 0; i < k; i++) 
        cin >> r[i] >> c[i];

    // Please write your code here.

    
    for(int i = 0; i < k; i++) {

        int o_r = r[i] - 1;
        int o_c = c[i] - 1;

        BFS(o_r, o_c);
    }

    cout << cnt;

    return 0;
}
