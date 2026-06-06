#include <iostream>
using namespace std;

int N;

int solve(int cnt) {

    if(cnt == 1) {
        return 1;
    }

    if(cnt == 2) {
        return 1;
    }

    return solve(cnt-1) + solve(cnt-2);

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    cout << solve(N);

    return 0;
}