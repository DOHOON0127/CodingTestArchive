#include <iostream>
#include <cstring>

using namespace std;

int n;
int memo[1004];

long long square(int cnt) {
    if(memo[cnt] != -1) {
        return memo[cnt];
    }

    if(cnt == 0) {
        memo[cnt] = 1;
    }
    else if(cnt == 1) {
        memo[cnt] = 2;
    }
    else if(cnt == 2) {
        memo[cnt] = 7;
    }
    else if(cnt == 3) {
        memo[cnt] = 22;
    }
    else{
        long long temp =  (square(cnt-1)*2 + square(cnt-2)*3) % 1000000007;
        for(int i = cnt - 3; i >= 0; i--) {
            temp = (temp + square(i) * 2) % 1000000007;
        }
        memo[cnt] = temp;
    }

    return memo[cnt];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    memset(memo, -1, sizeof(memo));

    square(n);

    cout << memo[n];

    return 0;
}
