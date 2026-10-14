#include <iostream>
#include <string>

using namespace std;

int N;
string a;
string b;

// 7
// GHHHGHH
// HHGGGHH
// 출력
// 2

int main() {
    cin >> N;
    cin >> a;
    cin >> b;

    int cnt = 0;

    // 서로 다른 구간의 개수를 구하면 끝나는 문제
    for(int i = 0; i < N; i++) {
        if(a[i] != b[i]) {
            if(i == N-1) {
                cnt++;
                break;
            }

            if(a[i+1] == b[i+1]) {
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}
