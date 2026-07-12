#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

int n, k;
int grid[100][100];
bool visited[100][100];
int min_dist[100][100];

vector<pair<int, int>> V_before;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void BFS() {

    queue<pair<int, int>> Q;
    
    for(int i = 0; i < (int)V_before.size(); i++) {
        Q.push(V_before[i]);
    }

    while(!Q.empty()) {
        int r, c;
        tie(r, c) = Q.front();
        visited[r][c] = true;
        Q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < n && visited[nr][nc] == false
            && grid[nr][nc] == 1) {

                Q.push({nr, nc});
                visited[nr][nc] = true;
                min_dist[nr][nc] = min_dist[r][c] + 1;

            }
        }
    }


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(visited[i][j] == false && grid[i][j] == 1) {
                min_dist[i][j] = -2;
            }
        }
    }


}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];

            if(grid[i][j] == 0) {
                min_dist[i][j] = -1;
            }

            if(grid[i][j] == 2) {
                V_before.push_back({i, j});
            }
        }
    }

    BFS();


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << min_dist[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
