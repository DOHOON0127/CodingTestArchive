#include <bits/stdc++.h>
using namespace std;

int arr[21][21];

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    // 시작위치에 대한 고민
    // 0,0 0,1 0,2
    // 1,0 1,1 1,2
    // 2,0 2,1 2,2
    // 여기까지 가면 완탐

    int max_sum = 0;

    for(int i = 0; i <= N - 3; i++) {
        for(int j = 0; j <= N - 3; j++) {
            
            int sum = 0;

            for(int n = 0; n < 3; n++) {
                for(int k = 0; k < 3; k++) {
                    sum += arr[i+n][j+k];
                }
            }

            max_sum = max(max_sum, sum);
        }
    }

    cout << max_sum;
}