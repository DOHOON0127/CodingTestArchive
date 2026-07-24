#include <iostream>
using namespace std;

int N;
int arr[100][100];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool inRange(int r, int c) {
    return (r >= 0 && r < N && c >= 0 && c < N);
}

int f_cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {

            int cnt = 0;
            
            for(int dir = 0; dir < 4; dir++) {
                int nr = i + dr[dir];
                int nc = j + dc[dir];

                if(inRange(nr, nc) && arr[nr][nc] == 1) {
                    cnt += 1;
                }
            }

            if(cnt >= 3) {
                f_cnt += 1;
            }
        }
    }

    cout << f_cnt;

    return 0;
}