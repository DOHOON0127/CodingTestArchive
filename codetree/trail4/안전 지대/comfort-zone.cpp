#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

int N, M;
int grid[50][50];
bool visited[50][50];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int findGridMax() {
    int gridMax = INT_MIN;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(grid[i][j] > gridMax) {
                gridMax = grid[i][j];
            }
        }
    }

    return gridMax;
}

void DFS(int curr_r, int curr_c, int k) {
    
    visited[curr_r][curr_c] = true;

    for(int i = 0; i < 4; i++) {
        int nr = curr_r + dr[i];
        int nc = curr_c + dc[i];

        if(nr >= 0 && nc >= 0 && nr < N && nc < M 
        && visited[nr][nc] == false && grid[nr][nc] > k) {

            visited[nr][nc] = true;
            DFS(nr, nc, k);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    int K = findGridMax();

    int max_areas = 0;
    int max_K = 1;
    
    for(int k = 1; k < K; k++) {
        memset(visited, false, sizeof(visited));
        int curr_safe_areas = 0;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(grid[i][j] > k && visited[i][j] == false) {
                    DFS(i, j, k); 
                    curr_safe_areas++;
                }
            }
        }

        if(curr_safe_areas > max_areas){
            max_areas = curr_safe_areas;
            max_K = k;
        }
    }

    cout << max_K << ' ' << max_areas;


    return 0;
}
