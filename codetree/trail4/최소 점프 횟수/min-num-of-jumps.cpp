#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int n;
int num[10];
int answer = INT_MAX;

// 현재 cnt위치에서 점프할 수 있는 경우
void solve(int cnt, int jumps) {

    if(cnt == n-1) {
        answer = min(answer, jumps);
        return;
    }

    for(int i = 1; i <= num[cnt]; i++) {
        if(cnt + i <= n-1) {
            solve(cnt + i, jumps + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n; // 도달해야 하는 위치

    for (int i = 0; i < n; i++) {
        cin >> num[i]; // 각각의 num 배열의 값은 최대 점프 가능 거리를 의미
    }

    solve(0, 0);

    if(answer == INT_MAX) {
        cout << -1;
    }
    else {
        cout << answer;
    }



    return 0;
}
