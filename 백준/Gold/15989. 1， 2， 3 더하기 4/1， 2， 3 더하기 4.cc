#include <bits/stdc++.h>
using namespace std;

int dp[10004];
int T, n;

int main () {
    dp[0] = 1;

    for(int i = 1; i <= 3; i++) {
        
        for(int j = 1; j <= 10000; j++) {
            if(j - i >= 0){
                dp[j] += dp[j - i];
            }
        }

    }

    cin >> T;

    while(T--) {
        cin >> n;

        cout << dp[n] << '\n';
    }

    return 0;

}