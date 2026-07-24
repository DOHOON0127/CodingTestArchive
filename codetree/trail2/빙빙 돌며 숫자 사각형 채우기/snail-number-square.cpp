#include <iostream>
using namespace std;

int N, M;
int dir;
int arr[101][101];
int r, c;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

bool inRange(int r, int c) {
    return (r >= 0 && r < N && c >= 0 && c < M);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    arr[0][0] = 1;

    while(true) {

        int temp = arr[r][c];

        r += dr[dir];
        c += dc[dir];


        if(inRange(r, c) && arr[r][c] == 0) {
           
            arr[r][c] = temp + 1;
           
        }
        else {
            r -= dr[dir];
            c -= dc[dir];

            dir = (dir + 1) % 4;
        }

        int iCount = 0;
        for(int i = 0; i < 4; i ++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(!inRange(nr, nc) || arr[nr][nc] != 0) {
                iCount++;
            }

        }

        if(iCount == 4) {
            break;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }


    return 0;
}