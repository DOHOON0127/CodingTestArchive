#include <iostream>
using namespace std;

int N; 
int dp[20];

void BST(int cnt) {
    
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int j = 3; j <= cnt; j++) {

        int temp = 0;

        for(int i = 0; i < j; i++) {
                temp += dp[i] * dp[j-1-i];
                // cout << temp << '\n';
        }

        dp[j] = temp;

    }
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    BST(N);

    cout << dp[N];

    return 0;
}