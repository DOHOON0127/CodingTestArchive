#include <iostream>
using namespace std;

int n,a,b,c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    cin >> a >> b >> c;

    // 총 3자리를 만들어야 하고 자리 비교했을때 2이내여야 함

    int cnt = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                if(abs(k-c) > 2 && abs(j-b) > 2 && abs(i-a) > 2) {
                    cnt++;
                }
            }
        }
    }

    cout << n*n*n - cnt;

    return 0;
}