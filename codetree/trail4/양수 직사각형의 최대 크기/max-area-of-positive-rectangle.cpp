#include <bits/stdc++.h>
#include <climits>
using namespace std;

int arr[21][21];
int max_val = INT_MIN;

bool isPositive(int r1, int c1, int r2, int c2) {
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            if (arr[i][j] <= 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M; // row, col
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int r1 = 0; r1 < N; r1++) {
        for (int c1 = 0; c1 < M; c1++) {

            for (int r2 = 0; r2 < N; r2++) {
                if (r2 < r1) {
                    continue;
                }
                for (int c2 = 0; c2 < M; c2++) {
                    if (c2 < c1) {
                        continue;
                    }
                    if (isPositive(r1, c1, r2, c2)) {
                        if ((r2-r1+1) * (c2-c1+1) > max_val) {
                            max_val =  (r2-r1+1) * (c2-c1+1);
                        }
                    }
                }
            }
        }
    }

    if (max_val < 0) {
        cout << -1;
    }else {
        cout << max_val;
    }
}