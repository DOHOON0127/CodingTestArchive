#include <iostream>

using namespace std;

int n;
int grid[100][100];
bool visited[100][100];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int count;

void DFS(int curr_r, int curr_c) {

    visited[curr_r][curr_c] = true;

    for(int i = 0; i < 4; i++) {
        int nr = curr_r + dr[i];
        int nc = curr_c + dc[i];

        if(nr >= 0 && nc >= 0 && nr < n && nc < n 
        && visited[nr][nc] == false 
        && (grid[curr_r][curr_c] == grid[nr][nc])) {
            
            DFS(nr, nc);
            count++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int boomBlock = 0;
    int maxBlock = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            count = 1;
            if(visited[i][j] == false) {
                DFS(i, j);

                if(count > maxBlock) {
                    maxBlock = count;
                }

                if(count >= 4) {
                    boomBlock++;
                }

            }
        }
    }

    
    cout << boomBlock << ' ' << maxBlock;



    return 0;
}
