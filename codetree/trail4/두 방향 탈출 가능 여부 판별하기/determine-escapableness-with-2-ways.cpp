#include <iostream>
using namespace std;

int N,M;
int arr[104][104];
bool visited[104][104];
bool is_end = false; // 탈출가능.

int dr[2] = {1, 0};
int dc[2] = {0, 1};

void DFS(int curr_r, int curr_c) {

    for(int i = 0; i < 2; i++) {
        int nr = curr_r + dr[i];
        int nc = curr_c + dc[i];

        if(nr >= 0 && nr < N && nc >= 0 && nc < M && visited[nr][nc] == false && arr[nr][nc] != 0) {
            
            visited[nr][nc] = true;
            if(nr == N-1 && nc == M-1){
                is_end = true;
            }
            DFS(nr, nc);
            
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
        }
    }

    visited[0][0] = true;
    DFS(0, 0);

    if(is_end) {
        cout << 1;
    }else{
        cout << 0;
    }

    return 0;
}