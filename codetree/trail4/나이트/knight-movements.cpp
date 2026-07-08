#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n;
int r1, c1, r2, c2;

int arr[104][104];
int min_dist[104][104];
bool visited[104][104];

int dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void BFS() {

    queue<pair<int, int>> Q;
    
    Q.push({r1-1, c1-1});
    visited[r1-1][c1-1] = true;
    min_dist[r1-1][c1-1] = 0;

    while(!Q.empty()) {
        int r,c;
        tie(r,c) = Q.front();
        Q.pop();

        if(r == r2-1 && c == c2-1) {
            cout << min_dist[r][c];
            return;
        }

        for(int i = 0; i < 8; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < n 
            && visited[nr][nc] == false) {
                
                Q.push({nr, nc});
                visited[nr][nc] = true;
                min_dist[nr][nc] = min_dist[r][c] + 1;

            }
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    // Please write your code here.

    if(r1 == r2 && c1 == c2) {
        cout << 0;
        return 0;
    }

    BFS();

    if(min_dist[r2-1][c2-1] == 0) {
        cout << -1;
    }

    return 0;
}
