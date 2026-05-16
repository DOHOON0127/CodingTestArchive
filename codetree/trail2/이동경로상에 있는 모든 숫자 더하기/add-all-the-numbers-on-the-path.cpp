#include <bits/stdc++.h>
using namespace std;

int arr[100][100]; // 배열
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int main () {
    int N, T;
    string LRF;

    cin >> N >> T;

    cin >> LRF;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    // 초기위치 정하기
    int sr = N / 2;
    int sc = N / 2;

    // 초기방향은 북쪽
    int dir_num = 3;
    int nr = 0;
    int nc = 0;

    int sum = arr[sr][sc];

    for (int i = 0; i < T; i++) {
        if (LRF[i] == 'L') {
            dir_num = (dir_num - 1 + 4) % 4;
        }
        else if (LRF[i] == 'R') {
            dir_num = (dir_num + 1) % 4;
        }
        else if (LRF[i] == 'F') {
            nr = sr + dr[dir_num];
            nc = sc + dc[dir_num];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N) {

            }else {
                sum += arr[nr][nc];
                sr = nr;
                sc = nc;
            }
        }
    }

    cout << sum;
}