#include <iostream>
using namespace std;

int N;
int sum;

int solve(int cnt) {

    if(cnt == 1) {
        return 1;
    }

    sum = solve(cnt -1) + cnt;

    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    cout << solve(N);
    
    return 0;
}