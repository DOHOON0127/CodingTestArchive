#include <iostream>
using namespace std;

int n, t;
int r, c; // 구슬의 초기 위치
char D; // 초기 구슬의 이동 방향 - U, D, R, L 중 하나 위 아래 오른쪽 왼쪽

// 벽에 부딪히면 방향이 반대로 뒤집히는데 이것도 1만큼의 시간이 소요됨

int dr[4] = {0, 1, -1, 0};
int dc[4] = {1, 0, 0, -1};

int arr[51][51];

int dir;

bool inRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> t;

    cin >> r >> c >> D;

    r--;
    c--;

        if(D == 'U') {
            dir = 2;
        }else if(D == 'D'){
            dir = 1;
        }else if(D == 'R') {
            dir = 0;
        }else {
            dir = 3;
        }

    while(t--) {

        r += dr[dir];
        c += dc[dir];

        if(inRange(r,c)) {

        }else{
            r -= dr[dir];
            c -= dc[dir];
            dir = 3 - dir;
        }
    }

    cout << r+1 << ' ' << c+1;

    return 0;
}