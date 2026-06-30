#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, K, curr_r, curr_c;
int arr[104][104];
bool visited[104][104];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
bool isEnd;

void BFS(int r, int c) {

    queue<pair<int, int> > Max_Q; // 최대 값을 가지고 있는 좌표를 저장 할 큐

    memset(visited, false, sizeof(visited));

    queue<pair<int, int> > Q;
    Q.push({r, c});
    visited[r][c] = true;

    int curr_val = arr[r][c]; // 현재 칸의 값
    int curr_max = 0; //현재 최소 값

    int last_r = 0;
    int last_c = 0;

    while(!Q.empty()) {

        int n_r = Q.front().first;
        int n_c = Q.front().second;

        Q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = n_r + dr[i];
            int nc = n_c + dc[i];

            if(nr >= 0 && nr < N && nc >= 0 && nc < N 
            && arr[nr][nc] < curr_val && visited[nr][nc] == false) {

                if(arr[nr][nc] > curr_max) {
                    curr_max = arr[nr][nc];
                }

                visited[nr][nc] = true;
                Q.push({nr, nc});
                
            }
        }
    }

    if(curr_max == 0) {
        isEnd = true;
        return;
    }

    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            
            if(visited[i][j] == true && arr[i][j] == curr_max) {
                Max_Q.push({i, j});
            }
        }
    }

    curr_r = Max_Q.front().first + 1;
    curr_c = Max_Q.front().second + 1; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    cin >> curr_r >> curr_c;

    for(int i = 0; i < K; i++) {

        if(isEnd) {
            break;
        }

        BFS(curr_r - 1, curr_c - 1);

    }

    cout << curr_r << " " << curr_c;

    return 0;
}