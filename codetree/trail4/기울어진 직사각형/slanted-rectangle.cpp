#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int n;
int arr[20][20];
int max_num = INT_MIN;

// 5
// 1 2 2 2 2
// 1 3 4 4 4
// 1 2 3 3 3
// 1 2 3 3 3
// 1 2 3 3 3

int dr[4] = {-1, -1, 1, 1};
int dc[4] = {1, -1, -1, 1};

bool inRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n);
}

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i < n-1; i++) {
        for (int j = n-1-i; j >= 1; j--) {
            // i : 오른쪽 위로 증가하는 횟수 (1번 = 3번)
            // j : 왼쪽 위로 증가하는 횟수 (2번 = 4번)
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < n; c++) { // 시작위치

                    int temp_max = 0;
                    bool isGo = true;

                    int cr = r;
                    int cc = c;

                    for (int dir = 0; dir < 4; dir++) {
                        if (dir == 0 || dir == 2) {
                            for (int t = 0; t < i; t++) {
                                int nr = cr + dr[dir];
                                int nc = cc + dc[dir];

                                if (!inRange(nr, nc)) {
                                    isGo = false;
                                    break;
                                }
                                temp_max += arr[nr][nc];
                                cr = nr;
                                cc = nc;
                            }
                            if (!isGo) {
                                break;
                            }
                        }
                        else {
                            for (int t = 0; t < j; t++) {
                                int nr = cr + dr[dir];
                                int nc = cc + dc[dir];

                                if (!inRange(nr, nc)) {
                                    isGo = false;
                                    break;
                                }
                                temp_max += arr[nr][nc];
                                cr = nr;
                                cc = nc;
                            }
                            if (!isGo) {
                                break;
                            }
                        }
                    }
                    if (isGo) {
                        max_num = max(max_num, temp_max);
                    }
                }
            }

        }
    }

    cout << max_num;

    return 0;
}
