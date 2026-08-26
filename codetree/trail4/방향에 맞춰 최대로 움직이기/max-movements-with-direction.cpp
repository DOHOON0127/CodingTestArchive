#include <iostream>
#include <climits>
using namespace std;

// 격자 n x n 
// 1이상 n x n 이하 정수
// 수는 중복 없이 주어진다
// 방향을 8개 중 하나
// 특정 위치에서 시작, 현재 위치에 적혀있는 방향에 있는 수들 중,
// 현재 수보다 더 큰수가 적혀있는 곳으로 이동하는데
// 이걸 최대한 많이

// 격자 초기 상태가 주어지면 -> 시작 위치로부터 조건을 만족하며 최대 몇 번 이동?


int arr[4][4]; // 격자
int dir[4][4]; // 방향을 가지고 있는 격자
int n;// 격자 크기
int s_r, s_c; // 시작 위치
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int max_move = INT_MIN;

bool inRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n);
}

// 재귀함수, 방향에 갈 수 있는 수가 없거나, 전부 다 갔다면 종료
void move_many(int r, int c, int cnt) {
    max_move = max(max_move, cnt);

    int d = dir[r][c];

    int nr = r + dr[d];
    int nc = c + dc[d];

    while(inRange(nr, nc)) {
        if(arr[nr][nc] > arr[r][c]) {
            move_many(nr, nc, cnt+1);
        }

        nr += dr[d];
        nc += dc[d]; 
    }
}

int main() {

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }   
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> dir[i][j];
            dir[i][j]--;
        }
    }

    cin >> s_r >> s_c;
    s_r--;
    s_c--;

    move_many(s_r, s_c, 0);
      

    cout << max_move;

    return 0;
}