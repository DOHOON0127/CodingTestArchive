#include <iostream>
#include <cstring>
using namespace std;

int N;
int memo[50];

int fibo(int cnt) {
    
    if(memo[cnt] != -1) {
        return memo[cnt];
    }

    if(cnt == 1 || cnt == 2) {
        memo[cnt] = 1;
    }
    else {
        memo[cnt] = fibo(cnt-1) + fibo(cnt-2);  
    }

    return memo[cnt];

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    memset(memo, -1, sizeof(memo));

    fibo(N);

    cout << memo[N];

    return 0;
}