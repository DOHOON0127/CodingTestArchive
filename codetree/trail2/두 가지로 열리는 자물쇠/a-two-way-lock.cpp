#include <iostream>
using namespace std;

int n, a, b, c, a1, b1, c1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    cin >> a >> b >> c;
    cin >> a1 >> b1 >> c1;

    int cnt = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)  {
            for(int k = 1; k <= n; k++) {

                if((abs(a-i) <= 2 || abs(a-i) >= n-2) 
                && (abs(b-j) <= 2 || abs(b-j) >= n-2) 
                && (abs(c-k) <= 2 || abs(c-k) >= n-2)  ) {
                    cnt++;
                }
                else if((abs(a1-i) <= 2 || abs(a1-i) >= n-2) 
                && (abs(b1-j) <= 2 || abs(b1-j) >= n-2) 
                && (abs(c1-k) <= 2 || abs(c1-k) >= n-2)) {
                    cnt++;
                }
            }   
        }
    }

    cout << cnt;

    return 0;
}