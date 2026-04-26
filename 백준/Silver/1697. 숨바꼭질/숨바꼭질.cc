#include <bits/stdc++.h>
using namespace std;

int arr[200001];
int N, K;

int main () {
    cin >> N >> K; // 5 17

    fill(arr, arr + 200001, -1);

    arr[N] = 0;

    queue<int> Q;
    Q.push(N);

    while (!Q.empty()) {
        int a = Q.front();
        Q.pop();

        int dx[3] = {a-1, a+1, a*2};

        for (int i = 0; i < 3; i++) {
            int nx = dx[i];

            if (nx < 0 || nx > 100000) continue;
            if (arr[nx] != -1) continue;

            arr[nx] = arr[a] + 1;
            Q.push(nx);
        }
    }

    cout << arr[K];
}