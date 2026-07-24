#include <iostream>
using namespace std;

int n;
char c; // 방향
int dis; // 거리
int arr[100][100];

// 0 -> N
// 1 -> E
// 2 -> S
// 3 -> W
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int dir;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int x = 0;
    int y = 0;
    int time = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> c >> dis;

        if(c == 'N') {
            dir = 0;
        }else if(c == 'E'){
            dir = 1;
        }else if(c == 'S') {
            dir = 2;
        }else {
            dir = 3;
        }

        for(int j = 0; j < dis; j++) {
            x = x + dx[dir];
            y = y + dy[dir];

            time++;

            if(x == 0 && y == 0) {
                cout << time;
                return 0;
            }
        }
    }

    cout << -1;

    return 0;
}